all: world

CXX?=g++
CXXFLAGS?=--std=c++23 -Wall
INCLUDES:=-I./include -I.

OBJS:= \
	objs/app.o objs/cmdline.o \
	objs/main.o

include common/Makefile.inc
include logger/Makefile.inc

world: splash2

objs/app.o: src/app.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

objs/cmdline.o: src/cmdline.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

objs/main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

splash2: $(OBJS) $(COMMON_OBJS) $(LOGGER_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@;

clean:
	rm -f objs/** splash2
