#include"libVec.h"
#include<vector>


//================= MOSTAFA SADEGHI   9423067 =============

void libVec::makeVector(long long int aNumber){
	std::vector<long long int> aVector;
		long long int sum{};
		for (long long int i = 0; i <= aNumber; i++){
			aVector.push_back(i);
			sum+=i;
		}
}