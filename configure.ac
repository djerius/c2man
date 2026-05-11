AC_INIT([c2man],[2.1.0], [c2man-maintainers@example.invalid])

AC_CONFIG_SRCDIR([c2man.c])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign no-define subdir-objects])
AC_USE_SYSTEM_EXTENSIONS

AC_PROG_CC
AC_PROG_CPP
AC_PROG_YACC
AC_PROG_LEX([noyywrap])
AC_PROG_SED
AC_PROG_INSTALL

MAJOR_VERSION=`echo "$PACKAGE_VERSION" | sed 's/\([[0-9]]*\)\.\([[0-9]]*\)\.\([[0-9]]*\)/\1/'`
MINOR_VERSION=`echo "$PACKAGE_VERSION" | sed 's/\([[0-9]]*\)\.\([[0-9]]*\)\.\([[0-9]]*\)/\2/'`
PATCHLEVEL=`echo "$PACKAGE_VERSION" | sed 's/\([[0-9]]*\)\.\([[0-9]]*\)\.\([[0-9]]*\)/\3/'`
AC_DEFINE_UNQUOTED([MAJOR_VERSION], ["$MAJOR_VERSION"], [Major version number])
AC_DEFINE_UNQUOTED([MINOR_VERSION], ["$MINOR_VERSION"], [Minor version number])
AC_DEFINE_UNQUOTED([VERSION_MACRO], ["${MAJOR_VERSION}_${MINOR_VERSION}"], [Minor version number])
AC_DEFINE_UNQUOTED([PATCHLEVEL], [$PATCHLEVEL], [Patch level number])

AC_CHECK_HEADERS([fcntl.h sys/file.h sys/types.h sys/time.h unistd.h])
AC_CHECK_FUNCS([access link symlink])

AC_ARG_WITH([cpp-comment-flag],
    [AS_HELP_STRING([--with-cpp-comment-flag=FLAG],
        [C preprocessor flag used to preserve comments @<:@default=-C@:>@])],
    [AS_IF([test "x$withval" = xno],
        [CPP_COMMENT_FLAG=],
        [CPP_COMMENT_FLAG=$withval])],
    [CPP_COMMENT_FLAG=-C])

CPP_FILE_COM="$CPP $CPP_COMMENT_FLAG"
AC_DEFINE_UNQUOTED([CPP_FILE_COM], ["$CPP_FILE_COM"],
    [Command to run the C preprocessor preserving comments.])

AC_CONFIG_FILES([Makefile flatten.sed])
AC_OUTPUT
