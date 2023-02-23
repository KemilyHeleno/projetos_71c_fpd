#include<stdio.h>
void imc (float peso, float altura, float *IMC)
{
	altura*=altura;
	*IMC= peso/altura;
}
main()
{
	float kg, alt, IMC;
	printf("Digite o seu peso: ");
	scanf("%f",&kg);
	printf("Digite a sua altura: ");
	scanf("%f",&alt);
	imc(kg, alt, &IMC);
	if (IMC < 20)
	{
		printf("\nVoce esta abaixo do peso");
	}
	else if (IMC >= 20 ||  IMC <= 25)
	{
		printf("\nVoce esta com o peso ideal");
	}
	else if (IMC > 25 || IMC < 30)
	{
		printf("\nvoce esta excesso de peso");
	}
	else if (IMC >= 30 || IMC <= 35)
	{
		printf("\nVoce esta com obesidade e precisa comecar a se tratar");
	}
	else if (IMC > 35)
	{
		printf("\nVoce possui uma obesidade morbida, me impressiona voce nao ter tido um infarto ainda");
	}
}
