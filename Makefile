.PHONY: build
build:
	g++ -iquote include/ src/main.cpp -o json-where
