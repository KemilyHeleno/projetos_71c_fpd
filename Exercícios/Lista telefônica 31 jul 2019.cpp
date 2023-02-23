#include<stdio.h>
#include<string.h>
struct stdados
{
	char nome[20];
	char endereco[55];
	char cidade[20];
	char CEP[50];
	char telefone[13];
	char aniversario[10];
	char email[90];
};
void lista(stdados dados)
{
	puts(dados.nome);
	puts(dados.endereco);
	puts(dados.cidade);
	puts(dados.CEP);
	puts(dados.telefone);
	puts(dados.aniversario);
	puts(dados.email);
}
main()
{
	stdados p1, p2, p3;
	printf("Digite seu nome: ");
	gets(p1.nome);
	printf("\nDigite seu endereco: ");
	gets(p1.endereco);
	printf("\nDigite sua cidade: ");
	gets(p1.cidade);
	printf("\nDigite seu CEP: ");
	gets(p1.CEP);
	printf("\nDigite a data do nascimento: ");
	gets(p1.aniversario);
	printf("\nDigite seu email: ");
	gets(p1.email);
	
	printf("Digite seu nome: ");
	gets(p2.nome);
	printf("\nDigite seu endereco: ");
	gets(p2.endereco);
	printf("\nDigite sua cidade: ");
	gets(p2.cidade);
	printf("\nDigite seu CEP: ");
	gets(p2.CEP);
	printf("\nDigite a data do nascimento: ");
	gets(p2.aniversario);
	printf("\nDigite seu email: ");
	gets(p2.email);
	
	printf("Digite seu nome: ");
	gets(p3.nome);
	printf("\nDigite seu endereco: ");
	gets(p3.endereco);
	printf("\nDigite sua cidade: ");
	gets(p3.cidade);
	printf("\nDigite seu CEP: ");
	gets(p3.CEP);
	printf("\nDigite a data do nascimento: ");
	gets(p3.aniversario);
	printf("\nDigite seu email: ");
	gets(p3.email);
	lista(p1);
	lista(p2);
	lista(p3);
}
