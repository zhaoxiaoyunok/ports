# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rbvmomi
PORTVERSION=	2.0.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to the VMware vSphere API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=3.0:devel/rubygem-builder \
		rubygem-json>=1.8:devel/rubygem-json \
		rubygem-nokogiri>=1.5:textproc/rubygem-nokogiri \
		rubygem-optimist>=3.0:devel/rubygem-optimist

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/rbvmomish

SHEBANG_FILES=	examples/run.sh

.include <bsd.port.mk>
