#include <stdio.h>
#include <time.h>

int main (){
	int h,m,s,ts;
	struct timespec acT, psT;

	printf("Escriba el tiempo que se va temporizar en el formato \n horas minutos segundos \n");
	scanf("%d %d %d",&h,&m,&s);
	/* calculo de cantidad de segundos a contar */

	ts=(h*60*60)+(m*60)+s;
	printf("\n Se contaran %d segundos\n",ts);

	clock_gettime(CLOCK_REALTIME,&acT);
	psT.tv_sec = acT.tv_sec + ts;
	psT.tv_nsec = 0;

	while (acT.tv_sec < psT.tv_sec){

		clock_gettime(CLOCK_REALTIME,&acT);
	}

	printf("\n**************************************************\n");
	printf(" Han pasado %d segundos",ts);
	printf("\n**************************************************\n");

	return 0;
}
