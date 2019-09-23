.PHONY: build
build:
	mkdir -p bin
	g++ -iquote include/ src/main.cpp -o bin/json-where
