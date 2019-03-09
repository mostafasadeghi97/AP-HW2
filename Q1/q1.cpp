#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>
#include"Map.h"

//================= MOSTAFA SADEGHI   9423067 ================

int main() { 
	
	Map obj1;
	//generate map with random numbers between 0,100
	obj1.generateMap(); 
	//show generated map
	obj1.showmap();
	//find route with first way
	std::cout << "firsr way Distance  : "<< obj1.find_route1()<< std::endl;
	//show route of first way
	obj1.show_route1();
	//find route with second way
	std::cout << "second way distance : "<< obj1.find_route2()<< std::endl;
	//show route of second way
	obj1.show_route2();
	//trace back for finding the route with third way
	int **T;
	T = new int*[obj1.n];
	for(int i = 0; i < obj1.n; i++){
    	T[i] = new int[obj1.n];
	}
	// find route with third way
	std::cout << "third way distance : " << obj1.find_route3(0, 0, T)<< std::endl;
	int i{},j{};
	while(i <obj1.n && j <obj1.n){
		if (T[i][j] == 1)
		{	
			i+=1;
			j+=1;
		}
		else if (T[i][j] == 2)
		{
			i+=1;
		}
		else if (T[i][j] == 3)
		{
			j+=1;
		}
		else{
			obj1.route3[i][j] = "*";
			break;
		}
		obj1.route3[i][j] = "*";

	}
	//show route of third way
	obj1.show_route3();
	//trace back for finding the route with fourth way
	int **T2;
	T2 = new int*[obj1.n];
	for(int i = 0; i < obj1.n; i++){
    	T2[i] = new int[obj1.n];
	}
	// find route with fourth way
	std::cout << "fourth way distance : " << obj1.find_route4(0, 0, T2)<< std::endl;
	i = 0,j=0;
	while(i <obj1.n && j <obj1.n){
		
		if (T2[i][j] == 2)
		{
			i+=1;
		}
		else if (T2[i][j] == 3)
		{
			j+=1;
		}
		else{
			obj1.route4[i][j] = "*";
			break;
		}
		obj1.route4[i][j] = "*";
	}
	//show route of fourth way
	obj1.show_route4();
	
	return 0; 
} 
