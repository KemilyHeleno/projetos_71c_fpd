#include <stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include <locale.h>

//struct cadastro do cliente
struct stCad
{
	char nome[40];
	int rg;
	char email[40];
	struct stCel
	{
		int ddd;
		int fone;
		int fone2;
	}telefone;
	struct data
	{
		int dia;
		int mes;
		int ano;
	}nasc;
	char excluido;
}cliente;
//ponteiro do arquivo do cliente
FILE *fp_c;

//struct cadastro bolo
struct stPed
{
	int id;
	char tamanho;
  //char recheio[60];
	char nome[20];
	//char cobertura[25];
	char excluido;
}bolo;
//ponteiro do arquivo do bolo
FILE *fp_b;

//declarando cabeçalho de funções
int getInt(int);
void abrir_arq_c();
void abrir_arq_b();
void cardapio();
void salva_dados();
void salva_ped();
void mostra_registro();
void registro();
void mostra_pedido();
void pedido();
void cursor (int);
void exclui();
void altera();
void consulta_cad();
void consultacad_pes();
void consulta_ped();
void submenu_cad();
void sobre ();
void menu(char, int, int);
void fecha_arqc();
void fecha_arqb();
void desenho_bolo();
void tabela();
void consulta_cad();
void consultacad_pes();
void tabelap();
void consulta_ped();
void consultaped_pes();
void submenu_cad();
void submenu_ped();
void altera();
void mostra_mascara_registro1();
void mostra_registro1();
void logo();
void sweet_cake();
void logo_menu();
void borda();

main()
{
	
	char c;
	int a=10;
	int sair;
		
	SetConsoleTitle("Loja de Bolos - SweetCakes");
	system("mode con:cols=130 lines=35"); //aumenta a tela para 150 colunas e 35 linhas
	
	
	setlocale(LC_ALL,"Portuguese");
	textcolor(5);
	textbackground(15);
	desenho_bolo();

	system("cls"); // limpar/pintar a tela
	textcolor(15); // cor de letra
	textbackground(3); // cor de fundo
	menu(c, a, sair);
	fecha_arqc();
	fecha_arqb();
}

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


void gotoxy(int x, int y)
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void getChar(char nome[], int max, int min)
{
	int aux = 0;
	char letra;
	fflush(stdin);
	while((letra = getch()) != '\r' || aux < min)
	{
		if((letra == 8 || aux > max) && aux != 0)
		{
			aux--;
			nome[aux] = ' ';
			printf("\b \b");
		}
		if((isalpha(letra) || letra == ' ')&& aux < max)
		{
			nome[aux] = letra;
			aux++;
			printf("%c", letra);
		}
		fflush(stdin);
	}
}



//*abrindo o arquivo do cliente*
void abrir_arq_c()
{
	//fp_c= fopen("cliente.bin", "ab+");
	if((fp_c= fopen("cliente.bin", "ab+")) == NULL)
	{
		gotoxy(20,20);printf("Falha ao abrir o arquivo :'(");
		exit(1);
	}
}
//*abrindo o arquivo do bolo*
void abrir_arq_b()
{
//	fp_b= fopen("bolo.bin", "ab+");
	if((fp_b= fopen("bolo.bin", "ab+")) == NULL)
	{
		gotoxy(20,20);printf("Falha ao abrir o arquivo :'(");
		exit(1);
	}
}
//*cardapio*
void cardapio()
{	
	borda();
	textcolor(15); // cor de letra
	textbackground(3); // cor de fundo
	gotoxy(60,2);printf("CARDAPIO:");
	gotoxy(60,6);printf("Sabores:");
	gotoxy(60,7);printf("(1)Bolo de morango");
	gotoxy(62,8);printf("Massa branca, recheio de chantilly, morango e suspiros");
	gotoxy(60,9);printf("(2)Bolo de chocolate com morango");
	gotoxy(62,10);printf("Massa preta, recheio de brigadeiro e morango");
	gotoxy(60,11);printf("(3)Bolo de doce de leite com morango");
	gotoxy(62,12);printf("Massa branca, recheio de doce de leite e morango");
	gotoxy(60,13);printf("(4)Bolo de chocolate com avela");
	gotoxy(62,14);printf("Massa preta, recheio de chocolate com avela");
	gotoxy(60,15);printf("(5)Bolo de brigadeiro");
	gotoxy(62,16);printf("Massa preta, recheio de brigadeiro");
	gotoxy(60,17);printf("(6)Bolo de prestigio");
	gotoxy(62,18);printf("Massa preta, recheio de brigadeiro e coco");
	gotoxy(60,19);printf("(7)Bolo de frutas");
	gotoxy(62,20);printf("Massa branca, recheio de creme paris e frutas");
	gotoxy(60,21);printf("(8)Bolo de laka com oreo");
	gotoxy(62,22);printf("Massa preta, recheio de chocolate branco com oreo");
	gotoxy(60,23);printf("(9)Bolo de doce de leite com paçoca");
	gotoxy(62,24);printf("Massa preta, recheio de doce de leite com pacoca");
	gotoxy(60,25);printf("(10)Bolo de abacaxi com coco");
    printf("\n                                                             Massa branca, recheio de coco com abacaxi"); //arrumamos com espaço e \n (ariane que nos orientou)
	printf("\n\n                                                           Pressione qualquer tecla para realizar o pedido");
	getch();
}
//********************************************************************************
void salva_dados()
{
	textcolor(15); // cor de letra
	textbackground(3); // cor de fundo
	char conf;
	gotoxy(5,25);printf("Confirma os dados para gravacao ? (S/N): ",22);
	do
	{
		gotoxy(35,33); conf = getche();
	}while( conf != 's' && conf != 'S' && conf != 'n' && conf != 'N' );
	fwrite(&cliente, sizeof(cliente), 1, fp_c);
	if( conf == 'n' || conf == 'N' )
	{
		if(fwrite(&cliente, sizeof(cliente), 1, fp_c) != 1)
		{
			gotoxy(5,35);printf("Erro na escrita do arquivo");
		}
	}
	else
	{
		fflush( fp_c );//descarrega o buffer no disco
		gotoxy(5,26);printf("Dados salvos com sucesso!",18);
	}
	//gotoxy(6,27);printf("<<<Pressione enter para voltar.");
	fclose(fp_c);
	getch();
	system("cls");
}

//********************************************************************************
void salva_ped()
{
	textcolor(15); // cor de letra
	textbackground(3); // cor de fundo
	char conf;
	gotoxy(10,15);printf("Confirma os dados para gravacao ? (S/N): ",22);
	do
	{
		gotoxy(10,16); conf = getche();
	}while( conf != 's' && conf != 'S' && conf != 'n' && conf != 'N' );
	fwrite(&bolo, sizeof(bolo), 1, fp_b);
	if( conf == 'n' || conf == 'N' )
	{
		if(fwrite(&bolo, sizeof(bolo), 1, fp_b) != 1)
		{
			gotoxy(10,18);printf("Erro na escrita do arquivo");
		}
	}
	else
	{
		fflush( fp_b );//descarrega o buffer no disco
		gotoxy(8,20);printf("Dados salvos com sucesso!",18);
	}
	gotoxy(10,22);printf("<<<Pressione enter para voltar.");
	getch();
}
//********************************************************************************
void mostra_mascara_registro()
{
	textcolor(15); // cor de letra
	textbackground(3); // cor de fundo
	system("cls");
	borda();
	gotoxy(15,6);printf("Nome:");
	gotoxy(15,5);printf("ID(0 encerra):");
	gotoxy(15,7);printf("Email:");
	gotoxy(15,8);printf("Telefone:");
	gotoxy(24,8);printf("(DD)");
	gotoxy(33,8);printf("-");
	gotoxy(15,9);printf("Data de Nascimento:");
	gotoxy(38,9);printf("/");
	gotoxy(41,9);printf("/");
	gotoxy(15,23);printf("A cada caractere (. - /) pressione enter para preencher os campos corretos");
	textcolor(13+14);
	gotoxy(90,3);printf("°°");
	gotoxy(90,4);printf("°°");
	textcolor(13);
	gotoxy(85,5); printf("°°°°°°°°°°°°");
   	gotoxy(85,6); printf("°°°°°°°°°°°°");
   	gotoxy(85,7); printf("°°°°°°°°°°°°");
	gotoxy(85,8); printf("°°°°°°°°°°°°");
	textcolor(10);
	gotoxy(80,9); printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(80,10);printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(80,11);printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(80,12);printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(80,13);printf("°°°°°°°°°°°°°°°°°°°°°°");
	textcolor(14);
	gotoxy(75,14);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,15);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,16);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,17);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,18);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,19);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	textcolor(15);
	logo();
}

