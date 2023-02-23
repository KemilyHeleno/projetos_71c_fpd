//comando return
#include<stdio.h>
int calculo(int a1, int b1)
{
int c1;
c1 = a1 * b1;
return c1;
}
main()
{
int a,b,c;
a = 10;
b = 20;
c = calculo(a,b);
printf("Resultado = %d", c);
}

