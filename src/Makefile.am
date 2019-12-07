AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

SUBDIRS = validation nested_json help_and_version

bin_PROGRAMS = helloWorld

helloWorld_SOURCES = main.cpp
helloWorld_LDADD = validation.la nested_json.la help_and_version.la
