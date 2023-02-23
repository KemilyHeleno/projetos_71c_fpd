#include<stdio.h>
float imc(float kg, float altura)
{
	float imc =kg/(altura*altura);
	return imc;
}
main()
{
	float k; float al; float i;
	printf("digite o seu peso: ");
	scanf("%f",&k);
	printf("digite a sua altura: ");
	scanf("%f",&al);
	i=imc(k,al);
	if(i<20)
	printf("abaixo do peso");
	else if (i>=20, i<25)
	printf("%f normal",i);
	else if (i>=25, i<30)
	printf("%f excesso de peso",i);
	else if(i>=30, i<35)
	printf("%f obesidade",i);
	else if (i>=35)
	printf("%f obesidade morbida",i);
}
