--- source3/smbd/reply.c.orig	2018-10-12 17:56:03.495873000 -0400
+++ source3/smbd/reply.c	2018-10-12 17:56:48.854154000 -0400
@@ -6643,10 +6643,17 @@ NTSTATUS rename_internals_fsp(connection
 		return status;
 	}
 
+/*
+        FIXME: OS-X clients will set a RH lease on AFP_Resource streams which results
+        in a share-mode lock being set on a file. Which causes the following check to
+        prevent users from renaming the file until the OS-X client with the lease disconnects.
+        This is incorrect behavior per MS docs.
+ */
+/*
 	if (file_has_open_streams(fsp)) {
 		return NT_STATUS_ACCESS_DENIED;
 	}
-
+ */
 	/* Make a copy of the dst smb_fname structs */
 
 	smb_fname_dst = cp_smb_filename(ctx, smb_fname_dst_in);
