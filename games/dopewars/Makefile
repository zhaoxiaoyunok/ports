# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dopewars
PORTVERSION=	1.5.12
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UNIX rewrite of a game originally based on "Drug Wars"

DEPRECATED=	Uses obsolete glib12
EXPIRATION_DATE=	2018-12-20

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake gettext
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12

CONFIGURE_ARGS=	--enable-networking --disable-plugins --localstatedir=${DATADIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	ABOUT-NLS AUTHORS COPYING ChangeLog INSTALL LICENCE NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's!/pixmaps!/dopewars/pixmaps!' \
		-e '/chmod 2755/d' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's!^CFLAGS =!CFLAGS = \@GLIB_CFLAGS\@!' \
		${WRKSRC}/src/gui_client/Makefile.in \
		${WRKSRC}/src/curses_client/Makefile.in
	@${REINPLACE_CMD} -e 's!install-recursive!!g' ${WRKSRC}/doc/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/dopewars.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/help
	${INSTALL_DATA} ${WRKSRC}/doc/*html ${WRKSRC}/doc/example* \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/help/*html ${STAGEDIR}${DOCSDIR}/help
	${INSTALL_DATA} ${PORTDOCS:S.^.${WRKSRC}/.} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
