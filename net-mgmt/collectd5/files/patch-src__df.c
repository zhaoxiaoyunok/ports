--- src/df.c.orig	2017-06-06 18:13:54 UTC
+++ src/df.c
@@ -28,6 +28,11 @@
 #include "utils_ignorelist.h"
 #include "utils_mount.h"
 
+#ifdef __FreeBSD__
+/* We want to use statfs on FreeBSD, for the mount flags. */
+#undef HAVE_STATVFS
+#endif
+
 #if HAVE_STATVFS
 #if HAVE_SYS_STATVFS_H
 #include <sys/statvfs.h>
@@ -48,17 +53,20 @@
 
 static const char *config_keys[] = {
     "Device",         "MountPoint",   "FSType",         "IgnoreSelected",
-    "ReportByDevice", "ReportInodes", "ValuesAbsolute", "ValuesPercentage"};
+    "ReportByDevice", "ReportInodes", "ValuesAbsolute", "ValuesPercentage",
+    "LogOnce"};
 static int config_keys_num = STATIC_ARRAY_SIZE(config_keys);
 
 static ignorelist_t *il_device = NULL;
 static ignorelist_t *il_mountpoint = NULL;
 static ignorelist_t *il_fstype = NULL;
+static ignorelist_t *il_errors = NULL;
 
 static _Bool by_device = 0;
 static _Bool report_inodes = 0;
 static _Bool values_absolute = 1;
 static _Bool values_percentage = 0;
+static _Bool log_once = 0;
 
 static int df_init(void) {
   if (il_device == NULL)
@@ -67,6 +75,8 @@ static int df_init(void) {
     il_mountpoint = ignorelist_create(1);
   if (il_fstype == NULL)
     il_fstype = ignorelist_create(1);
+  if (il_errors == NULL)
+    il_errors = ignorelist_create(0);
 
   return (0);
 }
@@ -123,6 +133,13 @@ static int df_config(const char *key, co
       values_percentage = 0;
 
     return (0);
+  } else if (strcasecmp(key, "LogOnce") == 0) {
+    if (IS_TRUE(value))
+      log_once = 1;
+    else
+      log_once = 0;
+
+    return (0);
   }
 
   return (-1);
@@ -202,13 +219,29 @@ static int df_read(void) {
       continue;
 
     if (STATANYFS(mnt_ptr->dir, &statbuf) < 0) {
-      char errbuf[1024];
-      ERROR(STATANYFS_STR "(%s) failed: %s", mnt_ptr->dir,
-            sstrerror(errno, errbuf, sizeof(errbuf)));
+      if (log_once == 0 || ignorelist_match(il_errors, mnt_ptr->dir) == 0)
+      {
+        if (log_once == 1)
+        {
+          ignorelist_add(il_errors, mnt_ptr->dir);
+        }
+        char errbuf[1024];
+        ERROR(STATANYFS_STR "(%s) failed: %s", mnt_ptr->dir,
+              sstrerror(errno, errbuf, sizeof(errbuf)));
+      }
       continue;
+    } else {
+      if (log_once == 1)
+      {
+        ignorelist_remove(il_errors, mnt_ptr->dir);
+      }
     }
 
+#ifdef __FreeBSD__
+    if ((statbuf.f_flags & MNT_IGNORE) || (statbuf.f_blocks == 0))
+#else
     if (!statbuf.f_blocks)
+#endif
       continue;
 
     if (by_device) {
@@ -295,14 +328,22 @@ static int df_read(void) {
       uint64_t inode_used;
 
       /* Sanity-check for the values in the struct */
+#ifndef __FreeBSD__ 
       if (statbuf.f_ffree < statbuf.f_favail)
         statbuf.f_ffree = statbuf.f_favail;
+#endif
       if (statbuf.f_files < statbuf.f_ffree)
         statbuf.f_files = statbuf.f_ffree;
 
+#ifdef __FreeBSD__
+      inode_free = (uint64_t)statbuf.f_ffree;
+      inode_reserved = 0;
+      inode_used = (uint64_t)(statbuf.f_files - inode_free);
+#else
       inode_free = (uint64_t)statbuf.f_favail;
       inode_reserved = (uint64_t)(statbuf.f_ffree - statbuf.f_favail);
       inode_used = (uint64_t)(statbuf.f_files - statbuf.f_ffree);
+#endif
 
       if (values_percentage) {
         if (statbuf.f_files > 0) {
