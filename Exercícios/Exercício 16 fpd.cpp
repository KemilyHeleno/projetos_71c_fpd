#include<stdio.h>
float validacao(float a, float b, float c, float d, float e)
{
	do 
	{
		if (a <=0 || a >=10)
		{
			printf("\nvalor invalido, redigite.\n");
			scanf("%f",&a);
		}
			
	}while(a <=0 || a >=10);
	
	do 
	{
		if (b <=0 || b >=10)
		{
			printf("\nvalor invalido, redigite.\n");
			scanf("%f",&b);
		}
			
	}while(b <=0 || b >=10);
	
	do 
	{
		if (c <=0 || c >=10)
		{
			printf("\nvalor invalido, redigite.\n");
			scanf("%f",&c);
		}
			
	}while(c <=0 || c >=10);
	
	do 
	{
		if (d <=0 || d >=10)
		{
			printf("\nvalor invalido, redigite.");
			scanf("%f",&d);
		}
			
	}while(d <=0 || d >=10);
	
	e=(a+b+c+d)/4;
	return e;
}
main()
{
	float no1, no2, no3, no4, media;
	printf("\nDigite a primeira nota: ");
	scanf("%f",&no1);
	printf("\nDigite a segunda nota: ");
	scanf("%f",&no2);
	printf("\nDigite a terceira nota: ");
	scanf("%f",&no3);
	printf("\nDigite a quarta nota: ");
	scanf("%f",&no4);
	media=validacao(no1, no2, no3, no4, media);
	printf("media final=%1.f",media);
}
