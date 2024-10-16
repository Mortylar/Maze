CC=g++
SFML_FLAGS=$(shell pkg-config --libs --cflags sfml-graphics)

a:
	echo $(SFML_FLAGS)
	g++ main.cc $(SFML_FLAGS)
	./a.out	
