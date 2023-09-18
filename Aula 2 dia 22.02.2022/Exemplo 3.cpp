//Sequencia de fibonacci usando recursividade
//Procedural
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int fibonacci(int x){
	if((x == 1) || (x == 2)){
		return 1;
	}else{
		return fibonacci(x-1)+fibonacci(x-2);
	}
}

int main(){
	int i;
	for(int i = 0; i< 10; i++){
		printf("Do numero %d e: %d \n", i+1,fibonacci(i+1));
	}
	return 0;	
}
