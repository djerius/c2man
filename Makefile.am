## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS = -I m4 --install

AM_CPPFLAGS = -I$(top_builddir) -I$(top_srcdir)
AM_YFLAGS = -Wno-yacc

bin_PROGRAMS = c2man
c2man_SOURCES = \
	c2man.c semantic.c string.c symbol.c strconcat.c strappend.c \
	manpage.c enum.c nroff.c texinfo.c latex.c html.c autodoc.c
nodist_c2man_SOURCES = y.tab.c
noinst_HEADERS = \
	c2man.h enum.h manpage.h output.h semantic.h \
	strappend.h strconcat.h symbol.h ctype_ex.h
BUILT_SOURCES = y.tab.c lex.yy.c fixexamp.sed flatten.sed
CLEANFILES = y.tab.c lex.yy.c y.output fixexamp.sed flatten.sed \
	example.inc ctype_ex.inc c2man.1
nodist_man_MANS = c2man.1

egdir = $(pkgdatadir)/eg
eg_DATA = \
	eg/boxcomment.c eg/ccomment.h eg/commentaft.c eg/cppcomment.h \
	eg/dash.h eg/ellipsis.c eg/grouped.c eg/multidecl.c \
	eg/namedash.h eg/oldstyle.c eg/retdecl.c eg/returnerr.h \
	eg/returnlist.h eg/sections.c eg/simplesect.c eg/surround.c \
	eg/underscore.h eg/variable.c

EXTRA_DIST = \
	CHANGES C++autodoc FAQ FAQ.stoney README README.stoney \
	ChangeLog ChangeLog.stoney bootstrap catalog c2man.man \
	ctype_ex.h example.h fixexamp.in flatten.sed.in \
	grammar.y lex.l \
	$(eg_DATA)

y.tab.c: $(srcdir)/grammar.y lex.yy.c
	@echo "Expect 64 shift/reduce conflicts."
	$(YACC) $(AM_YFLAGS) $(YFLAGS) $(srcdir)/grammar.y

lex.yy.c: $(srcdir)/lex.l
	$(LEX) -n $(srcdir)/lex.l

fixexamp.sed: $(srcdir)/fixexamp.in
	$(SED) -e '/^#/d' $(srcdir)/fixexamp.in > $@

example.inc: c2man$(EXEEXT) $(srcdir)/example.h fixexamp.sed
	./c2man$(EXEEXT) -o- $(srcdir)/example.h | $(SED) -f fixexamp.sed > $@

ctype_ex.inc: c2man$(EXEEXT) $(srcdir)/ctype_ex.h fixexamp.sed
	./c2man$(EXEEXT) -o- -g $(srcdir)/ctype_ex.h | $(SED) -f fixexamp.sed > $@

c2man.1: $(srcdir)/c2man.man c2man$(EXEEXT) example.inc ctype_ex.inc flatten.sed
	$(SED) -f flatten.sed < $(srcdir)/c2man.man > $@

check-local: c2man$(EXEEXT)
	@echo "Running c2man over the examples..." 1>&2
	@for file in $(srcdir)/eg/*.[chly]; do ./c2man$(EXEEXT) -I. -I$(srcdir) -v -o- $$file; done
	@echo "Running c2man over its own source code..." 1>&2
	@for file in $(c2man_SOURCES); do ./c2man$(EXEEXT) -I. -I$(srcdir) -v -o- $(srcdir)/$$file; done
	@echo "Hmmm, test seemed to go OK." 1>&2
