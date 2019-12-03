#include<stdio.h>
#include<time.h>

int main ()
{
	time_t rawtime;
	struct tm * timeinfo;
	struct tm * tiempoalarma;
	time (&rawtime);
	rawtime -= 5*3600; //Ajuste a la zona horaria.
	timeinfo = localtime(&rawtime);
	tiempoalarma = localtime(&rawtime);  
	//Auxiliar para conocer la alarma en la que va a sonar
	printf("Hora actual: %02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min);
	printf("Introduzca el tiempo para que se active la alarma(hh:mm):");
	scanf("%02d:%02d", 
			&tiempoalarma->tm_hour, 
			&tiempoalarma->tm_min,
			&tiempoalarma->tm_sec);
	return 0;

	//mktime
	//\r Hora actual

}
