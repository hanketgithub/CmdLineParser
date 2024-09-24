TARGET = CmdLineParser
LIBS = libCmdLineParser.a
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Source files
LIB_SOURCES = CmdLineParser.cpp
LIB_OBJECTS = $(LIB_SOURCES:.cpp=.o)
MAIN_SOURCES = main.cpp

all: $(TARGET)

# Compile the main program and link with the static library
$(TARGET): $(MAIN_SOURCES) $(LIBS)
	$(CXX) $(CXXFLAGS) $(MAIN_SOURCES) $(LIBS) -o $(TARGET)

$(LIBS): $(LIB_OBJECTS)
	$(AR) rcs $@ $^

install:
	cp $(TARGET) /usr/local/bin

clean:
	$(RM) $(TARGET) $(LIB_OBJECTS) $(LIBS)
