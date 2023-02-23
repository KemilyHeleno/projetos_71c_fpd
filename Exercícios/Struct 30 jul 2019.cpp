#include <stdio.h>
#include <string.h>
struct stFilme
{
char titulo[50];
char diretor_de_filme[40];
char ator[40];
int oscar;
int ano;
} ;
void mostrafilme (stFilme filme)
{
puts(filme.titulo);
printf(" (%d)\n",filme.ano);
}
main ()
{
stFilme meu, seu;
strcpy(meu.titulo,"2001 A Space Odyssey");
meu.ano = 1968;
printf("\nDigite o titulo: ");
gets (seu.titulo);
printf("\nDigite o ano: ");
scanf("%d", &seu.ano);
printf("\nDigite o nome do diretor do filme: ");
gets(seu.diretor_de_filme);
printf("\nDigite a quantidade de oscars ganhos: ");
scanf("%d",&seu.oscar);
printf("\nDigite o nome do ator principal: ");
gets(seu.ator);
printf("\nMeu filme favorito eh:\n ");
mostrafilme (meu);
printf("\nE o seu eh:\n ");
mostrafilme (seu);
}
