#include <conio.c>
#include <stdio.h>
main()
{
	puts ( "La la la lalalalalla");
 
	if(getch()==27)
	{}
	else
	{ 
		do 
		{
			puts ("Aperte ESC para sair\n");
			getch();
		}while(getch()!=27); 
	}
}
