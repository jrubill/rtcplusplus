# C++ Makefile

CXX = g++
CXXFLAGS = -g -Wall -std=c++11 

LIB = -lglut -lGL -lGLU 
INCLUDE = -I include -lm

SRC = $(wildcard src/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRC))

TARGET = prog


%.o: %.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIB)

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

run:
	./$(TARGET)
