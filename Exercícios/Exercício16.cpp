#include<stdio.h>
float validacao(float a)
{
	do 
	{
		if (a <=0 || a >=10)
		{
			printf("\nvalor invalido, redigite.\n");
			scanf("%f",&a);
		}
			
	}while(a <=0 || a >=10);
	return a;	
}

float media(float a, float b, float c, float d)
{
	float e;
	e=(a+b+c+d)/4;
	return e;	
}
main()
{
	float nota1; float nota2; float nota3; float nota4; float mediaritmetica;
	printf("Digite a nota: ");
	scanf("%f",&nota1);
	nota1=validacao(nota1);
	printf("\nDigite a nota: ");
	scanf("%f",&nota2);
	nota2=validacao(nota2);
	printf("\nDigite a nota: ");
	scanf("%f",&nota3);
	nota3=validacao(nota3);
	printf("\nDigite a nota: ");
	scanf("%f",&nota4);
	nota4=validacao(nota4);
	mediaritmetica = media (nota1,nota2,nota3,nota4);
	printf("\nA media aritmetica eh %1.f ",mediaritmetica);
}
