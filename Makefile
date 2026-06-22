# Compiler and flags

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

# Colors

GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RESET = \033[0m

# Files

INCLUDE_DIRS = -I./include
SRC = main.cpp $(wildcard ./utils/*.cpp) $(wildcard ./src/*.cpp) $(wildcard ./src/ui/*.cpp) $(wildcard ./helpers/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = program

# Progress tracking
TOTAL := $(words $(OBJ))
PROGRESS_FILE := .progress
BAR_WIDTH := 30
-include $(OBJ:.o=.d)

# Rules

all: prebuild $(TARGET)

prebuild:
	@rm -f $(PROGRESS_FILE)

$(TARGET): $(OBJ)
	@printf "\n$(BLUE)Linking $(TARGET)...$(RESET)\n"
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJ)
	@printf "$(GREEN)✓ Build complete: $(TARGET)$(RESET)\n"

%.o: %.cpp
	@printf "%s\n" >> $(PROGRESS_FILE); count=$$(wc -l < $(PROGRESS_FILE) | tr -d ' '); percent=$$((count * 100 / $(TOTAL))); bar=$$(awk -v p=$$percent -v w=$(BAR_WIDTH) 'BEGIN{f=int(p*w/100); for(i=0;i<f;i++)printf("█"); for(i=f;i<w;i++)printf(" "); }'); printf "\r\033[K$(YELLOW)Compiling %-40s$(RESET) [%s] %d%%" "$<" "$$bar" "$$percent"; tmp=$$(mktemp .compile.XXXXXX); $(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -MMD -MP -c $< -o $@ >$$tmp 2>&1; ret=$$?; if [ -s $$tmp ]; then printf "\n"; cat $$tmp; fi; rm -f $$tmp; if [ $$ret -ne 0 ]; then exit $$ret; fi

# Header dependencies

$(OBJ): include/private_school.hpp
src/%.o: include/Teacher.hpp
src/ui/%.o: include/ui/buildSchool.hpp
utils/%.o: include/utils/utils.hpp
helpers/%.o: include/helpers/helpers.hpp

clean:
	@rm -f $(OBJ) $(OBJ:.o=.d) $(TARGET)
	@printf "$(GREEN)✓ Clean complete$(RESET)\n"

re: clean all

.PHONY: all clean re
