# $FreeBSD$

PORTNAME=	cbindgen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.7
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	rust-

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Generate C bindings from Rust code

LICENSE=	MPL20

RUN_DEPENDS=	cargo:lang/rust

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	eqrion
PLIST_FILES=	bin/cbindgen

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.10 \
		bitflags-1.0.3 \
		cfg-if-0.1.3 \
		clap-2.31.2 \
		cloudabi-0.0.3 \
		dtoa-0.4.2 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		itoa-0.4.1 \
		libc-0.2.41 \
		log-0.4.1 \
		proc-macro2-0.3.8 \
		proc-macro2-0.4.4 \
		quote-0.5.2 \
		quote-0.6.3 \
		rand-0.5.5 \
		rand_core-0.2.1 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		remove_dir_all-0.5.1 \
		serde-1.0.64 \
		serde_derive-1.0.58 \
		serde_json-1.0.19 \
		strsim-0.7.0 \
		syn-0.13.11 \
		syn-0.14.1 \
		tempfile-3.0.3 \
		termion-1.5.1 \
		textwrap-0.9.0 \
		toml-0.4.6 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		vec_map-0.8.1 \
		winapi-0.3.4 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

.include <bsd.port.mk>
