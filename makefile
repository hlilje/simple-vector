CXX = g++
CFLAGS = -g -Wall -std=c++0x
LIBS = ../cxxtest
TARGET = vector

.PHONY: default all clean test

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@ -I$(LIBS)

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -Wall -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
	-rm -f testrunner.cpp
	-rm -f *.out

test_init:
	python2 $(LIBS)/cxxtestgen.py --error-printer \
	-o testrunner.cpp test_vec.cpp

test: test_init vector.o
	$(CXX) $(CFLAGS) -o simple_test.out -I$(LIBS) \
	testrunner.cpp vector.o
