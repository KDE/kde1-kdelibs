
# This has to be set. The rest should be reusable
DE_POFILES = de_kde.po 
DE_GMFILES = de_kde.gmo

FR_POFILES = fr_kde.po
FR_GMFILES = fr_kde.gmo

SV_POFILES = sv_kde.po
SV_GMFILES = sv_kde.gmo

CS_POFILES = cs_kde.po
CS_GMFILES = cs_kde.gmo

ES_POFILES = es_kde.po
ES_GMFILES = es_kde.gmo

RU_POFILES = ru_kde.po
RU_GMFILES = ru_kde.gmo

HU_POFILES = hu_kde.po
HU_GMFILES = hu_kde.gmo

NL_POFILES = nl_kde.po
NL_GMFILES = nl_kde.gmo

DA_POFILES = da_kde.po
DA_GMFILES = da_kde.gmo

IT_POFILES = it_kde.po
IT_GMFILES = it_kde.gmo

POFILES = $(DE_POFILES) $(FR_POFILES) $(SV_POFILES) $(CS_POFILES) $(ES_POFILES) $(RU_POFILES) $(HU_POFILES) $(NL_POFILES) $(DA_POFILES) $(IT_POFILES)
GMOFILES= $(DE_GMFILES) $(FR_GMFILES) $(SV_GMFILES) $(CS_GMFILES) $(ES_GMFILES) $(RU_GMFILES) $(HU_GMFILES) $(NL_GMFILES) $(DA_GMFILES) $(IT_GMFILES)

localedir = $(prefix)/share/locale

MAINTAINERCLEANFILES = $(GMOFILES)

GMSGFMT = @GMSGFMT@
MSGFMT = @MSGFMT@
XGETTEXT = @XGETTEXT@
DISTFILES = Makefile.in $(POFILES) $(GMOFILES)


all: all-@USE_NLS@
install-data-local: install-@USE_NLS@

SUFFIXES = .po .gmo

.po.mo:
	$(MSGFMT) -o $@ $<

.po.gmo:
	file=$(srcdir)/`echo $* | sed 's,.*/,,'`.gmo \
	&& rm -f $$file && $(GMSGFMT) -o $$file $< 

all-yes: $(GMOFILES)
all-no:

install-yes: all
	@catalogs='$(GMOFILES)'; \
	for cat in $$catalogs; do \
	destdir=$(localedir); \
	lang=`echo $$cat | sed 's/_.*$$//'`; \
	name=`echo $$cat | sed -e 's/^.._//' | sed -e 's/\.gmo/\.mo/'` \
	dir=$$destdir/$$lang/LC_MESSAGES; \
	$(mkinstalldirs) $$dir; \
	$(INSTALL_DATA) $$cat $$dir/$$name; \
	  echo "installing $$cat as $$dir/$$name"; \
	done

install-no:

uninstall-local:
	@catalogs='$(GMOFILES)'; \
	for cat in $$catalogs; do \
	destdir=$(localedir); \
	lang=`echo $$cat | sed 's/_.*$$//'`; \
	name=`echo $$cat | sed -e 's/^.._//' | sed -e 's/\.gmo/\.mo/'` \
	dir=$$destdir/$$lang/LC_MESSAGES; \
	rm -f $$cat $$dir/$$name; \
	echo "removing $$dir/$$name" ; \
	done

merge:
	@catalogs='$(POFILES)'; \
	for cat in $$catalogs; do \
	name=`echo $$cat | sed -e 's/^.._//' `; \
	echo $$cat $$name; \
	msgmerge $$cat $$name > $$cat.new ; \
	if diff $$cat $$cat.new; then \
		rm $$cat.new;  \
	else  \
		mv $$cat.new $$cat ; \
	fi; \
	done

