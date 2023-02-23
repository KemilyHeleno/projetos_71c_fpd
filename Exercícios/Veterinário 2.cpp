#include<stdio.h>
#define animal 1
struct veterinario
{
	char codigo[1000];
	char nome[40];
	char tipo[1000];
	char raca[30];
	struct nascimento
	{
		int dia;
		int mes;
		int ano;
	}nasc;
	float valor;
};
void Cadastro (veterinario dados)
{
	puts(dados.codigo);
	puts(dados.nome);
	puts(dados.tipo);
	puts(dados.raca);
	printf("\n%d/%d/%d",dados.nasc.dia,dados.nasc.mes,dados.nasc.ano);
	printf("\nR$ %.2f\n\n",dados.valor);
}
main()
{
	veterinario b[animal];
	int codigo;
	while(true)
	{
		for(int i=0; i<animal; i++)
		{
			printf("Digite o codigo do animal: ");
			gets(b[i].codigo);
			printf("Digite o nome do animal: ");
			gets(b[i].nome);
			printf("Digite o tipo do seu animal (ex: gato, cachorro, baleia...): ");
			gets(b[i].tipo);
			printf("Digite a raca do seu animal: ");
			gets(b[i].raca);
			printf("Digite a data de nascimento do seu animal (se for conhecida): ");
			printf("Dia     ");
			scanf("%d",&b[i].nasc.dia);
			printf("Mes     ");
			scanf("%d",&b[i].nasc.mes);
			printf("Ano     ");
			scanf("%d",&b[i].nasc.ano);
			printf("Digite o preco que foi o animal (se tiver sido por doacao colocar o valor 0): ");
			scanf("%f",&b[i].valor);
			fflush(stdin);
			printf("\n\n");
		}
		for(int i=0; i<animal; i++)
			Cadastro(b[i]);
			printf("Digite o codigo --> zero encerra");
			scanf("%d",&codigo);
			if(codigo==0)
			break;
	}
}
