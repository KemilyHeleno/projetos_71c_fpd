//bibliotecas
#include<stdio.h>
//variáveis globais
float med;
void media(float no1, float no2, float no3, float no4)
{
med = (no1+no2+no3+no4)/4;
}
main()
{
float n1, n2, n3, n4;
printf("Digite a primeira nota: ");
scanf("%f",&n1);
printf("\nDigite a segunda nota: ");
scanf("%f",&n2);
printf("\nDigite a terceira nota: ");
scanf("%f",&n3);
printf("\nDigite a quarta nota: ");
scanf("%f",&n4);
media(n1,n2,n3,n4);
printf("\n\nMedia das notas digitadas = %.1f", med);
}
