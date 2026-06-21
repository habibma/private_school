# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

# Files
INCLUDE_DIRS = -I./include
SRC = main.cpp $(wildcard ./utils/*.cpp) $(wildcard ./src/*.cpp) $(wildcard ./src/ui/*.cpp) $(wildcard ./helpers/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = program
-include $(OBJ:.o=.d)

# Rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -MMD -MP -c $< -o $@

# Header dependencies
$(OBJ): include/private_school.hpp
src/%.o: include/Teacher.hpp
src/ui/%.o: include/ui/buildSchool.hpp
utils/%.o: include/utils/utils.hpp
helpers/%.o: include/helpers/helpers.hpp

clean:
	rm -f $(OBJ) $(OBJ:.o=.d) $(TARGET)

re: clean all

.PHONY: all clean re