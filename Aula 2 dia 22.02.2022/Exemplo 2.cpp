//Sequencia de fibonacci usando função
//Procedural
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int fibonacci(int val1, int val2){
	float result = 0;
	
	for(int i = 2; i< 100; i++){
		result = val1 + val2;
		val1 = val2;
		val2 = result;
		printf("\n %.f", result);
	} 
}

int main(){
	double val1 = 0, val2 = 1, result = 0;
	printf("\n %.f \n %.f", val1, val2);
	fibonacci(val1, val2);
	return 0;	
}
