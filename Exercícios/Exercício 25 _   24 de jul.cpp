#include<stdio.h>
void cont (int *a, int *b)
{
	int x=*a;
	int y=*b;
	*a=y;
	*b=x;
}
main()
{
	int a,b;
	printf("Digite um numero: ");
	scanf("%d",&a);
	printf("Digite um numero: ");
	scanf("%d",&b);
	cont(&a,&b);
	printf("%d e %d",a,b);
}
