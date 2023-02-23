#include <stdio.h>
void senpai(float*a, float*b,float*c,float*d)
{
	printf("Insira uma note: ");
	scanf("%f",&*a);
	printf("Insira uma note: ");
	scanf("%f",&*b);
	printf("Insira uma note: ");
	scanf("%f",&*c);
	printf("Insira uma note: ");
	scanf("%f",&*d);
}
float somiu(float a, float b,float c,float d)
{
	float aoba=a+b+c+d;
	aoba/=4;
	return aoba;
}
main()
{
	float arface,aoba,berti,arroba;
	senpai(&arface,&aoba,&berti,&arroba);
	printf("%.1f",somiu(arface,aoba,berti,arroba));
	
}

