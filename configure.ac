#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([json-where], [0.1.0], [mail+bugs@siddharthkannan.in])
AM_INIT_AUTOMAKE

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
LT_INIT
AC_ENABLE_SHARED
AC_DISABLE_STATIC
AC_PROG_LIBTOOL(libtool)

# Checks for header files.
AC_CHECK_HEADERS([stdint.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_STRTOD
AC_CHECK_FUNCS([strtol])

# AC_CONFIG_FILES([tmp/testing/minijson_reader/Makefile])
# AC_CONFIG_FILES([Makefile src/Makefile src/validation/Makefile
                 # src/help_and_version/Makefile src/nested_json/Makefile
                 # src/nested_json/minijson/Makefile])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
