CXXFLAGS := -std=c++11 -O2 -Wall
TARGET := main
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %cpp, %o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean

clean:
	-$(RM) $(TARGET) $(OBJS)