//Desenvolva um algoritmo que crie um vetor de inteiros de 10 posições, 
//leia e imprima os dados lidos em ordem crescente
#include <iostream>
using namespace std;
int main ()
{
	int vet[10], aux;
	int num;
	for(int i = 0; i < 10; i ++)
	{
		cout << "Informe o "<< i+1<<" numero do vetor" << endl;
		cin >> num;
		vet[i] = num;
	}
	for(int i = 0; i < 10; i++){
		for(int j = i+1; j < 10; j++){
			if(vet[i] > vet[j])
			{
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}
	cout << " " << endl;
	cout << "Vetor em ordem crescente" << endl;
	for(int i = 0; i < 10; i++)
	{
		cout << "vet["<< i << "]" << " = " << vet[i] << endl;
	}
	return 0;	
}
