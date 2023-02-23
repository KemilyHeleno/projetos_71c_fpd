#include<stdio.h>
float validacao(float a)
{
	do 
	{
		if (a <=0 || a >=10)
		{
			printf("\nvalor invalido, redigite.\n");
			scanf("%f",&a);
		}
			
	}while(a <=0 || a >=10);
	return a;	
}
main()
{
	float nota;
	printf("Digite a nota: ");
	scanf("%f",&nota);
	nota=validacao(nota);
	printf("nota digitada = %1.f",nota);
}
