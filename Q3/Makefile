CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = q3.o
TARGET = q3


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: q3.cpp
	$(CXX) $(CXXFLAGS) q1.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)