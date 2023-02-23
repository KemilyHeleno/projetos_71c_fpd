#include<stdio.h>
main()
{
	int codigo;
	printf("Voce digitara o codigo");
	while(true)
	{
		printf("Digite o codigo --> zero encerra");
		scanf("%d",&codigo);
		if(codigo==0)
		break;
	}
}
