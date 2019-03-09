//================= MOSTAFA SADEGHI   9423067 =============

#include"libArr.h"

void libArr::makeArr(long long int aNumber){
	long long int* arr = new long long int[aNumber]; 
	  	long long int sum{};
	    /* Some operations on arr[] */
	    for (long long int i = 0; i <= aNumber; i++){
	      	arr[i]=i;
	      	sum+=i;
	      }
}