# $FreeBSD$

PORTNAME=	widgets
CATEGORIES=	x11-toolkits devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtWidgets module

CONFIGURE_ARGS=	--enable QtWidgets
PYQT_DIST=	yes

USES=		python pyqt:5 qt:5
USE_GL=		gl
USE_PYQT=	sip_build core_run gui_run
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core gui widgets qmake_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtGui API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5
DEBUG_CONFIGURE_ON=	--debug --trace

.include <bsd.port.mk>
