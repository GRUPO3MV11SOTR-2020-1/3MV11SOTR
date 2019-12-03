#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> //timespec, nanosleep

#include <misc/timespec_operations.h>

int main(int argc, char** argv)
{
	while (true) {
  	double cuenta = 0;
		struct timespec cuenta_ts;

  	do {
	    printf(
	      "\n"
	      "Alarma (en C)\n"
	      "Activar dentro de cuantos segundos: "
	    );
	    scanf("%lf", &cuenta);
	  } while (cuenta <= 0);

		// convertir cuenta a especificación de tiempo
		double_to_timespec(cuenta, &cuenta_ts);

		// esperar
		nanosleep(&cuenta_ts, NULL);
	  printf("\a\aTranscurrieron %.2lf segundos.\n", cuenta);
	}
	return EXIT_SUCCESS;
}
