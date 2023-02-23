//exercicio da prova o mais dificil da programacao 
//ESTUDAR
//exercicio de soma de valores variados
#include<stdio.h>
int quadrado(int);
main()
{
	int num, quad;
	printf("Digite um numero: ");
	scanf("%d",&num);
	quad=quadrado(num);
	printf("Quadrado = %d", quad);
}
int quadrado (int n)
{
	int q=0;
	int i=1;
	for(int a=1; a<=n; a++)
	{
		q+=i;  //q=q+i
		i+=2;
	}
	return q;
}