void mostra_registro()
{
	textcolor(0);
	gotoxy(21,5);printf("%s",cliente.nome);
	int aux;
	gotoxy(18,6);printf("%d",cliente.rg);
	cliente.rg = aux;
	gotoxy(18,6);printf("%d",cliente.rg);
	gotoxy(22,7);printf("%s",cliente.email);
	gotoxy(25,8);printf("%s",cliente.telefone.ddd);
	gotoxy(29,8),printf("%s",cliente.telefone.fone);
	gotoxy(34,8);printf("%s",cliente.telefone.fone2);
	gotoxy(36,9);printf("%d",cliente.nasc.dia);
	gotoxy(39,9);printf("%d",cliente.nasc.mes);
	gotoxy(42,9),printf("%d",cliente.nasc.ano);
}


//validação do nasc
int valida_nasc()
{
	textcolor(15); // cor de letra
	textbackground(3); // cor de fundo
	while(cliente.nasc.ano>2018)
	{
		gotoxy(12,15); printf("Data invalida, digite novamente...");
		gotoxy(36,9); printf("  "); 
		gotoxy(39,9); printf("  ");
		gotoxy(42,9); printf("             ");
		gotoxy(36,9); scanf("%d",&cliente.nasc.dia);
		gotoxy(39,9); scanf("%d",&cliente.nasc.mes);
		gotoxy(42,9); scanf("%d",&cliente.nasc.ano);
	}
	while (cliente.nasc.mes<0||cliente.nasc.mes>12)
	{
		gotoxy(12,15); printf("Data invalida, digite novamente...");
		gotoxy(36,9); printf("  "); 
		gotoxy(39,9); printf("  ");
		gotoxy(42,9); printf("            ");
		gotoxy(36,9); scanf("%d",&cliente.nasc.dia);
		gotoxy(39,9); scanf("%d",&cliente.nasc.mes);
		gotoxy(42,9); scanf("%d",&cliente.nasc.ano);
	}
	if(cliente.nasc.mes==1||cliente.nasc.mes==3||cliente.nasc.mes==5||cliente.nasc.mes==7||cliente.nasc.mes==8||cliente.nasc.mes==10||cliente.nasc.mes==12)
	{
		while(cliente.nasc.dia<01||cliente.nasc.dia>31)
		{
			gotoxy(12,15); printf("Data invalida, digite novamente...");
			gotoxy(36,9); printf("  "); 
			gotoxy(39,9); printf("  ");
			gotoxy(42,9); printf("          ");
			gotoxy(36,9); scanf("%d",&cliente.nasc.dia);
			gotoxy(39,9); scanf("%d",&cliente.nasc.mes);
			gotoxy(42,9); scanf("%d",&cliente.nasc.ano);
		}
	}
	if(cliente.nasc.mes==4||cliente.nasc.mes==6||cliente.nasc.mes==9||cliente.nasc.mes==11)
	{
		while(cliente.nasc.dia<01||cliente.nasc.dia>30)
		{
			gotoxy(12,15); printf("Data invalida, digite novamente...");
			gotoxy(36,9); printf("  "); 
			gotoxy(39,9); printf("  ");
			gotoxy(42,9); printf("          ");
			gotoxy(36,9); scanf("%d",&cliente.nasc.dia);
			gotoxy(39,9); scanf("%d",&cliente.nasc.mes);
			gotoxy(42,9); scanf("%d",&cliente.nasc.ano);
		}
	}
	if(cliente.nasc.mes==2)
	{
		while(cliente.nasc.dia<01||cliente.nasc.dia>28)
		{
			gotoxy(12,15); printf("Data invalida, digite novamente...");
			gotoxy(36,9); printf("  "); 
			gotoxy(39,9); printf("  ");
			gotoxy(42,9); printf("           ");
			gotoxy(36,9); scanf("%d",&cliente.nasc.dia);
			gotoxy(39,9); scanf("%d",&cliente.nasc.mes);
			gotoxy(42,9); scanf("%d",&cliente.nasc.ano);
		}   
	}
}

int checar_chave_primaria()
{
	int aux;
	int F; //função verifica se um código digitado já foi gravado no arquivo
	do{
		rewind(fp_c); //reposiciona o ponteiro no início do arquivo
		F=0;
		gotoxy(29,5);aux = getInt(5);
		if (aux==0) 
			break; //Condição de encerramento
		while( (fread( &cliente,sizeof(cliente),1,fp_c) )== 1 && cliente.rg != aux );
		
		if(cliente.rg == aux && cliente.excluido== 'n') 
		{
			F=1;
			gotoxy(25,11);printf("Codigo ja cadastrado! Enter para redigitar.");
			getch();
			gotoxy(25,11);printf("												");
			gotoxy(29,5);printf("          "); //apaga o código da tela
			//gotoxy(29,5);aux = getInt(5);
		}
	
	}while(F==1);
	return aux;
}

int getInt(int limite)
{
	char resp[limite+1];
	int aux = 0;
	char letra;
	fflush(stdin);
	while((letra = getch()) != '\r'){
		if((letra == 8 || aux > limite) && aux != 0){
			aux--;
			resp[aux] = ' ';
			printf("\b \b");
		}
		if(isdigit(letra) && aux != limite){
			resp[aux] = letra;
			aux++;
			printf("%c", letra);
		}
		fflush(stdin);
		if(letra == 27)
			return -1;
	}
	
	return atoi(resp);
}

void registro()
{
	do{
	abrir_arq_c();
	mostra_mascara_registro();
	//fflush(stdin);
	textcolor(0);
	cliente.rg  = checar_chave_primaria();
	if(cliente.rg == 0)
		break;
		
	gotoxy(21,6);getChar(cliente.nome, 38, 1);
	//fflush(stdin);
	gotoxy(22,7);gets(cliente.email);
	gotoxy(25,8);cliente.telefone.ddd = getInt(2);
	gotoxy(29,8);cliente.telefone.fone = getInt(4);
	gotoxy(34,8);cliente.telefone.fone2 = getInt(4);
	gotoxy(36,9);cliente.nasc.dia=getInt(2);
	gotoxy(39,9);cliente.nasc.mes=getInt(2);
	gotoxy(42,9);cliente.nasc.ano=getInt(4);
	cliente.excluido = 'n';
	valida_nasc();
	//fflush(stdin);
	salva_dados();
	}while(cliente.rg != 0);
}

//***********************************************************

void mostra_pedido()
{
	textcolor(15); // cor de letra
	textbackground(3); // cor de fundo
	gotoxy(10,5);printf("No(0 encerra):");
	gotoxy(10,6);printf("Nome do bolo:");
	gotoxy(10,7);printf("Tamanho:");
	textcolor(15);
	gotoxy(6,28);printf("°°°°°°  °°°°°°      ");
	gotoxy(6,29);printf("°°      °°          ");
	gotoxy(6,30);printf("°°°°°°  °°          ");
	gotoxy(6,31);printf("    °°  °°          ");
	gotoxy(6,32);printf("°°°°°°  °°°°°°      ");
}
void pedido()
{	

	do{
	system("cls");
	int a=8;
	borda();
	cardapio();
	mostra_pedido();
	
	gotoxy(25,5);bolo.id = getInt(2);
	if(bolo.id == 0)
		break;
	while(bolo.id<1 || bolo.id>10)
	{
	
		gotoxy(30,5);printf("ID invalido, regite:");
		gotoxy(50,5);scanf("%d", &bolo.id);
		if(bolo.id<1 || bolo.id>10)
		{
			gotoxy(50,5);printf("   ");
			fflush(stdin);
		}
	}
	fflush(stdin);
	gotoxy(23,6);gets(bolo.nome);
	gotoxy(18,7);bolo.tamanho = getche();
	while(bolo.tamanho != 'p' && bolo.tamanho != 'P' && bolo.tamanho != 'm' && bolo.tamanho != 'M' && bolo.tamanho != 'g' && bolo.tamanho != 'G')
	{
			gotoxy(10,8);printf("Tamanho inválido, redigite(p, m ou g): ");
			gotoxy(50,8);bolo.tamanho = getche();
			a++;
	}
	salva_ped();}while(bolo.id !=0);
	system("cls");
}

