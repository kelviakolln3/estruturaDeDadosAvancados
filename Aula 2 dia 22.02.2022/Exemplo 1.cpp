//Sequencia de fibonacci
//Procedural
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(){
	double val1 = 0, val2 = 1, result = 0;
	printf("\n %.f \n %.f", val1, val2);
	
	for(int i = 2; i< 100; i++){//Vai repetir 98 vezes ja que os elementos 0 e 1 ja existem
		result = val1 + val2;
		val1 = val2;
		val2 = result;
		printf("\n %.f", result);
	} 
	return 0;
}
