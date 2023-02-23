#include<stdio.h>
#define dados 2
struct info
{
	char nome[50];
	char endereco[60];
	char cidade[30];
	char CEP[11];
	char telefone[20];
	float aniversario;
	char email[50];
	
};
void mostra_dados (info dados1)
{
	puts(dados1.nome);
	puts(dados1.endereco);
	puts(dados1.cidade);
	puts(dados1.CEP);
	puts(dados1.telefone);
	puts(dados1.email);
	printf("%f",dados1.aniversario);	
}
main()
{
	info b[dados];
	for(int i=0; i<dados; i++)
	{
		printf("Digite o seu nome: ");
		gets(b[i].nome);
		printf("Digite o seu endereco: ");
		gets(b[i].endereco);
		printf("Digite a sua cidade");
		gets(b[i].cidade);
		printf("Digite seu CEP: ");
		gets(b[i].CEP);
		printf("Digite seu telefone");
		gets(b[i].telefone);
		fflush(stdin);
		printf("Digite seu e-mail: ");
		gets(b[i].email);	
		printf("Digite a data do seu aniversario: ");
		scanf("%f",&b[i].aniversario);		
		printf("\n\n");
	}
	for(int i=0; i<dados; i++)
	mostra_dados(b[i]);
}
