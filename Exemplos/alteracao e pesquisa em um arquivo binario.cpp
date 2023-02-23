/*
Exemplo de ALTERAÇÃO e pesquisa em um arquivo binário.
Profa. Ariane Scarelli, CTI-Unesp, out-2014
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
	char excluido;//para a exclusão lógica que interferirá na alteração
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
	gotoxy(18,7);printf("%s",agenda.sexo);
	gotoxy(42,7);printf("%d",agenda.dnasc.dia);
	gotoxy(45,7);printf("%d",agenda.dnasc.mes);
	gotoxy(48,7);printf("%d",agenda.dnasc.ano);
	gotoxy(18,8);puts(agenda.email);
}
void digita_dados()
{
	char aux_dia[3],aux_mes[3],aux_ano[5];
	/* o código foi exibido na função mostra_dados(), mas 
	   como é a chave primária não pode ser alterado */
	fflush(stdin);	
	gotoxy(18,6);gets(agenda.nome);
	gotoxy(18,7);gets(agenda.sexo);
	gotoxy(42,7);gets(aux_dia);//Os campos dia, mes e ano foram definidos como char[...]
	gotoxy(45,7);gets(aux_mes);//para permitir pressionar <enter> na
	gotoxy(48,7);gets(aux_ano);//alteração sem perder o conteúdo dos campos.
	agenda.dnasc.dia = atoi(aux_dia);//transforma de char para int
	agenda.dnasc.mes = atoi(aux_mes);//biblioteca <stdlib.h>
	agenda.dnasc.ano = atoi(aux_ano);
	gotoxy(18,8);gets(agenda.email);	
}
void alterar_dados()
{
	estrut1 agenda_aux; //cria uma estrutura auxiliar
	int aux_codigo,F;
	long fposicao;
	char conf;
	tela_dados("ALTERA€ŽO");
    gotoxy(18,12); printf("Digite o c¢digo a ser alterado: ");
    scanf("%d", &aux_codigo );
    F = 0;
    do
    {
		fread( &agenda,sizeof(agenda),1,fp);
		if ( agenda.codigo == aux_codigo && agenda.excluido=='n')//SOMENTE SE NÃO FOI EXCLUIDO	
		{
	   		F = 1;
	   		fposicao = ftell(fp); //guarda a posição do registro atual do arquivo
	   		mostra_dados();
	   		agenda_aux = agenda;//salva os dados do registro atual numa estrutura auxiliar
	   		digita_dados();
			// ******> VERIFICA SE HOUVE ALTERAÇÃO EM CADA UM DOS CAMPOS
			if (agenda.nome[0] == '\x0')//checa se cada campo está vazio
			    strcpy(agenda.nome, agenda_aux.nome);
			if (agenda.sexo[0] == '\0')//pode usar '\0' ou '\x0'
			    strcpy(agenda.sexo, agenda_aux.sexo);
			if (agenda.dnasc.dia == 0)
			    agenda.dnasc.dia = agenda_aux.dnasc.dia;
			if (agenda.dnasc.mes == 0)
			    agenda.dnasc.mes = agenda_aux.dnasc.mes;
			if (agenda.dnasc.ano == 0)
			    agenda.dnasc.ano = agenda_aux.dnasc.ano;
			if (agenda.email[0] == '\x0')
			    strcpy(agenda.email, agenda_aux.email);
		   	gotoxy(25,22); printf("Confirma alteracao? (S/N): ");
		   	do
		   	{
		    	gotoxy(54,22); conf = getche();
		   	}while( conf != 's' && conf != 'S' &&
			   conf != 'n' && conf != 'N' );
		   
		   	if( conf == 's' || conf == 'S' )
		   	{
		   		//posiciona o ponteiro do arquivo no registro alterado
				fseek (fp,fposicao-(sizeof(agenda)),SEEK_SET);//em stdio.h
				/* fposicao-(sizeof(agenda) significa:
				   >> fposicao: contem a posição onde começa o próximo registro.
				   >> sizeof(agenda): contem o tamanho total em bytes do registro.
				   >> A subtração (-) entre eles significa reposicionar o ponteiro no 
				      início do registro anterior que é onde se deseja alterar.
				*/
				//SEEK_SET indica o início do arquivo
				fwrite (&agenda,sizeof(agenda),1,fp);
				fflush (fp);
		   	}
		}
	} while ((!F) && (!feof(fp))); //enquanto F for diferente de 1 e não for o fim do arquivo
	if (F==0)
	{
		gotoxy(18,15);printf("****** C¢digo nao encontrado ******");
		getch();
	} 	
}
void consultar_dados()
{
	while( !feof(fp) )
	{
		if(fread(&agenda, sizeof(agenda), 1, fp) == 1)  
		{
			if (agenda.excluido=='n')//significa que o registro não foi excluido
			{
				tela_dados("CONSULTA");
				mostra_dados();
				gotoxy(18,11);printf("Pressione uma tecla para continuar...");
				fflush(stdin);
				getch();
			}
		}
	}
	fclose(fp);	
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
	system("TITLE EXEMPLO ARQUIVO BINÁRIO - ALTERAÇÃO E CONSULTA");
	abrir_arquivo("rb+"); //modo leitura e escrita, o arquivo deve existir
	alterar_dados();
	abrir_arquivo("rb"); //modo leitura, o arquivo deve existir
	consultar_dados();
	fclose(fp);
	clrscr();//LIMPEZA DE TELA
	gotoxy(18,11);printf("Obrigado por utilizar nosso sistema!");
	getch();
}

