# New ports collection makefile for:   kdelibs
# Version required:    Beta4
# Date created:        28 October 1997
# Whom:                Stefan E�er <se@freebsd.org>
#
# $Id$
#

#DISTNAME=	kdelibs-`date "+%y%m%d"`
PKGNAME=	kdelibs-`date "+%y%m%d"`
CATEGORIES=	x11 kde

MAINTAINER=	garbanzo@hooked.net

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt \
		autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake

LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11/qt \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.[6-8]\\.:${PORTSDIR}/graphics/jpeg

USE_GMAKE=	yes
NO_EXTRACT=	yes
NO_WRKDIR=	yes
WRKSRC=		../
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--x-inc=$(X11BASE)/include" \
		"--x-lib=$(X11BASE)/lib"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)"

# Since there's nothing to fetch, we might as well use a dummy target
do-fetch:
		@true

# This should clean the KDE target pretty well
pre-clean:
		cd $(WRKSRC);$(GMAKE) clean

# We need to go through Makefile.cvs before anything else.
pre-configure:
		cd $(WRKSRC);rm -f config.cache;$(GMAKE) -f Makefile.cvs

.include <bsd.port.mk>