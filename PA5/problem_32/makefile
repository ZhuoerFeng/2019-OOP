CXXFLAGS := -std=c++14 -Wall
TARGET := main
SRCS := main.cpp 
OBJS := $(patsubst %cpp, %o, $(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	-$(RM) $(TARGET) $(OBJS)