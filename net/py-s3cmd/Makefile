# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	s3cmd
DISTVERSION=	2.0.2
CATEGORIES=	net python
MASTER_SITES=	SF/s3tools/${PORTNAME}/${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Unix-like tools to manipulate stored files from the command line

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR}

USES=		python:3
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's,share/man,man,' ${WRKSRC}/setup.py

post-patch-DOCS-on:
	${REINPLACE_CMD} -e 's,doc/packages,doc,' ${WRKSRC}/setup.py

post-patch-DOCS-off:
	${REINPLACE_CMD} -e '/(doc_path+/d' ${WRKSRC}/setup.py

.include <bsd.port.mk>
