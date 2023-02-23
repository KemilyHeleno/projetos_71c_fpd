#include<stdio.h>
#define animal 3
struct stveterinario
{
	char codigo[100];
	char nome[100];
	char tipo[100];
	char raca[100];
	char nasc[100];
	float valor;
};
void cadastro (stveterinario *dados)
{
	printf("Digite o codigo do animal: ");
	gets(dados->codigo);
	printf("Digite o nome do animal: ");
	gets(dados->nome);
	printf("Digite o tipo do animal: ");
	gets(dados->tipo);
	printf("Digite a raca do animal: ");
	gets(dados->raca);
	printf("Digite a data de nascimento do animal: ");
	gets(dados->nasc);
	printf("Digite o valor do animal: ");
	scanf("%f",&dados->valor);
	fflush(stdin);
	printf("\n\n");
}
void mostra_cadastro (stveterinario *dados)
{
	puts(dados->codigo);
	puts(dados->nome);
	puts(dados->tipo);
	puts(dados->raca);
	puts(dados->nasc);
	printf("R$ %.2f",dados->valor);
}
main()
{
	stveterinario qtde[animal];
	for ( int i=0; i<animal; i ++)
	{
		cadastro(&qtde[i]);
	}
	for (int i=0; i<animal; i++)
	{
		mostra_cadastro(&qtde[i]);
	}
}
