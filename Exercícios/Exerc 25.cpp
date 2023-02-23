#include <stdio.h>
void igual(int *a,int *b)
{
	int c=*a;
	int d=*b;
	*a=d;
	*b=c;
}
main()
{
	int comunista,nazista;
	printf("Insira um valor:");
	scanf("%d",&comunista);
	printf("Insira outro:");
	scanf("%d",&nazista);
	igual(&comunista,&nazista);
	printf("%d e %d",comunista,nazista);
}
