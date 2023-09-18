//Calcular a média, mediana e a moda
#include <stdlib.h>
#include <stdio.h>
#define TAM 11
using namespace std;
//int vet[TAM] = {0,4,5,3,2,7,9,1,8,6};
int vet[TAM] = {34,39,36,35,37,40,36,38,36,38,41};
float soma = 0, media = 0, mediana = 0, somaMediana = 0, moda = 0, conta;
int cont[TAM];
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
	if(vet[x]<vet[y])//Ordena
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
			soma = soma + vet[x];
			x++;
			y=x+1;
		}
		ordena(x, y);
	}
}
void calcMediana(){//Calculo da mediana
	if(TAM%2){
         mediana = vet[TAM/2];
    } else {
    	somaMediana = vet[TAM/2-1]+vet[TAM/2];
        mediana = (somaMediana)/2;
    }
    printf("\n Mediana: %2.1f", mediana);
}
void calcMedia(){//Calculo da média
	media = soma/TAM;
	printf("\n Media: %.2f ", media);
}
float calcModa(int x, int y){//Calculo da moda
	if(vet[x]==vet[y]){
		cont[x]++;
		if(cont[x]>conta){
			conta = cont[x];
			moda = vet[x];
		}
	}	
	if(x<TAM)
	{
		if(y<TAM)
			y++;
		else{
			cont[x]=0;
			x++;
			y=x+1;
		}
		calcModa(x, y);
	}
		
	 if(conta == 0){
    	printf(" \nNao existe moda");
    	return 0;
	}
	else{
		return moda;
	}
}
int main()
{
	ordena(0, 1);
	imprime(0, 0);
	printf("\n");
	imprime(0 ,1);	
	calcMedia();
	calcMediana();
	if(calcModa(0,1) != 0)
	{
		printf("\n Moda: %.2f ", moda); 
	}
	return 0;
}
