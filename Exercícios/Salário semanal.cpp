#include<stdio.h>
void salario_semanal(int hora, float valor, float *adicional)
{
	if (hora <=40)
	{
		*adicional= valor;
	}
	else if (hora >40 || hora <=60)
	{
		*adicional=(valor/2) + valor;
	}
	else if (hora > 60)
	{
		*adicional =valor+valor;
	}
}
main()
{
	int tempo ;
	float salario, add;
	printf("Total de horas trabalhadas na semana: ");
	scanf("%d",&tempo);
	printf("Valor por hora: ");
	scanf("%f",&salario);
	salario_semanal(tempo, salario, &add);
	printf("\nTotal de horas trabalhadas na semana: %d\nValor por hora: %.2f\nValor do salario semanal apos acrescimo: %.2f", tempo, salario, add);
}
