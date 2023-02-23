/*
Exemplo de CADASTRO e pesquisa em um arquivo binário.
CHECAGEM para não entrar com CHAVE PRIMÁRIA repetida.
Atribuição de valor 'n' para campo EXCLUIDO - Exclusão lógica.
Profa. Ariane Scarelli, CTI-Unesp, out-2014.
Atualizações: out-2018.
*/
#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <conio.c> //para usar funções gotoxy, clrscr, textbackground, textcolor
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
//----------------------------------------------------------------------
void abrir_arquivo(const char modo[])
{
	if((fp = fopen("arq3.bin",modo)) == NULL) 
	{
		gotoxy(18,11);printf("Erro na abertura do arquivo");
	    exit(1);
	}	
}
//----------------------------------------------------------------------
void mensagem(const char MENS[], int lin )
{
	long I;  
	div_t x;
	x = div( ( 80 - strlen( MENS ) ), 2 );
	gotoxy( x.quot, lin); printf("%s", MENS );
	fflush(stdin);
}
//----------------------------------------------------------------------
void tela_dados(const char *parte)
{
	system("cls");
	gotoxy(10,2);printf("Cadastro de Pessoas - %s",parte);
	gotoxy(10,5);printf("Codigo (para encerrar digite 0): ");	
	gotoxy(10,6);printf("Nome  : ");
	gotoxy(10,7);printf("Sexo  : ");
	gotoxy(25,7);printf("Data nascimento:   /  /");
	gotoxy(10,8);printf("e-mail: ");
}
//----------------------------------------------------------------------
int checar_chave_primaria()
{
	int aux_codigo, F;
	//função verifica se um código digitado já foi gravado no arquivo	
	do{
		rewind(fp); //reposiciona o ponteiro no início do arquivo
		F = 0;
		gotoxy(43,5);scanf("%d",&aux_codigo);
		if (aux_codigo==0) 
			break; //Condição de encerramento, quebra o laço
		
	    while( fread( &agenda,sizeof(agenda),1,fp) == 1 )
		{
			if( agenda.codigo == aux_codigo && agenda.excluido=='n')
			{ //o código existe ou o código foi excluído mas já foi recadastrado: continuar percorrendo o arquivo para levar ponteiro para eof.
				F = 1;
			}		
		}/*o arquivo tem que ser percorrido do início ao fim, sempre, para verificar possíveis 
		   inserções da mesma chave primária no final do arquivo e também para que o ponteiro
		   fique em EOF, portanto, pronto para nova inclusão ao final.
		  
		  -->  Correção de lógica no algoritmo de quando se tentava reincluir 
		     um código já deletado!! (Em outubro/2018) <--
	     
		 */
	    if( F == 1 )
		{													
			fflush(stdin);
			mensagem("****** C¢digo j  cadastrado ! ******",22);
			getch();
			gotoxy(10,22);clreol(); // limpa a linha a partir da posição do cursor até o fim
			gotoxy(43,5);printf("          ");//apaga o código da tela
		}

	}while( F == 1 );
	return aux_codigo;
}
//----------------------------------------------------------------------
void digitar_dados()
{
	tela_dados("CADASTRO");
	agenda.codigo=checar_chave_primaria();
	if (agenda.codigo==0) return; //Condição de encerramento
	fflush(stdin);	
	gotoxy(18,6);gets(agenda.nome);
	gotoxy(18,7);gets(agenda.sexo);
	gotoxy(42,7);scanf("%d",&agenda.dnasc.dia);
	gotoxy(45,7);scanf("%d",&agenda.dnasc.mes);
	gotoxy(48,7);scanf("%d",&agenda.dnasc.ano);
	fflush(stdin);
	gotoxy(18,8);gets(agenda.email);
	agenda.excluido = 'n'; /* atribuição de 'n' para o campo excluído para indicar 
							 que o registro acabou de ser inserido */
}
//----------------------------------------------------------------------
void salvar_dados()
{
	char conf;
	mensagem("Confirma os dados para gravacao ? (S/N): ",18);
	do
   	{
       	gotoxy(61,18); conf = getche();
   	}while( conf != 's' && conf != 'S'
		&& conf != 'n' && conf != 'N' );
   	
	if( conf == 's' || conf == 'S' )
   	{
		if(fwrite(&agenda, sizeof(agenda), 1, fp) != 1) 
		{
		    gotoxy(18,11);printf("Erro na escrita do arquivo");
		}
		else
		{
			fflush( fp );//descarrega o buffer no disco
			mensagem("Dados salvos com sucesso!",22);
		}
		getch();	
	}
}
//----------------------------------------------------------------------
void mostrar_dados()
{
	fclose(fp); 
	abrir_arquivo("rb");//para pesquisa, abre-se com modo leitura                                 

	while( !feof(fp) )
	{
		if(fread(&agenda, sizeof(agenda), 1, fp)// == 1 
		    && agenda.excluido=='n')  
		{
			tela_dados("PESQUISA");
			gotoxy(43,5);printf("%d",agenda.codigo);	
			gotoxy(18,6);puts(agenda.nome);
			gotoxy(18,7);printf("%s",agenda.sexo);
			gotoxy(42,7);printf("%d",agenda.dnasc.dia);
			gotoxy(45,7);printf("%d",agenda.dnasc.mes);
			gotoxy(48,7);printf("%d",agenda.dnasc.ano);
			gotoxy(18,8);puts(agenda.email);
			gotoxy(18,11);printf("Pressione uma tecla para continuar...");
			fflush(stdin);
			getch();	
		}
	}
	fclose(fp);
}
//----------------------------------------------------------------------
main()
{
	abrir_arquivo("ab+"); //Leitura e escrita
	do{
		digitar_dados();
		if (agenda.codigo==0) 
			break; //Condição de encerramento
		salvar_dados();		
	}while(true);
	clrscr(); // limpeza de tela
	mensagem("------>Inclusao encerrada!<-------",11);
	getch();
	mostrar_dados();
	clrscr(); // limpeza de tela
	mensagem("Obrigado por utilizar nosso sistema!",11);
	getch();
}


