all: splash2

CXX?=g++
CXXFLAGS?=--std=c++23
#-ggdb

OBJS:= \
	objs/main.o

SHARED_OBJS:=objs/common.o objs/log.o
LIBS:=

INCLUDES:=-I./include -I.

objs/main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

splash2: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) $(LIBS) -o $@;

clean:
	rm -f objs/** splash2
