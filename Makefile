.PHONY: build
build:
	g++ -iquote include/ src/main.cpp -o json-where

.PHONY: run
run:
	./json-where $()
