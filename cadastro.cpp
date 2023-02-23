/*
Exemplo simples de cadastro em um arquivo binário.
Profa. Ariane Scarelli, CTI-Unesp
Atualizações: AGO/2019		++ Versão sem conio.c. Funções anexadas ++
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
struct estrut1
{
	int codigo;
	char nome[40];
	char sexo[2];
	struct estrut2
	{
		int dia, mes, ano;
	}dnasc;
	char email[20];
	char excluido;//para a exclusão lógica
}agenda;

FILE *fp;

text_info vActual = {0, 0, 79, 24, WHITE, WHITE, C80, 25, 80, 1, 1}; //25 linhas, 80 colunas
											        //lin,col
void textcolor(int newcolor)
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0xf0) | newcolor);
   vActual.attribute = (csbi.wAttributes & 0xf0) | newcolor;
}

void textbackground(int newcolor)
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0x0f) | (newcolor << 4));
   vActual.attribute = (csbi.wAttributes & 0x0f) | (newcolor << 4);
}

void cursor (int x) { // mostra ou não o cursor do prompt
	switch (x) {
		case 0: {//ocultar cursor
			CONSOLE_CURSOR_INFO cursor = {1, FALSE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
			break;
		}
		case 1: {//apresentar cursor
			CONSOLE_CURSOR_INFO cursor = {1, TRUE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
			break;
		}
	}
}

void gotoxy(int x, int y)
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void mascara_dados()
{
	system("cls");
	gotoxy(10,2);printf("Cadastro de Pessoas");
	gotoxy(10,5);printf("Codigo: ");	
	gotoxy(10,6);printf("Nome  : ");
	gotoxy(10,7);printf("Sexo  : ");
	gotoxy(25,7);printf("Data nascimento:   /  /");
	gotoxy(10,8);printf("e-mail: ");
}
void salvar_dados()
{
	char conf;
	gotoxy(18,11);printf("Confirma os dados para gravacao ? (S/N): ");
	do
   	{
       	gotoxy(61,11); conf = getche();
   	}while( conf != 's' && conf != 'S'
		&& conf != 'n' && conf != 'N' );
   	
	if( conf == 's' || conf == 'S' )
   	{
		if(fwrite(&agenda, sizeof(agenda), 1, fp) != 1) /* Escreve a estrutura no arquivo */
		{
		    gotoxy(18,13);printf("Erro na escrita do arquivo");
		}
		else
		{
			fflush( fp );//descarrega o buffer no disco
			gotoxy(18,13);printf("Dados salvos com sucesso!");
		}
		getch();
	}
}
void digitar_dados()
{
	mascara_dados();
	gotoxy(18,5);scanf("%d",&agenda.codigo);
	fflush(stdin);
	gotoxy(18,6);gets(agenda.nome);
	gotoxy(18,7);gets(agenda.sexo);
	gotoxy(42,7);scanf("%d",&agenda.dnasc.dia);
	gotoxy(45,7);scanf("%d",&agenda.dnasc.mes);
	gotoxy(48,7);scanf("%d",&agenda.dnasc.ano);
	fflush(stdin);
	gotoxy(18,8);gets(agenda.email);
	agenda.excluido='N'; //atribui 'N' para status da tabela, ou seja, registro está ativo (não excluído)
	salvar_dados();
}
void abrir_arquivo()
{
	if((fp = fopen("arq.bin", "ab+")) == NULL) 
	/* Abre arquivo binário para leitura e escrita */
	{
		gotoxy(18,11);printf("Erro na abertura do arquivo.");
	    exit(1);
	}	
}
main()
{
	textcolor(5);
	textbackground(7);
	system("cls");
	abrir_arquivo();
	digitar_dados();
	system("cls");	
	gotoxy(18,10);printf("Obrigado por utilizar nosso sistema!");
	getch();
	cursor(0);//ocultar cursor
	gotoxy(18,12);printf("O cursor foi escondido!");
	getch();
	cursor(1);//mostrar cursor	
	gotoxy(18,13);printf("O cursor reapareceu!");
	getch();
}
