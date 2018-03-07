# Makefile for Library Management System
CXXFLAGS += -std=c++14 
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: main
rebuild: clean main

debug: CXXFLAGS += -g
debug: rebuild

main: main.o library.o publication.o 
	$(CXX) $(CXXFLAGS) -o lms main.o library.o publication.o $(GTKFLAGS)

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)

test_library: test_library.o library.o publication.o
	$(CXX) $(CXXFLAGS) -o test_library test_library.o library.o publication.o $(GTKFLAGS)

test_library.o: test_library.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_library.cpp $(GTKFLAGS)

library.o: library.cpp *.h
	$(CXX) $(CXXFLAGS) -c library.cpp $(GTKFLAGS)

test_publication: test_publication.o publication.o 
	$(CXX) $(CXXFLAGS) -o test_publication test_publication.o publication.o $(GTKFLAGS)

test_publication.o: test_publication.cpp *.h
	$(CXX) $(CXXFLAGS) -c -w test_publication.cpp $(GTKFLAGS)

publication.o: publication.cpp *.h
	$(CXX) $(CXXFLAGS) -c publication.cpp $(GTKFLAGS)

clean:
	-rm -f *.o lms test_publication test_library *.gch *~ gui cli test
