.PHONY: build
build:
	mkdir -p bin
	g++ -iquote include/ src/main.cpp -o bin/json-where

build-clang:
	mkdir -p bin
	clang++ -std=c++11 -stdlib=libc++ -iquote include/ src/main.cpp -o bin/json-where
