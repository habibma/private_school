# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Files
SRC = main.cpp ./utils/*.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = program

# Rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Explicit header dependencies
main.o: main.cpp private_teacher.hpp
utils.o: ./utils/*.cpp private_teacher.hpp

clean:
	rm -f $(OBJ) $(TARGET)
