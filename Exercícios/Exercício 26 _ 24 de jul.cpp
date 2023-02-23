#include<stdio.h>
#include<math.h>
float bhaskara (float *a,float *b,float *c)
{
	int x=*a * *a;
	printf("%d",x);
}
main()
{
	float a, b, c;
	
	do 
	{
	printf("Digite o valor de a: ");
	scanf("%d",&a);
		printf("\ndigite novamente.");
	}while (a>0);
	printf("\nDigite o valor de b: ");
	scanf("%d",&b);
	printf("\nDigite o valor de c: ");
	scanf("%d",&c);
	bhaskara(&a,&b,&c);
}
