# Created by: Arjan van Leeuwen <avleeuwen@piwebs.com>
# $FreeBSD$

PORTNAME=	digikam
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	17
PORTEPOCH=	2
CATEGORIES=	graphics kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 digital photo management application

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

.include "${.CURDIR}/Makefile.common"

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		liblcms.so:graphics/lcms \
		libpng.so:graphics/png \
		libjasper.so:graphics/jasper \
		liblensfun.so:graphics/lensfun \
		liblqr-1.so:graphics/liblqr-1 \
		libopencv_video.so:graphics/opencv \
		libpgf.so:graphics/libpgf \
		libkgeomap.so:astro/libkgeomap-kde4 \
		libboost_graph.so:devel/boost-libs

USES+=		eigen:3 pkgconfig qt:4 shebangfix
USE_KDE+=	libkdcraw libkexiv2 libkipi runtime_run
USE_QT+=		sql-sqlite3_run
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DWITH_Sqlite2:BOOL=OFF -DENABLE_OPENCV3:BOOL=true

WRKSRC=		${WRKDIR}/${DISTNAME}/core
SHEBANG_FILES=	data/scripts/digitaglinktree/digitaglinktree

OPTIONS_DEFINE=		DOCS NLS GPHOTO2 PIMLIBS MYSQL
OPTIONS_DEFAULT=	GPHOTO2 PIMLIBS
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=		yes # MYSQL

DOCS_RUN_DEPENDS=	digikam-doc>=${DIGIKAM_VER}:graphics/digikam-kde4-doc

NLS_RUN_DEPENDS=	digikam-l10n>=${DIGIKAM_VER}:graphics/digikam-kde4-l10n

GPHOTO2_DESC=		Gphoto2 camera support
GPHOTO2_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO2_CMAKE_ON=	-DWITH_Gphoto2:BOOL=ON
GPHOTO2_CMAKE_OFF=	-DWITH_Gphoto2:BOOL=OFF

PIMLIBS_DESC=		Address book support
PIMLIBS_USE=		KDE=pimlibs baloo
PIMLIBS_CMAKE_ON=	-DENABLE_KDEPIMLIBSSUPPORT:BOOL=ON
PIMLIBS_CMAKE_OFF=	-DENABLE_KDEPIMLIBSSUPPORT:BOOL=OFF

MYSQL_USES=	qt:4
MYSQL_USE=		MYSQL=server QT=sql-mysql_run
MYSQL_BUILD_DEPENDS=	${LOCALBASE}/lib/mysql/libmysqld.a:${_MYSQL_SERVER}
MYSQL_CMAKE_ON= 	-DMYSQLD_PATH:PATH=${LOCALBASE}/libexec \
			-DMYSQL_TOOLS_PATH:PATH=${LOCALBASE}/bin \
			-DENABLE_INTERNALMYSQL:BOOL=ON \
			-DENABLE_MYSQLSUPPORT:BOOL=ON
MYSQL_CMAKE_OFF=	-DENABLE_INTERNALMYSQL:BOOL=OFF \
			-DENABLE_MYSQLSUPPORT:BOOL=OFF

.include <bsd.port.mk>
