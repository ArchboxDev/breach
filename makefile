CXX = g++
CXXFLAGS = -Wall -g -lsfml-graphics -lsfml-window -lsfml-system
SOURCEFILES = source.cpp

all: source.o

source.o: 
		  $(CXX) $(CXXFLAGS) $(SOURCEFILES)
		  $(MAKE) run

run:
	 ./a.out
	 $(MAKE) clean

clean:
	   rm a.out