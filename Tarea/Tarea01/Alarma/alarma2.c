#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t now;
struct tm *right_now;

int main()
{
	int horas, minutos;

	printf("Ingresa la hora:");
	scanf("%d",&horas);
	printf("\nIngresa los minutos:");
	scanf("%d",&minutos);
	

	while(1)
	{
		time(&now);
		right_now=localtime(&now);

		if(horas == right_now->tm_hour & minutos == right_now->tm_min)
		{
			printf("\nSe acabo el tiempo");
			break;
		}
	
	}
	return 0;

}
