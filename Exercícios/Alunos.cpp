#include<stdio.h>
#define aluno 35
struct cadastro
{
	struct matricula
	{
		char ano[2];
		char curso[1];
		char numero[4]; 
	}
	char nome[50];
	struct nascimento
	{
		int ano;
		int mes;
		int dia;
	}
	char e_mail[30];
}
void mostra_dados()
{
	puts(cadastro.matricula.ano);
	puts(cadastro.matricula.curso);
	puts(cadastro.matricula.numero);
	puts(cadastro.nome);
	puts(cadastro.nascimento.dia);
	puts(cadastro.nascimento.mes);
	puts(cadastro.nascimento.ano);
	puts(cadastro.e_mail);
}
main
{
	cadastro b[aluno];
	int codigo;
	while(true)
	{
		for(int i=0; i<aluno; i++)
		{
			printf("Digite o ano da matricula: ");
			gets(b[i].cadastro.matricula.ano);
			printf("Digite o nome do a: ");
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
