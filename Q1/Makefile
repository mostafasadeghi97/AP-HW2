CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = q1.o Map.o
TARGET = q1


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: q1.cpp
	$(CXX) $(CXXFLAGS) q3.cpp
Map.o: Map.cpp Map.h
	$(CXX) $(CXXFLAGS) Map.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)