#include<stdio.h>
#include<time.h>

int main(){
	int hrs,min,sec,tosec;
	struct timespec acTime;
	struct timespec psTime;
	printf("TEMPORIZADOR. Este programa manda una alerta en pantalla cuando haya transcurrido el tiempo que el usuario haya especificado.\n");
	printf("\nEscriba las horas: ");
	scanf("%d",&hrs);
	printf("\nEscriba los minutos: ");
	scanf("%d",&min);
	printf("\nEscriba los segundos: ");
	scanf("%d",&sec);

	//Algoritmo
	tosec=(hrs*3600)+(60*min)+sec;
	printf("\nTiempo a transcurrir en segundos: %d",tosec);
	clock_gettime(CLOCK_REALTIME,&acTime);
	psTime.tv_sec=acTime.tv_sec+tosec;
	psTime.tv_nsec=0;
	while(acTime.tv_sec<psTime.tv_sec)
	{
		clock_gettime(CLOCK_REALTIME,&acTime);
	}
	printf("\n\nTIEMPO AGOTADO");
	return 0;
}
