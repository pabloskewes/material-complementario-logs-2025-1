CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Directorios
SRC_DIR = src
INCLUDE_DIR = include

# Targets principales
all: create_tree search_value

create_tree: $(SRC_DIR)/create_tree.cpp $(SRC_DIR)/tree.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $^ -o $@

search_value: $(SRC_DIR)/search_value.cpp $(SRC_DIR)/tree.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $^ -o $@

clean:
	rm -f create_tree search_value tree.bin

.PHONY: all clean
