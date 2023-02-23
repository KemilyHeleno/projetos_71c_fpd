/*
	Exemplo de menu
		
	Conte�dos: 
		-movimenta��o por setas;
		-aumento da janela de execu��o;
		-uso de cores, posicionamento de cursor, ocultar/mostrar cursor;
		-uso da fun��o Sleep().
	
	Profa. Ariane Scarelli, CTI-Unesp, Bauru-SP
	Agosto/2018
	
	obs.: para executar este exemplo no computador da sua casa � necess�rio
	      baixar e instalar os arquivos da pasta conio.c do OneDrive. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

text_info vActual = {0, 0, 79, 24, WHITE, WHITE, C80, 25, 80, 1, 1};

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

void cursor (int x) { // mostra ou n�o o cursor do prompt
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

main()
{
	char c;
	int lin=5;
	int sair;
	
	SetConsoleTitle("Muda o Nome na Barra do Windows");
	system("mode con:cols=120 lines=35"); //aumenta a tela para 120 colunas e 35 linhas
	
	textcolor(1); // cor de letra
	textbackground(BROWN+BLACK); // cor de fundo
	system("cls"); // limpar/pintar a tela

	cursor(0);//ocultar cursor
	do
	{
		sair=1;
		
		gotoxy(22,3);printf("Modelo de Menu com Setas");
		gotoxy(10,5);printf("Op%c%co 1", 135, 198);
		           //135 � o caractere '�' e 198 � o caractere '�'
		gotoxy(10,7);printf("Op%c%co 2", 135, 198);
		gotoxy(10,9);printf("Op%c%co 3", 135, 198);
		gotoxy(10,11);printf("Sair");
		gotoxy(8,lin); printf("%c", 62);//62 � o caractere '>'
		c=getch();
		gotoxy(8,lin); printf(" ");
	
		switch(c)//movimento das setas
		{
			case 72 : //seta para cima
				lin-=2;
				if(lin<5)
				{
					lin=11;	
				}
				gotoxy(8,lin); printf("%c", 62);
				break;
			case 80 : //seta para baixo
				lin+=2;
				if(lin>11)
				{
					lin=5;
				}
				gotoxy(8,lin); printf("%c", 62);
				break;
		}
		
		switch(c)//Quando teclar enter para escolher op��o
		{
			case 13: //teclou enter
				if(lin==5)
				{
					gotoxy(20,15);printf("Voc%c escolheu a \'Opcao 1\'", 136);
									            //136 � o caractere '�'
					Sleep(1500);
					gotoxy(20,15);printf("                           ");					
				}
				else
				if(lin==7)
				{
					gotoxy(20,15);printf("Voce escolheu a \'Opcao 2\'");
					Sleep(1500);
					gotoxy(20,15);printf("                           ");
				}
				else
				if(lin==9)
				{
					gotoxy(20,15);printf("Voce escolheu a \'Opcao 3\'");
					Sleep(1500);
					gotoxy(20,15);printf("                           ");
				}
				else
				if(lin==11)
				{
					gotoxy(20,15);printf("Voce escolheu \'Sair\'");
					sair=0;
				}
		}

	}while(sair);
	cursor(1);//mostrar cursor
	gotoxy(10,20);printf("N%co tecle nada, aguarde a pausa...", 198);
	Sleep(2000);
}
