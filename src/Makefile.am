AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

SUBDIRS = validation nested_json help_and_version

bin_PROGRAMS = json-where

json_where_SOURCES = main.cpp
json_where_LDADD = libvalidation.la libnested_json.la libhelp_and_version.la
