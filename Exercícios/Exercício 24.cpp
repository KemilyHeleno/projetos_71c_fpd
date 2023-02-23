#include<stdio.h>
void media(float *, float *, float *, float *, float*);
float nota_final(float *);
main()
{
	float a, b, c, d, nota, notafinal;
	media(&a, &b, &c, &d, &nota);
	notafinal= nota_final(&nota);
	printf("O valor da media final eh %1.f",nota);
}
void media (float *a, float *b, float *c, float *d, float *nota)
{
	float notafinal;
	printf("Digite o valor da media do primeiro bim: ");
	scanf("%d",&*a);
	printf("Digite o valor da media do segundo bim: ");
	scanf("%d",&*b);
	printf("Digite o valor da media do terceiro bim: ");
	scanf("%d",&*c);
	printf("Digite o valor da media do quarto bim: ");
	scanf("%d",&*d);
	*nota = *a + *b + *c + *d;
}
void nota_final (float *nota)
{
	*nota= *nota/4;
}