//funções para o cursor
void cursor (int x) 
{ 
	// mostra ou não o cursor do prompt
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

//função exclusão de dados
void exclui()
{
	system("cls");
	borda();
	int aux_codigo,F;
	long fposicao;
	char conf;
		
		 if((fp_c = fopen("cliente.bin","rb+")) == NULL) 
		{
			gotoxy(18,11);printf("Erro na abertura do arquivo");
		    exit(1);
		}
	do
	{
		mostra_mascara_registro1();
		logo();
		fflush(stdin);
		gotoxy(15,2); printf("Digite o codigo a ser excluido (digite 0 para encerrar): ");
		aux_codigo = getInt(5);
		
		if (aux_codigo!=0)
		{
		 	
		 	
			F = 0;
			rewind(fp_c);
			do
			{
				
				
				if(fread( &cliente,sizeof(cliente),1,fp_c) == 1){
				
				
						if ( cliente.rg == aux_codigo && cliente.excluido =='n' ) //NÃO FOI EXCLUIDO
						{
							
							
							F = 1;
							mostra_registro1();
							fposicao = ftell(fp_c); // guarda a posição do registro atual do arquivo
							gotoxy(25,22); printf("Confirma exclusao ? (S/N): "); 
							fflush(stdin);
							do
							{
							
							
								gotoxy(54,22); conf = getche();
							
							
							}while( conf != 's' && conf != 'S' && conf != 'n' && conf != 'N' );
							
							if( conf == 's' || conf == 'S' )
							{
								
								
								//posiciona o ponteiro do arquivo no registro a ser excluido logicamente
								fseek (fp_c,fposicao-(sizeof(cliente)),SEEK_SET);
								//SEEK_SET - início do arquivo
								cliente.excluido='s';//exclusão logicaa
								fwrite (&cliente,sizeof(cliente),1,fp_c);
								fflush (fp_c);
							
							
							}
						
						
						}
					
				}
			} while ((!F) && (!feof(fp_c)));
			
			
		} 
		if (F==0 && aux_codigo!=0 && aux_codigo != cliente.rg)
		{
			gotoxy(20,15);printf("****** C¢digo nao encontrado ******");
			getch();
		}
	}while(aux_codigo!=0);
}
//**********************************************************************
void mostra_mascara_registro1()
{
	textcolor(15); // cor de letra
	textbackground(3); // cor de fundo
	system("cls");
	borda();
	gotoxy(15,4);printf("ID:");
	gotoxy(15,6);printf("Nome:");
	gotoxy(15,7);printf("Email:");
	gotoxy(15,8);printf("Telefone:");
	gotoxy(24,8);printf("(DD)");
	gotoxy(33,8);printf("-");
	gotoxy(15,9);printf("Data de Nascimento:");
	gotoxy(38,9);printf("/");
	gotoxy(41,9);printf("/");
	gotoxy(15,25);printf("A cada caractere (. - /) pressione enter para preencher os campos corretos");
	textcolor(13+14);
	gotoxy(90,3);printf("°°");
	gotoxy(90,4);printf("°°");
	textcolor(13);
	gotoxy(85,5); printf("°°°°°°°°°°°°");
   	gotoxy(85,6); printf("°°°°°°°°°°°°");
   	gotoxy(85,7); printf("°°°°°°°°°°°°");
	gotoxy(85,8); printf("°°°°°°°°°°°°");
	textcolor(10);
	gotoxy(80,9); printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(80,10);printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(80,11);printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(80,12);printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(80,13);printf("°°°°°°°°°°°°°°°°°°°°°°");
	textcolor(14);
	gotoxy(75,14);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,15);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,16);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,17);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,18);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,19);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	textcolor(15);
}

void mostra_registro1()
{
	textcolor(0);
	gotoxy(18,4);printf("%d",cliente.rg);
	gotoxy(21,6);printf("%s",cliente.nome);
	int aux;
	cliente.rg = aux;
	gotoxy(22,7);printf("%s",cliente.email);
	gotoxy(25,8);printf("%d",cliente.telefone.ddd);
	gotoxy(29,8),printf("%d",cliente.telefone.fone);
	gotoxy(34,8);printf("%d",cliente.telefone.fone2);
	gotoxy(36,9);printf("%d",cliente.nasc.dia);
	gotoxy(39,9);printf("%d",cliente.nasc.mes);
	gotoxy(42,9),printf("%d",cliente.nasc.ano);
}

//***********************************************************************
char consalt(char aux_dia[3], char aux_mes[3], char aux_ano[5])
{
	int d=atoi(aux_dia);//transforma de char para int
	int m=atoi(aux_mes);//biblioteca <stdlib.h>
	int a=atoi(aux_ano);
	textcolor(15); // cor de letra
	textbackground(3); // cor de fundo
	while(a > 2018)
	{
		gotoxy(12,15); printf("Data invalida, digite novamente...");
		gotoxy(36,9); printf("  "); 
		gotoxy(39,9); printf("  ");
		gotoxy(42,9); printf("             ");
		gotoxy(36,9); scanf("%d",&aux_ano);
		gotoxy(39,9); scanf("%d",&aux_mes);
		gotoxy(42,9); scanf("%d",&aux_ano);
	}
	while (m<0||m>12)
	{
		gotoxy(12,15); printf("Data invalida, digite novamente...");
		gotoxy(36,9); printf("  "); 
		gotoxy(39,9); printf("  ");
		gotoxy(42,9); printf("            ");
		gotoxy(36,9); scanf("%d",&d);
		gotoxy(39,9); scanf("%d",&m);
		gotoxy(42,9); scanf("%d",&a);
	}
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
	{
		while(d<01||d>31)
		{
			gotoxy(12,15); printf("Data invalida, digite novamente...");
			gotoxy(36,9); printf("  "); 
			gotoxy(39,9); printf("  ");
			gotoxy(42,9); printf("          ");
			gotoxy(36,9); scanf("%d",&d);
			gotoxy(39,9); scanf("%d",&m);
			gotoxy(42,9); scanf("%d",&a);
		}
	}
	if(m==4||m==6||m==9||m==11)
	{
		while(d<01||d>30)
		{
			gotoxy(12,15); printf("Data invalida, digite novamente...");
			gotoxy(36,9); printf("  "); 
			gotoxy(39,9); printf("  ");
			gotoxy(42,9); printf("          ");
			gotoxy(36,9); scanf("%d",&d);
			gotoxy(39,9); scanf("%d",&m);
			gotoxy(42,9); scanf("%d",&a);
		}
	}
	if(m==2)
	{
		while(d<01||d>28)
		{
			gotoxy(12,15); printf("Data invalida, digite novamente...");
			gotoxy(36,9); printf("  "); 
			gotoxy(39,9); printf("  ");
			gotoxy(42,9); printf("           ");
			gotoxy(36,9); scanf("%d",&d);
			gotoxy(39,9); scanf("%d",&m);
			gotoxy(42,9); scanf("%d",&a);
		}   
	}
}
void digita_dados()
{
	char aux_dia[3],aux_mes[3],aux_ano[5];
	/* o código foi exibido na função mostra_dados(), mas 
	   como é a chave primária não pode ser alterado */
	fflush(stdin);	
	gotoxy(21,6);gets(cliente.nome);
	gotoxy(22,7);gets(cliente.email);
	gotoxy(25,8);cliente.telefone.ddd = getInt(2);
	gotoxy(29,8);cliente.telefone.fone = getInt(4);
	gotoxy(34,8);cliente.telefone.fone2 = getInt(4);
	gotoxy(36,9);gets(aux_dia);//Os campos dia, mes e ano foram definidos como char[...]
	gotoxy(39,9);gets(aux_mes);//para permitir pressionar <enter> na
	gotoxy(42,9);gets(aux_ano);//alteração sem perder o conteúdo dos campos.
	valida_nasc();
	consalt(aux_dia, aux_mes, aux_ano);
	cliente.nasc.dia = atoi(aux_dia);//transforma de char para int
	cliente.nasc.mes = atoi(aux_mes);//biblioteca <stdlib.h>
	cliente.nasc.ano = atoi(aux_ano);		
	
}

