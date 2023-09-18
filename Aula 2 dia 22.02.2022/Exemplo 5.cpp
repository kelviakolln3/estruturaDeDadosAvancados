//Programação dinamica
//É recomendado que use a PD com recursividade
//Tem como objetivo salvar dados que ja foram "calculado"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM 10
long long int fb[1000];

int fibonacci(int x){
	if(fb[x-1] == -1){//Quer dizer que tem que calcular o fibonacci
		fb[x-1] = fibonacci(x-1)+fibonacci(x-2);
		printf("%lld \n", fb[x-1]);//Jeito que o professor fez °2. Assim apresenta em ordem mas sem o 0, 1 e 1(valores que não são calculados)
	}
	//printf("%lld \n", fb[x-1]);//Jeito que o professor fez 1°. Assim repete os números que ja foram calculados
	return fb[x-1];
}
/*void ordemFibonacci(){ Jeito que eu fiz. Assim mostra todos os números em ordem contando com 0, 1 e 1(valores que não são calculados)
	int aux;
	for(int i = 0; i < TAM; i++){
		for(int j = i+1; j < TAM; j++){
			if(fb[i-1] > fb[j-1])
			{
				aux = fb[i];
				fb[i] = fb[j];
				fb[j] = aux;
			}
		}
	}
	for(int k = 0; k < TAM; k++){
	printf("%lld \n", fb[k]);
	}
}*/

int main(){
	memset(fb, -0x1, 1000); //Função que seta valores de memoria.
	fb[0] = 0;
	fb[1] = 1;
	fb[2] = 1;
	int i = TAM;
	printf("Do numero %d e: %d \n", TAM,fibonacci(i));
	//for(i=0;i<100;i++){
		//printf("Do numero %d e: %lld \n", i+1, fb[i]);
	//}
	printf("Chamada da funcao \n");
	//ordemFibonacci();
	return 0;	
}
