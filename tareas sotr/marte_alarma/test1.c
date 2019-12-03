#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

int main(int argc, char** argv)
{
  struct timeval t1, t2;
  double cuenta = 5;

  do {
    printf(
      "\n"
      "Alarma (en C)\n"
      "Activar dentro de cuantos segundos: "
    );
    scanf("%lf", &cuenta);
  } while (cuenta <= 0);

  gettimeofday(&t1, NULL);
  while(true)
  {
    gettimeofday(&t2, NULL);
    if ((t2.tv_sec - t1.tv_sec) >= cuenta)
    {
      printf("\a\aTranscurrieron %.2lf segundos.\n", cuenta);
      break;
    }
  }
  return EXIT_SUCCESS;
}