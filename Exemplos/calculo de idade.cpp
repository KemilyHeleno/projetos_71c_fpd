//RETURN como encerramento de funcoes
#include<stdio.h>
void calculo(int idade)
{
	int c1;
	if (idade<=0)
	{
		printf("Idade invalida, impossivel calcular!");
		return;
	}
	c1 = idade * 365;
	printf("\nVoce ja viveu %d dias", c1);
	return;
	}
main()
{
	int id;
	printf("Digite sua idade: ");
	scanf("%d",& id);
	calculo(id);
}
