
GMOFILES = de.gmo fr.gmo sv.gmo cs.gmo es.gmo ru.gmo \
	hu.gmo da.gmo it.gmo nl.gmo pt.gmo no.gmo pl.gmo \
	el.gmo fi.gmo hr.gmo ro.gmo zh_TW.Big5.gmo zh_CN.GB2312.gmo \
	sk.gmo ca.gmo sl.gmo en_UK.gmo mk.gmo pt_BR.gmo eo.gmo

POFILES = $(GMOFILES:.gmo=.po) 

CHARSETFILES = de.charset cs.charset pl.charset ru.charset fr.charset \
               hu.charset ro.charset fi.charset da.charset pt.charset \
               sk.charset es.charset sv.charset eo.charset

localedir = $(kde_locale)

MAINTAINERCLEANFILES = $(GMOFILES)

EXTRA_DIST = kde.pot $(CHARSETFILES) $(POFILES) $(GMOFILES) texts.cpp
# install this to make excluding of this messages possible
include_HEADERS = kde.pot

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
	lang=`echo $$cat | sed 's/\.gmo//'`; \
	name=kde.mo \
	dir=$$destdir/$$lang/LC_MESSAGES; \
	$(mkinstalldirs) $$dir; \
	$(INSTALL_DATA) $$cat $$dir/$$name; \
	  echo "installing $$cat as $$dir/$$name"; \
	done;\
	charsets='$(CHARSETFILES)'; \
	for chset in $$charsets; do \
	destdir=$(localedir); \
	lang=`echo $$chset | sed 's/\.charset//'`; \
	name=charset ; \
	dir=$$destdir/$$lang; \
	$(mkinstalldirs) $$dir; \
	$(INSTALL_DATA) $$chset $$dir/$$name; \
	  echo "installing $$chset as $$dir/$$name"; \
	done  

install-no:

uninstall-local:
	@catalogs='$(GMOFILES)'; \
	for cat in $$catalogs; do \
	destdir=$(localedir); \
	lang=`echo $$cat | sed 's/\.gmo//'`; \
	name=kde.mo; \
	dir=$$destdir/$$lang/LC_MESSAGES; \
	rm -f $$cat $$dir/$$name; \
	echo "removing $$dir/$$name" ; \
	done ;\
	charsets='$(CHARSETFILES)'; \
	for chset in $$charsets; do \
	  destdir=$(localedir); \
	  lang=`echo $$chset | sed 's/\.charset//'`; \
	  name=charset; \
	  dir=$$destdir/$$lang; \
	  rm -f $$dir/$$name; \
	  echo "removing $$dir/$$name" ; \
	done

merge:
	@catalogs='$(POFILES)'; \
	for cat in $$catalogs; do \
	echo $$cat $$name; \
	msgmerge $$cat kde.pot > $$cat.new ; \
	if diff $$cat $$cat.new; then \
		rm $$cat.new;  \
	else  \
		mv $$cat.new $$cat ; \
	fi; \
	done

