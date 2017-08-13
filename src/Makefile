# Makefile for building the uart plotting service
#
CXXFLAGS = -std=c++14 -I../submodules/crow/include
LFLAGS = -lpthread -lboost_system

OBJS = main.o server.o

all: $(OBJS)
	$(CXX) $(LFLAGS) $(CXXFLAGS) $(OBJS) -o plotme

clean:
	rm -rf *.o plotme
