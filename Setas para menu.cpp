#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/*Autor: Ruben Alves do Nascimento
  Contato: rubenanapu@hotmail.com       
*/
main()
{
	char c;
	printf("\t\t\tPRESSIONE AS SETAS DO TECLADO: ");
	do{
	   c=getch();
	   system("cls");
	   switch(c){
			case 75: 
				printf("\n\n\n\n\n\n\n\n\nPressione as setas do teclado ou ESC para sair: ");
           		break;   //75 é o valor da tecla seta para esquerda na tabela ASCII
           	case 77: 
			   	printf("\n\n\n\n\n\n\n\n\n\t\t\t\tPressione as setas do teclado ou ESC para sair: ");
           		break;   //77 é o valor da tecla seta para direita na tabela ASCII
           case 72: 
		   		printf("\t\tPressione as setas do teclado ou ESC para sair: ");
           		break;   //72 é o valor da tecla seta para cima na tabela ASCII
           case 80: 
		   		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tPressione as setas do teclado ou ESC para sair: ");
           		break;   //80 é o valor da tecla seta para baixo na tabela ASCII	   	
	   }                 
	}while(c!=27);        //27 é o valor da tecla ESC na tabela ASCII
    system("pause");       
}
