//bibliotecas
#include<stdio.h>
#include <conio.h>
void procura( char str[30], char p )
{
int i;
for( i = 0; str[i]; i++ )
if( str[i] == p )
{
printf("\n\nEncontrou !");
return;
}
printf("\n\nNao encontrou !");
return;
}
main()
{
char str[30], p;
printf("Digite uma frase: ");
gets(str); // para ler uma string
printf("\nDigite um caractere a ser procurado na frase: ");
p = getche(); //para ler um caractere
procura( str, p );
}
