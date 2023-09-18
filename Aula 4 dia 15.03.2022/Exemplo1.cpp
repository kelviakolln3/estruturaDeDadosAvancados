#include <cstdlib>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct produtos {
       char nome_prod[30];
       float preco;

}carro, moto;

int main(int argc, char *argv[])
{
	produtos *p_carro;
	p_carro = &carro;
	produtos *p_moto;
	p_moto = &moto;
    cout << "Escreva o nome do seu carro" << endl;
    //fflush (stdin);//Limpar teclado
    gets(p_carro->nome_prod);
    cout << "Escreva o preco do seu carro" << endl;
    scanf("%f", &p_carro->preco);
    cout << "Escreva o nome da sua moto" << endl;
    scanf(" %[^\n]s", &p_moto->nome_prod);/*Outra maneira para ler nomes compostos. So vai termiar de ler 
	quando o usuario der um enter. Isso é uma expressão regular*/
    cout << "Escreva o preco da sua moto" << endl;
    scanf("%f", &p_moto->preco);
    cout << "Seu carro e "  << p_carro->nome_prod << " R$ " << p_carro->preco << endl;
    cout << "Sua moto e " << p_moto->nome_prod << " R$ " << p_moto->preco << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