//função alteração de dados
void altera()
{
	borda();
	system("cls");
	if((fp_c= fopen("cliente.bin", "rb+")) == NULL)
	{
		gotoxy(20,20);printf("Não há dados no arquivo ou houve falha na abertura :'(");
		getch();
		return;
	}
	stCad cliente_aux;
	int aux_codigo,F;
	long fposicao;
	char conf;
	do{
    gotoxy(18,12); printf("Digite o c¢digo a ser alterado: ");
    aux_codigo=getInt(5);
    if (aux_codigo == 0)
		break;
    F = 0;
    do
    {
		fread(&cliente,sizeof(cliente),1,fp_c);
		if ( aux_codigo == cliente.rg && cliente.excluido == 'n')//SOMENTE SE NÃO FOI EXCLUIDO	
		{
	   		F = 1;
	   		fposicao = ftell(fp_c); //guarda a posição do registro atual do arquivo
	   		system("cls");
	   		mostra_mascara_registro1(); 
	   		cliente_aux = cliente;
	   		mostra_registro1();
	   	//	aux_codigo = cliente.rg;//salva os dados do registro atual numa estrutura auxiliar
	   		digita_dados();
	   		 cliente.rg=cliente_aux.rg;
			if (cliente.nome[0] == '\x0')//checa se cada campo está vazio
			    strcpy(cliente.nome, cliente_aux.nome);
			if (cliente.email[0] == '\x0')
			    strcpy(cliente.email, cliente_aux.email);
			if (cliente.nasc.dia == 0)
			    cliente.nasc.dia = cliente_aux.nasc.dia;
			if (cliente.nasc.mes == 0)
			    cliente.nasc.mes = cliente_aux.nasc.mes;
			if (cliente.nasc.ano == 0)
			    cliente.nasc.ano = cliente_aux.nasc.ano;
			if (cliente.telefone.ddd == 0)
			    cliente.telefone.ddd == cliente_aux.telefone.ddd;
			if (cliente.telefone.fone == 0)
				cliente.telefone.fone == cliente_aux.telefone.fone;
			if (cliente.telefone.fone2 == 0)
			    cliente.telefone.fone2 == cliente_aux.telefone.fone2;
			   
			
		   	gotoxy(25,22); printf("Confirma alteracao ? (S/N): ");
		   	do 
		   	{
		    	gotoxy(54,22); conf = getche();
		   	}while( conf != 's' && conf != 'S' &&
			   conf != 'n' && conf != 'N' );
		   
		   	if( conf == 's' || conf == 'S' )
		   	{
		   		//posiciona o ponteiro do arquivo no registro alterado
				fseek (fp_c,fposicao-(sizeof(cliente)),SEEK_SET);//em stdio.h
				
				if(fwrite (&cliente,sizeof(cliente),1,fp_c)==1)
				{
					fflush (fp_c);
					gotoxy(10,26);printf("Dados alterados com sucesso!");
					getch();	
				}
				
		   	}
		}
	}  while ((!F) && (!feof(fp_c))); //enquanto F for diferente de 1 e não for o fim do arquivo
	}while (aux_codigo != 0);
	if (F==0)
	{
		gotoxy(18,15);printf("****** C¢digo nao encontrado ******");
		getch();
	} 	
}
void tabela()
{
	setlocale(LC_ALL, "C");
	borda();
	int x0=5;textcolor(15);
	gotoxy(23,4);printf("°°°°°°°  °°°°°°°  °°°   °°  °°°°°°°°  °°    °°  °°    °°°°°°°°°  °°°°°°°° ");
	gotoxy(23,5);printf("°°       °°   °°  °°°°  °°  °°        °°    °°  °°        °      °°    °° ");
	gotoxy(23,6);printf("°°       °°   °°  °° °° °°  °°°°°°°°  °°    °°  °°        °      °°°°°°°° ");
	gotoxy(23,7);printf("°°       °°   °°  °° °° °°        °°  °°    °°  °°        °      °°    °° ");
	gotoxy(23,8);printf("°°°°°°°  °°°°°°°  °°  °°°°  °°°°°°°°  °°°°°°°°  °°°°°°°   °      °°    °° ");
	textcolor(15);
	gotoxy(x0,10);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(x0,11);printf("°         NOME                         °   ID   °               EMAIL                         °   TEL    °    NASC    °");
	gotoxy(x0,12);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(x0,13);printf("°                                      °        °                                             °          °            °");
	gotoxy(x0,14);printf("°                                      °        °                                             °          °            °");
	gotoxy(x0,15);printf("°                                      °        °                                             °          °            °");
	gotoxy(x0,16);printf("°                                      °        °                                             °          °            °");
	gotoxy(x0,17);printf("°                                      °        °                                             °          °            °");
	gotoxy(x0,18);printf("°                                      °        °                                             °          °            °");
	gotoxy(x0,19);printf("°                                      °        °                                             °          °            °");
	gotoxy(x0,20);printf("°                                      °        °                                             °          °            °");
	gotoxy(x0,21);printf("°                                      °        °                                             °          °            °");
	gotoxy(x0,22);printf("°                                      °        °                                             °          °            °");
	gotoxy(x0,23);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	setlocale(LC_ALL, "C");
}
//função de consulta
void consulta_cad()
{
	system("cls");
	gotoxy(1,1);printf("Pressione qualquer tecla para continuar e ESC para sair.");
	fclose(fp_c);//Fecha o arquivo	
	int lin = 13;
	tabela();
	if((fp_c = fopen("cliente.bin", "rb")) == NULL) /* Abre o arquivo novamente para leitura */
	{
	    gotoxy(18,11);printf("Nao ha dados cadastrados");
	    fflush(stdin);
		getch();
		return;//exit(1);
	}
	while( !feof(fp_c) )
	{
		if(fread(&cliente, sizeof(cliente), 1, fp_c) == 1)
		{
			if(lin>22)
			{
				int r= getche();
				system("cls");
				tabela();
				if (r==27)
					break;
				lin=13;
			}
			gotoxy(7,lin);printf("%s",cliente.nome);
			gotoxy(46,lin);printf("%d",cliente.rg);
			gotoxy(55,lin);printf("%s",cliente.email);
			gotoxy(100,lin);printf("%d",cliente.telefone.ddd);
			gotoxy(102,lin);printf("%d",cliente.telefone.fone);
			gotoxy(106,lin);printf("%d",cliente.telefone.fone2);
			gotoxy(112,lin);printf("%d",cliente.nasc.dia);
			gotoxy(114,lin);printf("/%d",cliente.nasc.mes);
			gotoxy(117,lin);printf("/%d",cliente.nasc.ano);
			lin++;
		}		
	}
	int r= getche();		
	fclose(fp_c);
	abrir_arq_c();
}
//tabela para consulta por nome
void tabela_n()
{
	setlocale(LC_ALL, "C");
	gotoxy(8,4);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(8,5);printf("°   Registros encontrados: °");
	
	int x4=35;
	gotoxy(x4,5);printf("°");
	gotoxy(9,6);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(x4,7);printf("°");
	gotoxy(x4,8);printf("°");
	gotoxy(x4,9);printf("°");
	gotoxy(x4,10);printf("°");
	gotoxy(x4,11);printf("°");
	gotoxy(x4,12);printf("°");
	gotoxy(x4,13);printf("°");
	gotoxy(x4,14);printf("°");
	gotoxy(x4,15);printf("°");
	gotoxy(x4,16);printf("°");
	gotoxy(x4,17);printf("°");
	gotoxy(x4,18);printf("°");
	gotoxy(x4,19);printf("°");
	gotoxy(x4,20);printf("°");
	gotoxy(x4,21);printf("°");
	gotoxy(x4,22);printf("°");
	gotoxy(x4,23);printf("°");
	gotoxy(x4,24);printf("°");
	gotoxy(x4,25);printf("°");
	gotoxy(9,25);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(x4,5);printf("°");
	gotoxy(8,6);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	int x5=8;
	gotoxy(x5,7);printf("°");
	gotoxy(x5,8);printf("°");
	gotoxy(x5,9);printf("°");
	gotoxy(x5,10);printf("°");
	gotoxy(x5,11);printf("°");
	gotoxy(x5,12);printf("°");
	gotoxy(x5,13);printf("°");
	gotoxy(x5,14);printf("°");
	gotoxy(x5,15);printf("°");
	gotoxy(x5,16);printf("°");
	gotoxy(x5,17);printf("°");
	gotoxy(x5,18);printf("°");
	gotoxy(x5,19);printf("°");
	gotoxy(x5,20);printf("°");
	gotoxy(x5,21);printf("°");
	gotoxy(x5,22);printf("°");
	gotoxy(x5,23);printf("°");
	gotoxy(x5,24);printf("°");
	gotoxy(x5,25);printf("°");
	setlocale(LC_ALL, "C");
		textcolor(13+14);
	gotoxy(90,3);printf("°°");
	gotoxy(90,4);printf("°°");
	textcolor(13);
	gotoxy(85,5); printf("°°°°°°°°°°°°");
   	gotoxy(85,6); printf("°°°°°°°°°°°°");
   	gotoxy(85,7); printf("°°°°°°°°°°°°");
	gotoxy(85,8); printf("°°°°°°°°°°°°");
	textcolor(10);
	gotoxy(80,9); printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(80,10);printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(80,11);printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(80,12);printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(80,13);printf("°°°°°°°°°°°°°°°°°°°°°°");
	textcolor(14);
	gotoxy(75,14);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,15);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,16);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,17);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,18);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(75,19);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	textcolor(15);
	gotoxy(85,21);printf("°°°°°°  °°°°°°      ");
	gotoxy(85,22);printf("°°      °°          ");
	gotoxy(85,23);printf("°°°°°°  °°          ");
	gotoxy(85,24);printf("    °°  °°          ");
	gotoxy(85,25);printf("°°°°°°  °°°°°°      ");
}

