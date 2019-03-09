#include <iostream>
#include <vector>
#include <chrono> 
#include"libArr.h"
#include"libVec.h"

using std::cout;
using std::endl;

//================= MOSTAFA SADEGHI   9423067 ================

void runtime(void (libArr::* xptr) (long long int),
	void (libVec::* yptr) (long long int), long long int arg);
	
int main() {
	//declare member class methods
	void (libArr::* arr2) (long long int) = &libArr::makeArr;
	void (libVec::* vect2) (long long int) = &libVec::makeVector;
	//calculate from 1 to 1000000
	for (int i = 1; i <= 1000000; i*=10)
	{
		runtime(arr2,vect2,i);
	}
	return 0;
}


//runtime function that gives two class member method and calculate runnnig time
void runtime(void (libArr::* xptr) (long long int),
	void (libVec::* yptr) (long long int), long long int arg){
	// f(arg);
	auto start = std::chrono::steady_clock::now(); 
	libArr xobject;
	(xobject.*xptr)(arg);
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	std::cout << "array(" <<  arg << " : " <<
		std::chrono::duration <double, std::milli> (diff).count() << " ms )" << endl; 
	start = std::chrono::steady_clock::now(); 
	libVec yobject;
	(yobject.*yptr)(arg);
	end = std::chrono::steady_clock::now();
	diff = end - start;
	std::cout << "vector(" <<  arg << " : " <<
		std::chrono::duration <double, std::milli> (diff).count() << " ms )" << endl; 
	
}

 



