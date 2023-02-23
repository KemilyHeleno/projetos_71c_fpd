//exercício 12 com variáveis float
#include<stdio.h>
float calculo (float a1, float b1, float c1)
{
	float d1;
	d1=a1*b1+c1;
	return d1;
}
main()
{
	float f; float g; float h; float i;
	printf("Digite um numero: ");
	scanf("%f",&f);
	printf("Digite um numero: ");
	scanf("%f",&g);
	printf("Digite um numero: ");
	scanf("%f",&h);
	i=calculo(f,g,h);
	printf("resultado %.2f",i);
}
