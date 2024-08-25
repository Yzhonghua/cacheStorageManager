# Makefile for Cache Storage Manager

# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Include directories
INCLUDES = -Iinclude

# Target executable
TARGET = cacheStorageManager

# Source files
SRCS = main.cpp 

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean the build directory
clean:
	rm -f $(TARGET) $(OBJS)
