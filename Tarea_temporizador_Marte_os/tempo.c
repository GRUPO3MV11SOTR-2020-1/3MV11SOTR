#include<stdio.h>
#include<time.h>
#include<unistd.h>

int main()
{
	int min=0;
	int n=0;
	int i=0;
	printf("TEMPORIZADOR\n");
	printf("INTRODUCE EL TIEMPO EN MINUTOS");
	scanf("%d",&min);

	while(n<=(60*min))
	{
		sleep(1);
		if(n%60==0)
		{
			i=n/60;			
			printf("%d MINUTOS\n",i);
		}	
		n=n+1;
	}
	printf("TERMINO EL TIEMPO, DESPIERTA!!!");
	return 0;
}

