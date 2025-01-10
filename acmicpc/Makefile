# variable define
CXX = clang++
CXXFLAGS = -g -Wall
DEFAULT_SRC = example.cpp
TARGET = example

# build rule
all: $(TARGET)

$(TARGET): $(DEFAULT_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# run rule
run:
	$(CXX) $(CXXFLAGS) -o temp_target $(FILE)
	./temp_target
	rm -f temp_target

# debug rule
debug:
	$(CXX) $(CXXFLAGS) -o temp_target $(FILE)
	gdb ./temp_target

# clean rule
clean:
	rm -f $(TARGET) temp_target