//consulta por pesquisa
void consultacad_nome()
{
	system("cls");
	fclose(fp_c);//Fecha o arquivo
	borda();
	char pes[40];
	int lin = 7;
	gotoxy(3,2);printf("Digite o nome/caractere que deseja pesquisar:");
	gets(pes);
	if((fp_c = fopen("cliente.bin", "rb")) == NULL) /* Abre o arquivo novamente para leitura */
	{
	    gotoxy(18,11);printf("Nao ha dados cadastrados");
	    fflush(stdin);
		getch();
		return;//exit(1);
	}
	while( !feof(fp_c) )
	{
		if(fread(&cliente, sizeof(cliente), 1, fp_c) == 1 && cliente.excluido=='n')
		{
			strlwr(cliente.nome);
    		strlwr(pes);
    		if(strstr(cliente.nome,pes) == NULL)
			{
				gotoxy(2,lin);printf("Nao ha o respectivo registro.");
			}
			else if(strstr(cliente.nome,pes) != NULL)
			{
				tabela_n();
				gotoxy(10,lin);printf("-%s", cliente.nome);
				lin++;
			}
		}		
	}
	gotoxy(1,30); printf("Digite qualquer tecla para voltar ao menu.");
	int r= getche();		
	fclose(fp_c);
	abrir_arq_c();
}
//tabela id
void tabela_id()
{
	setlocale(LC_ALL, "C");
	int x=8;
	gotoxy(x,5);printf("°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(x,6);printf("°  IDs Encontrados     °");
	gotoxy(x,7);printf("°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(x,8);printf("°                      °");
	gotoxy(x,9);printf("°                      °");
	gotoxy(x,10);printf("°                      °");
	gotoxy(x,11);printf("°                      °");
	gotoxy(x,12);printf("°                      °");
	gotoxy(x,13);printf("°                      °");
	gotoxy(x,14);printf("°                      °");
	gotoxy(x,15);printf("°                      °");
	gotoxy(x,16);printf("°                      °");
	gotoxy(x,17);printf("°                      °");
	gotoxy(x,18);printf("°                      °");
	gotoxy(x,19);printf("°                      °");
	gotoxy(x,20);printf("°                      °");
	gotoxy(x,21);printf("°                      °");
	gotoxy(x,22);printf("°                      °");
	gotoxy(x,23);printf("°                      °");
	gotoxy(x,24);printf("°                      °");
	gotoxy(x,25);printf("°°°°°°°°°°°°°°°°°°°°°°°°");
	setlocale(LC_ALL, "C");
}
void consultacad_id()
{
	system("cls");
	system("cls");
	fclose(fp_c);//Fecha o arquivo
	borda();
	int pes;
	int lin = 7;
	gotoxy(3,2);printf("Digite o ID que deseja pesquisar:");
	scanf("%d", &pes);
	cliente.rg = getInt(5);
	fflush(stdin);
	if((fp_c = fopen("cliente.bin", "rb")) == NULL) /* Abre o arquivo novamente para leitura */
	{
	    gotoxy(18,11);printf("Nao ha dados cadastrados");
	    fflush(stdin);
		getch();
		return;//exit(1);
	}
	while( !feof(fp_c) )
	{
		if(fread(&cliente, sizeof(cliente), 1, fp_c) == 1 && cliente.excluido=='n')
		{
    		if(cliente.rg == pes)
    		{
					tabela_id();
					gotoxy(10,lin);printf("%d", cliente.rg);
					lin++;
			
			}
			else if(cliente.rg!= pes)
			{
				gotoxy(2,lin);printf("Nao ha o respectivo registro.");
			}
		}		
	}
	gotoxy(1,30); printf("Digite qualquer tecla para voltar ao menu.");
	int r= getche();		
	fclose(fp_c);
	abrir_arq_c();
}
//tabela consulta ped
void tabelap()
{
	setlocale(LC_ALL, "C");
	borda();
	gotoxy(2,4);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(2,6);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(2,25);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	int x=2;
	gotoxy(x,5);printf("°");
	gotoxy(x,6);printf("°");
	gotoxy(x,7);printf("°");
	gotoxy(x,8);printf("°");
	gotoxy(x,9);printf("°");
	gotoxy(x,10);printf("°");
	gotoxy(x,11);printf("°");
	gotoxy(x,12);printf("°");
	gotoxy(x,13);printf("°");
	gotoxy(x,14);printf("°");
	gotoxy(x,15);printf("°");
	gotoxy(x,16);printf("°");
	gotoxy(x,17);printf("°");
	gotoxy(x,18);printf("°");
	gotoxy(x,19);printf("°");
	gotoxy(x,20);printf("°");
	gotoxy(x,21);printf("°");
	gotoxy(x,22);printf("°");
	gotoxy(x,23);printf("°");
	gotoxy(x,24);printf("°");
	gotoxy(x,25);printf("°");
	x=63;
	gotoxy(x,5);printf("°");
	gotoxy(x,6);printf("°");
	gotoxy(x,7);printf("°");
	gotoxy(x,8);printf("°");
	gotoxy(x,9);printf("°");
	gotoxy(x,10);printf("°");
	gotoxy(x,11);printf("°");
	gotoxy(x,12);printf("°");
	gotoxy(x,13);printf("°");
	gotoxy(x,14);printf("°");
	gotoxy(x,15);printf("°");
	gotoxy(x,16);printf("°");
	gotoxy(x,17);printf("°");
	gotoxy(x,18);printf("°");
	gotoxy(x,19);printf("°");
	gotoxy(x,20);printf("°");
	gotoxy(x,21);printf("°");
	gotoxy(x,22);printf("°");
	gotoxy(x,23);printf("°");
	gotoxy(x,24);printf("°");
	gotoxy(x,25);printf("°");
	x=12;
	gotoxy(5,5);printf("ID");
	gotoxy(x,5);printf("°");
	gotoxy(x,6);printf("°");
	gotoxy(x,7);printf("°");
	gotoxy(x,8);printf("°");
	gotoxy(x,9);printf("°");
	gotoxy(x,10);printf("°");
	gotoxy(x,11);printf("°");
	gotoxy(x,12);printf("°");
	gotoxy(x,13);printf("°");
	gotoxy(x,14);printf("°");
	gotoxy(x,15);printf("°");
	gotoxy(x,16);printf("°");
	gotoxy(x,17);printf("°");
	gotoxy(x,18);printf("°");
	gotoxy(x,19);printf("°");
	gotoxy(x,20);printf("°");
	gotoxy(x,21);printf("°");
	gotoxy(x,22);printf("°");
	gotoxy(x,23);printf("°");
	gotoxy(x,24);printf("°");
	gotoxy(x,25);printf("°");
	
	int x2=43;
	gotoxy(16,5);printf("Nome do Bolo");
	gotoxy(x2,5);printf("°");
	gotoxy(x2,6);printf("°");
	gotoxy(x2,7);printf("°");
	gotoxy(x2,8);printf("°");
	gotoxy(x2,9);printf("°");
	gotoxy(x2,10);printf("°");
	gotoxy(x2,11);printf("°");
	gotoxy(x2,12);printf("°");
	gotoxy(x2,13);printf("°");
	gotoxy(x2,14);printf("°");
	gotoxy(x2,15);printf("°");
	gotoxy(x2,16);printf("°");
	gotoxy(x2,17);printf("°");
	gotoxy(x2,18);printf("°");
	gotoxy(x2,19);printf("°");
	gotoxy(x2,20);printf("°");
	gotoxy(x2,21);printf("°");
	gotoxy(x2,22);printf("°");
	gotoxy(x2,23);printf("°");
	gotoxy(x2,24);printf("°");
	gotoxy(x2,25);printf("°");
	
	gotoxy(45,5);printf("Tamanho do Bolo");
	setlocale(LC_ALL, "C");
}

//consulta geral
void consulta_ped()
{
	system("cls");
	fclose(fp_b);//Fecha o arquivo
	tabelap();
	int lin = 7;
	if((fp_b = fopen("bolo.bin", "rb")) == NULL) /* Abre o arquivo novamente para leitura */
	{
	    gotoxy(18,2);printf("Nao ha dados cadastrados");
	    fflush(stdin);
		getch();
		return;//exit(1);
	}
	while( !feof(fp_b) )
	{
		if(fread(&bolo, sizeof(bolo), 1, fp_b) == 1)
		{
			if(lin>15)
			{
				gotoxy(21,20); printf("Digite qualquer tecla para continuar ou ESC para sair.");
				int r= getche();
				if (r==27)
					break;
				lin=7;
				system("cls");
				tabelap();
			}
			gotoxy(5,lin);printf("%d", bolo.id);
			fflush(stdin);
			gotoxy(15,lin);printf("%s", bolo.nome);
			gotoxy(46,lin);printf("%c", bolo.tamanho);
			lin++;
		}		
	}
	gotoxy(1,1); printf("Digite qualquer tecla para voltar ao menu.");
	int r= getche();		
	fclose(fp_c);
	abrir_arq_c();
}
//tabela ped nome
void tabela_pedn()
{
	setlocale(LC_ALL, "C");
	int x=8;
	gotoxy(x,5);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(x,6);printf("°        Bolos Encontrados       °");
	gotoxy(x,7);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(x,8);printf("°                                °");
	gotoxy(x,9);printf("°                                °");
	gotoxy(x,10);printf("°                                °");
	gotoxy(x,11);printf("°                                °");
	gotoxy(x,12);printf("°                                °");
	gotoxy(x,13);printf("°                                °");
	gotoxy(x,14);printf("°                                °");
	gotoxy(x,15);printf("°                                °");
	gotoxy(x,16);printf("°                                °");
	gotoxy(x,17);printf("°                                °");
	gotoxy(x,18);printf("°                                °");
	gotoxy(x,19);printf("°                                °");
	gotoxy(x,20);printf("°                                °");
	gotoxy(x,21);printf("°                                °");
	gotoxy(x,22);printf("°                                °");
	gotoxy(x,23);printf("°                                °");
	gotoxy(x,24);printf("°                                °");
	gotoxy(x,25);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	setlocale(LC_ALL, "C");
}
//consulta de pedidos por pesquisa
void consultaped_nome()
{
	system("cls");

	fclose(fp_b);//Fecha o arquivo
	char pes[20];
	int lin = 7;
	gotoxy(3,2);printf("Digite o nome/caractere do bolo que deseja pesquisar:");
	gets(pes);
	if((fp_b = fopen("bolo.bin", "rb")) == NULL) /* Abre o arquivo novamente para leitura */
	{
	    gotoxy(18,11);printf("Nao ha dados cadastrados");
	    fflush(stdin);
		getch();
		return;//exit(1);
	}
	while( !feof(fp_b) )
	{
		if(fread(&bolo, sizeof(bolo), 1, fp_b) == 1)
		{
			strlwr(bolo.nome);
    		strlwr(pes);
    		if(strstr(bolo.nome,pes) == NULL)
    		{
				gotoxy(10,lin+1);printf("Nao ha o respectivo registro.");
			}
			else if(strstr(bolo.nome,pes) != NULL)
			{
				tabela_pedn();
				gotoxy(10,lin);printf("-%s", bolo.nome);
				lin++;
			}
		}		
	}
	gotoxy(9,lin+1);printf("                                       ");
	gotoxy(1,30); printf("Digite qualquer tecla para voltar ao menu.");
	int r= getche();		
	fclose(fp_c);
	abrir_arq_c();
}
void tabpedid()
{
	setlocale(LC_ALL, "C");
	int x=8;
	gotoxy(x,5);printf("°°°°°°°°°°°°°°°°°");
	gotoxy(x,6);printf("°IDs Encontrados°");
	gotoxy(x,7);printf("°°°°°°°°°°°°°°°°°");
	gotoxy(x,8);printf("°               °");
	gotoxy(x,9);printf("°               °");
	gotoxy(x,10);printf("°               °");
	gotoxy(x,11);printf("°               °");
	gotoxy(x,12);printf("°               °");
	gotoxy(x,13);printf("°               °");
	gotoxy(x,14);printf("°               °");
	gotoxy(x,15);printf("°               °");
	gotoxy(x,16);printf("°               °");
	gotoxy(x,17);printf("°               °");
	gotoxy(x,18);printf("°               °");
	gotoxy(x,19);printf("°               °");
	gotoxy(x,20);printf("°               °");
	gotoxy(x,21);printf("°               °");
	gotoxy(x,22);printf("°               °");
	gotoxy(x,23);printf("°               °");
	gotoxy(x,24);printf("°               °");
	gotoxy(x,25);printf("°°°°°°°°°°°°°°°°°");
	setlocale(LC_ALL, "C");
}
void consultaped_id()
{
	
	if((fp_b = fopen("bolo.bin", "rb")) == NULL) /* Abre o arquivo novamente para leitura */
	{
	    gotoxy(18,11);printf("Nao ha dados cadastrados");
	    fflush(stdin);
		getch();
		return;//exit(1);
	}
	system("cls");	
	int pes=0;
	cursor(1);
	int lin =8;
	int idbolo;
	
	gotoxy(3,2);printf("Digite o ID do bolo que deseja pesquisar:");
	scanf("%d",&idbolo);
	
	cursor(0);
	
	int cont=0;
	
	rewind(fp_b);
	
	while( !feof(fp_b) )
	{
		if(fread(&bolo, sizeof(bolo), 1, fp_b) == 1)
		{
			if(idbolo == bolo.id)
			{
				tabpedid();
				
				gotoxy(10,lin);printf("-%d", bolo.id);
				
				lin++;
				
				cont++;
			}
		}
	}
	
	
		if(cont==0)
		{
			gotoxy(2,lin);printf("Nao ha o respectivo registro.");
		}
	
	
	//gotoxy(1,lin+1);printf("                                                               ");
	gotoxy(1,30); printf("Digite qualquer tecla para voltar ao menu.");
	int r= getche();	
	system("cls");	
	fclose(fp_c);
	abrir_arq_c();
}
//submenu para consulta
void submenu_cad()
{
	borda();
	char c;
	int a=10;
	int sair;
	do{
		cursor(0);//oculta cursor
		sair=1;
		borda();
		textcolor(15);textcolor(13);
		gotoxy(23,4);printf("°°°°°°°  °°°°°°°  °°°   °°  °°°°°°°°  °°    °°  °°    °°°°°°°°°  °°°°°°°° ");
		gotoxy(23,5);printf("°°       °°   °°  °°°°  °°  °°        °°    °°  °°        °      °°    °° ");
		gotoxy(23,6);printf("°°       °°   °°  °° °° °°  °°°°°°°°  °°    °°  °°        °      °°°°°°°° ");
		gotoxy(23,7);printf("°°       °°   °°  °° °° °°        °°  °°    °°  °°        °      °°    °° ");
		gotoxy(23,8);printf("°°°°°°°  °°°°°°°  °°  °°°°  °°°°°°°°  °°°°°°°°  °°°°°°°   °      °°    °° ");
		textcolor(15);
		gotoxy(12,10);printf("Consulta Geral");
		gotoxy(12,12);printf("Consulta por Nome");
		gotoxy(12,14);printf("Consulta por ID");
		gotoxy(12,16);printf("Pressione espaço para voltar ao menu."); 
		
		gotoxy(11,a); printf("%c", 62);//62 é o caractere '>'
		fflush (stdin);
		c=getch();
		gotoxy(11,a); printf(" ");
		
		switch(c)
		{
			case 72 : //seta para cima
				a-=2;
				if(a<10)
				{
					a=14;	
				}
				gotoxy(14,a); printf("%c", 62);
				break;
			case 80 : //seta para baixo
				a+=2;
				if(a>14)
				{
					a=10;
				}
				gotoxy(8,a); printf("%c", 62);
				break;
			case 32 :
				menu(c, a, sair);
				break;
		}
		fflush(stdin);
		switch(c)//Quando teclar enter para escolher opção
		{
			case 13: //teclou enter
				if(a==10)
				{
					gotoxy(20,15);printf("                           ");
					cursor(1);
					consulta_cad();
				}
				else
				if(a==12)
				{
					gotoxy(20,15);printf("                           ");
					cursor(1);
					consultacad_nome();
				}
				else
				if(a==14)
				{
					gotoxy(20,15);printf("                           ");
					cursor(1);
					consultacad_id();
				}
		}
	}while(sair);
	cursor(1);//mostrar cursor
	gotoxy(10,28);printf("Nao tecle nada, aguarde a pausa...");
}

//submenu para consulta de pedidos
void submenu_ped()
{
	borda();
	logo();
	char c;
	int a=5;
	int sair;
	do{
		cursor(0);//oculta cursor
		sair=1;
		//gotoxy(10,2);printf("**Consulta de Pedidos**");
		gotoxy(10,5);printf("Consulta Geral");
		gotoxy(10,8);printf("Consulta por Nome");
		gotoxy(10,11);printf("Consulta por ID");
		gotoxy(10,14);printf("Pressione espaço para voltar ao menu."); 
		textcolor(15);textcolor(13);
		gotoxy(23,18);printf("°°°°°°°  °°°°°°°  °°°   °°  °°°°°°°°  °°    °°  °°    °°°°°°°°°  °°°°°°°° ");
		gotoxy(23,19);printf("°°       °°   °°  °°°°  °°  °°        °°    °°  °°        °      °°    °° ");
		gotoxy(23,20);printf("°°       °°   °°  °° °° °°  °°°°°°°°  °°    °°  °°        °      °°°°°°°° ");
		gotoxy(23,21);printf("°°       °°   °°  °° °° °°        °°  °°    °°  °°        °      °°    °° ");
		gotoxy(23,22);printf("°°°°°°°  °°°°°°°  °°  °°°°  °°°°°°°°  °°°°°°°°  °°°°°°°   °      °°    °° ");
		textcolor(15);
		
		gotoxy(8,a); printf("%c", 62);//62 é o caractere '>'
		fflush (stdin);
		c=getch();
		gotoxy(8,a); printf(" ");
		
		switch(c)
		{
			case 72 : //seta para cima
				a-=3;
				if(a<5)
				{
					a=11;	
				}
				gotoxy(14,a); printf("%c", 62);
				break;
			case 80 : //seta para baixo
				a+=3;
				if(a>11)
				{
					a=5;
				}
				gotoxy(8,a); printf("%c", 62);
				break;
			case 32 :
				menu(c, a, sair);
				break;
		}
		fflush(stdin);
		switch(c)//Quando teclar enter para escolher opção
		{
			case 13: //teclou enter
				if(a==5)
				{
					gotoxy(20,15);printf("                           ");
					system("cls");
					cursor(1);
					consulta_ped();
				}
				else
				if(a==8)
				{
					gotoxy(20,15);printf("                           ");
					system("cls");
					cursor(1);
					consultaped_nome();
				}
				else
				if(a==11)
				{
					gotoxy(20,15);printf("                           ");
					system("cls");
					cursor(1);
					consultaped_id();
				}
		}
	}while(sair);
	cursor(1);//mostrar cursor
	gotoxy(10,28);printf("Nao tecle nada, aguarde a pausa...");
}
// função sobre 

void sobre ()
{
	system ("cls");
	borda();
	setlocale(LC_ALL,"Portuguese");
	textcolor(13);
	gotoxy(1,4);printf ("\r\tA EMPRESA:");
	textcolor(15);
	gotoxy(1,5);printf("\t\tUma boleria, chamada Sweet Cake, criada no dia 23/08/2018");
	gotoxy(1,6);printf("\t\tNosso objetivo é trazer felicidade à vida das pessoas, deixando-a mais doce");
	textcolor(13);
	gotoxy(1,8);printf("\tPROPRIETÁRIAS:");
	textcolor(15);
	gotoxy(1,9);printf("\t\tAmanda Fayad Mainini (nº03)");
	gotoxy(1,10);printf("\t\tAna Julia Marcelino Ticianeli (nº04)");
	gotoxy(1,11);printf("\t\tBruna Pereira Aguirre (nº06)");
	textcolor(13);
	gotoxy(1,14);printf("\tPROFESSORA ORIENTADORA: "); //linda maravilhosa rainha deusa fada 
	textcolor(15);
	gotoxy(24,15);printf("Ariane Scarelli");
	textcolor(13);
	gotoxy(1,17);printf("\tMAIS INFORMAÇÕES: ");
	textcolor(15);
	gotoxy(1,18);printf("\tA empresa localiza-se na cidade de Bauru, no Colégio Técnico Industrial - CTI.");
	textcolor(13);
	gotoxy(1,19);printf("\t\tTELEFONE PARA CONTATO:");
	textcolor(15);
	gotoxy(30,20);printf("3273-9266");
	textcolor(13);
	gotoxy(1,22);printf("\t\t<3 Um trabalho desenvovido com muito amor, assim como um pedaço fresquinho de bolo <3");
	setlocale(LC_ALL, "C");
	textcolor(12+15);
	gotoxy(22,27);printf("  %c%c%c%c%c%c   %c%c    %c%c  %c%c%c%c%c%c%c  %c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c %c%c%c%c%c%c%c  %c%c   %c%c %c%c%c%c%c%c%c   ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(22,28);printf("  %c%c       %c%c    %c%c  %c%c       %c%c          %c%c         %c%c      %c%c   %c%c  %c%c  %c%c  %c%c        ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(22,29);printf("  %c%c%c%c%c%c%c  %c%c %c%c %c%c  %c%c%c%c%c%c%c  %c%c%c%c%c%c%c     %c%c         %c%c      %c%c%c%c%c%c%c  %c%c%c%c%c   %c%c%c%c%c%c%c   ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(22,30);printf("       %c%c  %c%c%c  %c%c%c  %c%c       %c%c          %c%c         %c%c      %c%c   %c%c  %c%c  %c%c  %c%c        ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(22,31);printf("  %c%c%c%c%c%c%c  %c%c    %c%c  %c%c%c%c%c%c%c  %c%c%c%c%c%c%c     %c%c         %c%c%c%c%c%c%c %c%c   %c%c  %c%c   %c%c %c%c%c%c%c%c%c   ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	textcolor(15);
	gotoxy(50,34);printf("Enter para sair.");
	getch();
}
//função menu

void menu(char c, int a, int sair)
{
	system("cls");
	do
	{
		cursor(0);//oculta cursor
		sair=1;
		borda();
		textcolor(14);
		gotoxy(22,3);printf("°°°°    °°°°  °°°°°°°°  °°°°   °°  °°    °°");
		gotoxy(22,4);printf("°°°°    °°°°  °°        °° °°  °°  °°    °°");
		gotoxy(22,5);printf("°° °°  °° °°  °°°°°°°°  °°  °° °°  °°    °°");
		gotoxy(22,6);printf("°°  °°°°  °°  °°        °°   °°°°  °°    °°");
		gotoxy(22,7);printf("°°   °°   °°  °°°°°°°°  °°    °°°  °°°°°°°°");
		textcolor(15);
		gotoxy(20,10);printf("Registro de cliente");
		gotoxy(20,12);printf("Pedido");
		gotoxy(20,14);printf("Consulta de clientes");
		gotoxy(20,16);printf("Consulta de pedidos");
		gotoxy(20,18);printf("Alterar dados do cadastro");
		gotoxy(20,20);printf("Excluir dados cadastrados");
		gotoxy(20,22);printf("Sobre");
		gotoxy(20,24);printf("Sair");
		textcolor(13+14);
		gotoxy(90,8);printf("°°");
		gotoxy(90,9);printf("°°");
		textcolor(13);
		gotoxy(85,10); printf("°°°°°°°°°°°°");
	   	gotoxy(85,11); printf("°°°°°°°°°°°°");
	   	gotoxy(85,12); printf("°°°°°°°°°°°°");
		gotoxy(85,13); printf("°°°°°°°°°°°°");
		textcolor(10);
		gotoxy(80,14); printf("°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(80,15);printf("°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(80,16);printf("°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(80,16);printf("°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(80,17);printf("°°°°°°°°°°°°°°°°°°°°°°");
		textcolor(14);
		gotoxy(75,18);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(75,19);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(75,20);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(75,21);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(75,22);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		gotoxy(75,23);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		textcolor(13+14);
		gotoxy(85,25);printf("°°°°°°  °°°°°°      ");
		gotoxy(85,26);printf("°°      °°          ");
		gotoxy(85,27);printf("°°°°°°  °°          ");
		gotoxy(85,28);printf("    °°  °°          ");
		gotoxy(85,29);printf("°°°°°°  °°°°°°      ");
		textcolor(15);
		gotoxy(19,a); printf("%c", 62);//62 é o caractere '>'
		fflush (stdin);
		c=getch();
		gotoxy(8,a); printf(" ");
	
		
		switch(c)
		{
			case 72 : //seta para cima
				a-=2;
				if(a<10)
				{
					a=24;	
				}
				gotoxy(14,a); printf("%c", 62);
				break;
			case 80 : //seta para baixo
				a+=2;
				if(a>24)
				{
					a=10;
				}
			gotoxy(8,a); printf("%c", 62);
				break;
		}
		
		switch(c)//Quando teclar enter para escolher opção
		{
			case 13: //teclou enter
				if(a==10)
				{
					Sleep(1500);
					gotoxy(20,15);printf("                           ");
					cursor(1);
					abrir_arq_c();
					registro();	
				}
				else
				if(a==12)
				{
					Sleep(1500);
					gotoxy(20,15);printf("                           ");
					cursor(1);
					abrir_arq_b();
					pedido();
				}
				else
				if(a==14)
				{
					Sleep(1500);
					gotoxy(20,15);printf("                           ");
					cursor(1);
					submenu_cad();
				}
				else
				if(a==16)
				{
					Sleep(1500);
					gotoxy(20,15);printf("                           ");
					cursor(1);
					submenu_ped();
				}
					else
				if(a==18)
				{
					Sleep(1500);
					gotoxy(20,15);printf("                           ");
					cursor(1);
					altera();
				}
					else
				if(a==20)
				{
					Sleep(1500);
					gotoxy(20,15);printf("                           ");
					cursor(1);
					exclui();
				}
					else
				if(a==22)
				{
					Sleep(1500);
					gotoxy(20,15);printf("							 ");
					cursor(1);
					sobre();
				}
				if(a==24)
				{
					system("cls");
					sair=0;
				}
		}
	}while(sair);
	cursor(1);//mostrar cursor
	gotoxy(10,20);printf("Nao tecle nada, aguarde a pausa...");
}
//*************************************************************************************
void fecha_arqc()
{
	fclose(fp_c);
}

void fecha_arqb()
{
	fclose(fp_b);
}

//*************************************************************************************
void desenho_bolo()
{   	
	setlocale(LC_ALL, "C");
	system("cls");
	textcolor(13+14);
	gotoxy(65,3);printf("°°");
	gotoxy(65,4);printf("°°");
	textcolor(13);
	gotoxy(60,5); printf("°°°°°°°°°°°°");
   	gotoxy(60,6); printf("°°°°°°°°°°°°");
   	gotoxy(60,7); printf("°°°°°°°°°°°°");
	gotoxy(60,8); printf("°°°°°°°°°°°°");
	textcolor(10);
	gotoxy(55,9); printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(55,10);printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(55,11);printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(55,12);printf("°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(55,13);printf("°°°°°°°°°°°°°°°°°°°°°°");
	textcolor(14);
	gotoxy(50,14);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(50,15);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(50,16);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(50,17);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(50,18);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	gotoxy(50,19);printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	textcolor(1);
	gotoxy(22,21);printf("  °°°°°°°  °°    °°  °°°°°°°  °°°°°°°  °°°°°°°°      °°°°°°° °°°°°°°  °°   °° °°°°°°°   ");
	gotoxy(22,22);printf("  °°       °°    °°  °°       °°          °°         °°      °°   °°  °°  °°  °°        ");
	gotoxy(22,23);printf("  °°°°°°°  °° °° °°  °°°°°°°  °°°°°°°     °°         °°      °°°°°°°  °°°°°   °°°°°°°   ");
	gotoxy(22,24);printf("       °°  °°°  °°°  °°       °°          °°         °°      °°   °°  °°  °°  °°        ");
	gotoxy(22,25);printf("  °°°°°°°  °°    °°  °°°°°°°  °°°°°°°     °°         °°°°°°° °°   °°  °°   °° °°°°°°°   ");
	textcolor(1);
	gotoxy(50,27);printf("Pressione enter para comecar...");
	setlocale(LC_ALL, "C");
	getch();
}

void logo()
{
	setlocale(LC_ALL, "C");
	textcolor(15);
	gotoxy(110,28);printf("°°°°°°  °°°°°°      ");
	gotoxy(110,29);printf("°°      °°          ");
	gotoxy(110,30);printf("°°°°°°  °°          ");
	gotoxy(110,31);printf("    °°  °°          ");
	gotoxy(110,32);printf("°°°°°°  °°°°°°      ");
}
void sweet_cake()
{
	setlocale(LC_ALL, "C");
	textcolor(12+15);
	gotoxy(22,29);printf("  °°°°°°°  °°    °°  °°°°°°°  °°°°°°°  °°°°°°°°      °°°°°°° °°°°°°°  °°   °° °°°°°°°   ");
	gotoxy(22,30);printf("  °°       °°    °°  °°       °°          °°         °°      °°   °°  °°  °°  °°        ");
	gotoxy(22,31);printf("  °°°°°°°  °° °° °°  °°°°°°°  °°°°°°°     °°         °°      °°°°°°°  °°°°°   °°°°°°°   ");
	gotoxy(22,32);printf("       °°  °°°  °°°  °°       °°          °°         °°      °°   °°  °°  °°  °°        ");
	gotoxy(22,33);printf("  °°°°°°°  °°    °°  °°°°°°°  °°°°°°°     °°         °°°°°°° °°   °°  °°   °° °°°°°°°   ");
}

void borda()
{
	system("mode con:cols=130 lines=35");
	textcolor(13);
	for (int i=1; i<36; i++)
	{
		gotoxy(1,i); printf("%c", 219);
	}
	for (int a=1; a<131; a++)
	{
		gotoxy(a,35); printf("%c", 219);
	}
	for (int b=35; b>=1; b--)
	{
		gotoxy(130,b); printf("%c", 219);
	}
	for (int n=1; n<131; n++)
	{
		gotoxy(n,1); printf("%c", 219);
	}
	textcolor(15);
}
