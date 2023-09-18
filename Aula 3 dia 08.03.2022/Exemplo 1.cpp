#include <stdlib.h>
#include <stdio.h>
using namespace std;
int vet[10] = {0,1,2,3,4,5,6,7,8,9};
void imprime(int x){
	
	printf(" %d ", vet[x]);
	if(x<9){
		imprime(x+1);
	}
}
int main()
{
	imprime(0);
	return 0;
}
