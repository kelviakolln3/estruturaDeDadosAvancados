#include <stdlib.h>
#include <stdio.h>
#define TAM 10
using namespace std;
int vet[TAM] = {0,4,5,3,2,7,9,1,8,6};
void imprime(int x, int asc)
{
	if(asc)
		printf(" %d ", vet[x]);
	if(x<TAM-1)
		imprime(x+1, asc);
	if(!asc)
		printf(" %d ", vet[x]);		
}
void ordena(int x, int y){
	int aux;
	if(vet[x]<vet[y])
	{
		aux = vet[x];
		vet[x] = vet[y];
		vet[y] = aux;
	}
	if(x<TAM)
	{
		if(y<TAM)
			y++;
		else{
			x++;
			y=x+1;
		}
		ordena(x, y);
	}
}
int main()
{
	ordena(0, 1);
	imprime(0, 0);
	printf("\n");
	imprime(0 ,1);
	return 0;
}
