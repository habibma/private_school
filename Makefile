# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

# Files
INCLUDE_DIRS = -I./include
SRC = main.cpp $(wildcard ./utils/*.cpp) $(wildcard ./src/*.cpp) $(wildcard ./helpers/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = program

# Rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Header dependencies
$(OBJ): include/private_teacher.hpp
src/%.o: include/Teacher.hpp

clean:
	rm -f $(OBJ) $(TARGET)
