# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freerdp
PORTVERSION=	1.2.0
PORTREVISION=	15
CATEGORIES=	net comms ipv6
PKGNAMESUFFIX=	1

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Free implementation of Remote Desktop Protocol

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to build: ninja: error: build.ninja:315: bad $-escape (literal $ must be written as $$)

USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	${GH_ACCOUNT}
GH_TAGNAME=	f5ff6e1

USES=		alias cmake:outsource compiler:c++11-lib cpe gettext localbase pathfix pkgconfig ssl
USE_LDCONFIG=	yes
CPE_VENDOR=	freerdp_project

CMAKE_ARGS+=	-DWITH_LIBSYSTEMD=OFF -DWITH_WAYLAND=OFF -DWITH_GSTREAMER_0_10=OFF ${CMAKE_ARGS_${ARCH}}

CMAKE_ARGS_aarch64=	-DWITH_NEON=ON
CFLAGS_aarch64=		-D__ARM_NEON__=__ARM_NEON # clang

OPTIONS_DEFINE=		ALSA CUPS FFMPEG GSTREAMER PULSEAUDIO SSE X11
OPTIONS_DEFAULT=	CUPS GSTREAMER X11
OPTIONS_SUB=		yes

OPTIONS_DEFINE_armv6=	NEON
OPTIONS_DEFINE_armv7=	NEON
OPTIONS_EXCLUDE_armv6=	SSE
OPTIONS_EXCLUDE_armv7=	SSE

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	WITH_ALSA

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CMAKE_BOOL=	WITH_CUPS

FFMPEG_BROKEN=		fails to build with ffmpeg 4.0
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libavutil.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	WITH_FFMPEG

GSTREAMER_CMAKE_BOOL=	WITH_GSTREAMER_1_0
GSTREAMER_USE=		gnome=glib20 gstreamer1=yes xorg=x11,xorgproto,xext,xrandr
GSTREAMER_LIB_DEPENDS=	libgstbase-1.0.so:multimedia/gstreamer1

NEON_DESC=		Enable	Media Processing Engine instructions
NEON_CMAKE_BOOL=	WITH_NEON
.if ! ${CFLAGS:M-march*}
NEON_CFLAGS=		-march=armv7-a
.endif

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WITH_PULSE

SSE_CMAKE_BOOL=		WITH_SSE2

X11_DESC=		Build FreeRDP X11 client
X11_BUILD_DEPENDS=	xmlto:textproc/xmlto
X11_CMAKE_BOOL=		WITH_X11
X11_CMAKE_OFF=		-DWITH_XKBFILE=OFF
X11_USE=		xorg=x11,xkbfile,xcursor,xorgproto,xv,xinerama,xext,xrandr,xi,xfixes,xrender

post-patch:
	@${FIND} ${WRKSRC} -name 'CMakeLists.txt' | ${XARGS} \
		${REINPLACE_CMD} \
				-e 's|list(APPEND $${MODULE_PREFIX}_LIBS freerdp)|list(APPEND $${MODULE_PREFIX}_LIBS freerdp1)|' \
				-e 's|list(APPEND $${MODULE_PREFIX}_LIBS winpr)|list(APPEND $${MODULE_PREFIX}_LIBS winpr1)|'
	@${FIND} ${WRKSRC} -name 'CMakeLists.txt' | ${XARGS} \
		${REINPLACE_CMD} -E \
				-e 's|freerdp winpr|freerdp1 winpr1|' \
				-e 's|winpr freerdp|winpr1 freerdp1|' \
				-e 's|-lwinpr|-lwinpr1|' \
				-e 's|-lfreerdp|-lfreerdp1|' \
				-e 's|^([[:blank:]]*)target_link_libraries\((.+) freerdp\)([[:blank:]]*)$$|\1target_link_libraries(\2 freerdp1)\3|' \
				-e 's|^([[:blank:]]*)target_link_libraries\((.+) winpr\)([[:blank:]]*)$$|\1target_link_libraries(\2 winpr1)\3|' \
				-e 's|^([[:blank:]]*)set\((.+) freerdp (.+) winpr\)([[:blank:]]*)$$|\1set(\2 freerdp1 \3 winpr1)\4|' \
				-e 's|^([[:blank:]]*)set\((.+) winpr\)([[:blank:]]*)$$|\1set(\2 winpr1)\3|'
	@${REINPLACE_CMD} -e '/CMAKE_INSTALL_RPATH /d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' \
		${WRKSRC}/client/X11/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/NetBSD__)/NetBSD__) || defined(__FreeBSD__)/' \
		${WRKSRC}/winpr/libwinpr/utils/trio/triodef.h
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/channels/drive/client/statvfs.c
	@${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/cmake|$${CMAKE_INSTALL_PREFIX}/share/cmake/Modules|' \
		${WRKSRC}/winpr/CMakeLists.txt \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
