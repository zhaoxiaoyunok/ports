# $FreeBSD$

PORTNAME=	wsdd
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	awalker@ixsystems.com
COMMENT=	Python WS-Discovery implementation

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT= 	freenas
GH_PROJECT=	wsdd
GH_TAGNAME=	fc31fc6279ce4a1c4d4bac68d9e4b96e007eb1f3

post-install:
		${LN} -sf ${PYTHON_SITELIBDIR}/wsdd/wsdd.py ${LOCALBASE}/bin/wsdd.py
		${CHMOD} +x  ${STAGEDIR}${PYTHON_SITELIBDIR}/wsdd/wsdd.py

.include <bsd.port.mk>
