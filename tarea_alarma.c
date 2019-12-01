#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main(){
	int x;
	float tiempo;
	bool y = true;
	time_t t0;
	time_t t1;
	
	printf("Tarea 2: Alarma \n");
	
	printf("Introduzca la duracion de la alarma en minutos:");
	scanf("%i",&x);
	
	printf("Recibira una mensaje en %i minutos\n",x);
	t0 = time(NULL);	
	
	while(y){
		
		t1 =time(NULL);
		tiempo=t1-t0;
		
		if (tiempo >= x*60){
			y=false;
			}
	
	}
	
	printf("Ha transcurrido %f minutos \n",tiempo/60);
	getchar();
}
