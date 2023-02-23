//Exercicio 1 da lista
#include<stdio.h>
void calculo(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, float *media)
{
	*media=(a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10)/10;
}
main()
{
	int b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;
	float media;
	printf("Digite os numeros em ordem: ");
	scanf("%d",&b1);
	printf(" ");
	scanf("%d",&b2);
	printf(" ");
	scanf("%d",&b3);
	printf(" ");
	scanf("%d",&b4);
	printf(" ");
	scanf("%d",&b5);
	printf(" ");
	scanf("%d",&b6);
	printf(" ");
	scanf("%d",&b7);
	printf(" ");
	scanf("%d",&b8);
	printf(" ");
	scanf("%d",&b9);
	printf(" ");
	scanf("%d",&b10);
	calculo(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10, &media);
	printf("A media desses valores eh %.2f",media);
}
