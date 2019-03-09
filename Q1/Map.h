#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>

//================= MOSTAFA SADEGHI   9423067 =============

class Map 
{ 
	public: 
	static const int n=10;

	int matric [n][n];
	std::string route1 [n][n];
	std::string route2 [n][n];
	std::string route3 [n][n];
	std::string route4 [n][n];
	std::vector<int> route;
	std::vector<int> route_gh;
	std::vector<std::string> route_kol;

	
	// printname is not defined inside class defination 
	void showmap();
	
	int find_route1();
	int find_route2();
	int find_route3(int, int, int**);
	int find_route4(int, int, int**);
	int min(int, int, int);
	void show_route1();
	void show_route2();
	void show_route3();
	void show_route4();
	void generateMap();
}; 