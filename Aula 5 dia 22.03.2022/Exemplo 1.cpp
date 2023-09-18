#include <cstdlib>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct filmes {
       char titulo[100];
       char duracao[5];
       int ano;

};
struct pessoa {
       char nome[100];
       filmes favorito;
};

int main(int argc, char *argv[])
{
	pessoa p;
	pessoa *p_pessoa;
	p_pessoa = &p;
	printf("Informe o nome do filme \n");
	scanf(" %[^\n]s", p_pessoa->favorito.titulo);
	printf("Informe a duracao \n");
	scanf(" %[^\n]s", &p.favorito.duracao);
	p_pessoa->favorito.ano = 2010;
	
    printf("Filme %s duracao %s ano %i", p.favorito.titulo, p.favorito.duracao, p.favorito.ano);
    return EXIT_SUCCESS;
}
