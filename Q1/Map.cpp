#include"Map.h"
#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>

//================= MOSTAFA SADEGHI   9423067 =============


//generate map with random numbers between 0,100
void Map::generateMap()
{
	std::mt19937 rng;
    rng.seed(std::random_device()());
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			
			std::uniform_int_distribution<std::mt19937::result_type> dist6(0,100);
			matric [i][j] = dist6(rng);
		}
	}	
}



//show n*n map
void Map::showmap() 
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matric[i][j] <10)
				std::cout << " " << matric[i][j ] << "  ";
			else
				std::cout << matric[i][j] << "  ";
		}
		std::cout << std::endl;
	}
} 

//find route with third way
int Map::find_route3(int i, int j, int** T)
{	
	int sum1{},sum2{},sum3{},minn{};
   if (i > n-1 || j > n-1) 
      return 10000000; 
   else if (i == n-1 && j == n-1) 
      return 0; 
   else{
   	  
   	  sum1 = std::abs(matric[i][j]-matric[i+1][j+1]) + find_route3(i+1,j+1, T);
   	  sum2 = std::abs(matric[i][j]-matric[i+1][j]) + find_route3(i+1,j, T);
   	  sum3 = std::abs(matric[i][j]-matric[i][j+1]) + find_route3(i,j+1, T);
   	  minn = min(sum1,sum2,sum3);


   	  if (sum1 == minn)
   	  {
   	  	T[i][j] = 1;
   	  }
   	  else if (sum2 == minn)
   	  {
   	  	T[i][j] = 2;
   	  }
   	  else{
   	  	T[i][j] = 3;
   	  }

   	  return minn;
   }
}

//find route with fourth way
int Map::find_route4(int i, int j, int** T)
{	
	int sum2{},sum3{},minn{};
   if (i > n-1 || j > n-1) 
      return 10000000; 
   else if (i == n-1 && j == n-1) 
      return 0; 
   else{
   	  
   	  sum2 = std::abs(matric[i][j]-matric[i+1][j]) + find_route4(i+1,j, T);
   	  sum3 = std::abs(matric[i][j]-matric[i][j+1]) + find_route4(i,j+1, T);


   	  if (sum2 < sum3)
   	  {
   	  	T[i][j] = 2;
   	  	minn = sum2;
   	  }
   	  else
   	  {
   	  	T[i][j] = 3;
   	  	minn = sum3;
   	  }
   	  

   	  return minn;
   }
}


//calaculate minimum of three integer
int Map::min(int x, int y, int z) 
{ 
   if (x < y) 
      return (x < z)? x : z; 
   else
      return (y < z)? y : z; 
} 


//find route with second way
int Map::find_route2()
{
	int i{};
	int j{};
	int first{};
	int second{};
	int third{};
	int sum{};
	route_gh.push_back(0);
	route_gh.push_back(0);
	
	while(j< n-1 && i< n-1){
		first = std::abs(matric[i][j] - matric[i][j+1]);
		second = std::abs(matric[i][j] - matric[i+1][j]);
		third = std::abs(matric[i][j] - matric[i+1][j+1]);
			
		if (first <= second && first< third)
		{
			j+=1;
			sum+=first;
			
			route_gh.push_back(i);
			route_gh.push_back(j);
			
			if (j == (n-1))
			{
				while(i<n-1){
					sum+= std::abs(matric[i][j]- matric[i+1][j]);
					i+=1;
					std::vector<int> v1;
					route_gh.push_back(i);
					route_gh.push_back(j);
					
				}
				
			}

		}
		else if(second < first && second < third){
			i+=1;
			sum+=second;
			route_gh.push_back(i);
			route_gh.push_back(j);
			
			if (i == (n-1))
			{
				while(j < n-1){
					sum+= std::abs(matric[i][j] - matric[i][j+1]);
					j+=1;
					route_gh.push_back(i);
					route_gh.push_back(j);
				}
				
			}
		}
		else{
			i+=1;
			j+=1;
			sum+=third;
			route_gh.push_back(i);
			route_gh.push_back(j);
			if (i == (n-1))
			{
				while(j < n-1){
					sum+= std::abs(matric[i][j] - matric[i][j+1]);
					j+=1;
					route_gh.push_back(i);
					route_gh.push_back(j);
				}
				
			}
			if (j == (n-1))
			{
				while(i<n-1){
					sum+= std::abs(matric[i][j]- matric[i+1][j]);
					i+=1;
					std::vector<int> v1;
					route_gh.push_back(i);
					route_gh.push_back(j);
					
				}
				
			}

		}

	}
	return sum;
}


//find route with first way
int Map::find_route1(){
	int i{};
	int j{};
	int first{};
	int second{};
	
	int sum{};
	route.push_back(0);
	route.push_back(0);
	
	while(j< n-1 && i< n-1){
		first = std::abs(matric[i][j] - matric[i][j+1]);
		second = std::abs(matric[i][j] - matric[i+1][j]);
			
		if (first <= second)
		{
			j+=1;
			sum+=first;
			
			route.push_back(i);
			route.push_back(j);
			
			if (j == (n-1))
			{
				while(i<n-1){
					sum+= std::abs(matric[i][j]- matric[i+1][j]);
					i+=1;
					std::vector<int> v1;
					route.push_back(i);
					route.push_back(j);
					
				}
				
			}

		}
		else{
			i+=1;
			sum+=second;
			route.push_back(i);
			route.push_back(j);
			
			if (i == (n-1))
			{
				while(j < n-1){
					sum+= std::abs(matric[i][j] - matric[i][j+1]);
					j+=1;
					route.push_back(i);
					route.push_back(j);
				}
				
			}
		}

	}
	return sum;
}


//show map with first way
void Map::show_route1(){
	for (size_t i = 0; i <= route.size(); i+=2)
	{
		route1[route[i]][route[i+1]] = "*";
	}
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{	
			if (route1[i][j]=="")
			{
				route1[i][j] = "-";
			}
			std::cout << route1[i][j] << "  ";
		}
		std::cout << std::endl;
		
	}
}

//show map with second way
void Map::show_route2(){
	for (size_t i = 0; i <= route_gh.size(); i+=2)
	{
		route2[route_gh[i]][route_gh[i+1]] = "*";
	}
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{	
			if (route2[i][j]=="")
			{
				route2[i][j] = "-";
			}
			std::cout << route2[i][j] << "  ";
		}
		std::cout << std::endl;
		
	}
}

//show map with third way
void Map::show_route3(){
	route3[0][0] = "*";
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{	
			if (route3[i][j]=="")
			{
				route3[i][j] = "-";
			}
			std::cout << route3[i][j] << "  ";
		}
		std::cout << std::endl;
		
	}
}


//show map with fourth way
void Map::show_route4(){
	route4[0][0] = "*";
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{	
			if (route4[i][j]=="")
			{
				route4[i][j] = "-";
			}
			std::cout << route4[i][j] << "  ";
		}
		std::cout << std::endl;
		
	}
}