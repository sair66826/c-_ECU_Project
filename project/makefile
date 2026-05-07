# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra

# Output executable name
TARGET = ecu_system

# Source files
SRCS = main.cpp ecu_communication.cpp data.cpp

# Object files (auto-generated from SRCS)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile step
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean build files
clean:
	rm -f *.o $(TARGET)

# Rebuild everything
rebuild: clean all
