#include<stdio.h>
struct stanimal
{
	char codigo[100];
	char nome[100];
	char raca[100];
	char nasc[100];
};
void veterinario (stanimal dados)
{
	puts(dados.codigo);
	puts(dados.nome);
	puts(dados.raca);
	puts(dados.nasc);
}
main()
{
	stanimal animal1, animal2;
	printf("Digite o codigo do animal: ");
	gets(animal1.codigo);
	printf("Digite o nome do animal: ");
	gets(animal1.nome);
	printf("Digite a raca do animal: ");
	gets(animal1.raca);
	printf("Digite a data de nascimento do animal: ");
	gets(animal1.nasc);
	printf("\n\n");
	printf("Digite o codigo do animal: ");
	gets(animal2.codigo);
	printf("Digite o nome do animal: ");
	gets(animal2.nome);
	printf("Digite a raca do animal: ");
	gets(animal2.raca);
	printf("Digite a data de nascimento do animal: ");
	gets(animal2.nasc);
	printf("\n\n");
	veterinario(animal1);
	veterinario(animal2);
}
