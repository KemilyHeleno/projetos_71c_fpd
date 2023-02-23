/*
Exemplo de EXCLUSÃO em um arquivo binário.
Profa. Ariane Scarelli, CTI-Unesp, out-2014
Atualizações: out-2018.
*/
#include <stdio.h>
#include <stdlib.h>
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
	char excluido;// campo para indicar a exclusão lógica
}agenda;

FILE *fp;

void tela_dados(const char parte[30])
{
	clrscr();
	gotoxy(10,2);printf("Cadastro de Pessoas - %s",parte);
	gotoxy(10,5);printf("Codigo: ");	
	gotoxy(10,6);printf("Nome  : ");
	gotoxy(10,7);printf("Sexo  : ");
	gotoxy(25,7);printf("Data nascimento:   /  /");
	gotoxy(10,8);printf("e-mail: ");
}
void mostra_dados()
{
	gotoxy(18,5);printf("%d",agenda.codigo);	
	gotoxy(18,6);puts(agenda.nome);
	gotoxy(18,7);puts(agenda.sexo);
	gotoxy(42,7);printf("%d",agenda.dnasc.dia);
	gotoxy(45,7);printf("%d",agenda.dnasc.mes);
	gotoxy(48,7);printf("%d",agenda.dnasc.ano);
	gotoxy(18,8);puts(agenda.email);
}
void excluir_dados() //exclusao lógica
{
	int aux_codigo,F;
	long fposicao;
	char conf;
	do{	
		tela_dados("EXCLUSŽO");
	    gotoxy(10,12); printf("Digite o c¢digo a ser excluido (digite zero para encerrar): ");
	    scanf("%d", &aux_codigo );
	    if (aux_codigo!=0)
	    {
			F = 0;
			rewind(fp);
		    do
		    {
				fread( &agenda,sizeof(agenda),1,fp);
				if ( agenda.codigo == aux_codigo && agenda.excluido == 'n' ) //SOMENTE SE NÃO FOI EXCLUIDO
				{
			   		F = 1;
			   		fposicao = ftell(fp); // guarda a posição do registro atual do arquivo
			   		mostra_dados(); // um registro nunca pode ser excluído sem antes ser apresentado ao usuário
				   	gotoxy(25,22); printf("Confirma exclusao ? (S/N): ");
				   	// exclusão é uma operação crítica, por isso, sempre será confirmada pelo usuário
					fflush(stdin);
					do 
				   	{
				    	gotoxy(54,22); conf = getche();
				   	}while( conf != 's' && conf != 'S' &&
					   conf != 'n' && conf != 'N' );
				   
				   	if( conf == 's' || conf == 'S' )
				   	{
				   		//posiciona o ponteiro do arquivo no registro a ser excluido logicamente
						fseek (fp,fposicao-(sizeof(agenda)),SEEK_SET); //em stdio.h
						//SEEK_SET indica o início do arquivo
						agenda.excluido='s'; /*atribuição de 's' para o campo excluído para indicar 
							 que o registro foi excluído ou desativado (exclusão lógica) */
						if(fwrite (&agenda,sizeof(agenda),1,fp)==1)
						{
							fflush (fp);
							gotoxy(25,23);printf("Cadastro excluido com sucesso!");
							getch();
						}	
				   	}
				}
			} while ((!F) && (!feof(fp)));  	
		} // if (aux_codigo!=0)
		if (F==0 && aux_codigo!=0)
		{
			gotoxy(20,15);printf("****** C¢digo nao encontrado ******");
			getch();
		}
	}while(aux_codigo!=0);
}
void abrir_arquivo(const char *modo)
{
	if((fp = fopen("arq3.bin", modo)) == NULL) 
	{
		gotoxy(18,11);printf("Erro na abertura do arquivo");
	    exit(1);
	}	
}
main()
{
	abrir_arquivo("rb+"); //modo leitura e escrita, o arquivo deve existir
	excluir_dados();
	clrscr();//limpeza de tela
	gotoxy(18,11);printf("Obrigado por utilizar nosso sistema!");
	getch();
}

