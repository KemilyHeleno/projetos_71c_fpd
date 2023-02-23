#include<stdio.h>
int soma;
void calculo(int mun1, int mun2)
{
soma=mun1+mun2;
}
main()
{
	int num1, num2;
	printf("Digite um numero: ");
	scanf("%d",&num1);
	printf("Digite mais um numero: ");
	scanf("%d",&num2);
	calculo(num1,num2);
	printf("A soma dos valores digitedos eh = %d",soma);
}
