.PHONY: build
build:
	g++ -iquote src src/main.cpp -o json-where

.PHONY: run
run:
	./json-where $()
