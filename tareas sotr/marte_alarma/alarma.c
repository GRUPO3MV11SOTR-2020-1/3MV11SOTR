/* localtime example */
#include <stdio.h>      /* puts, printf */
#include <time.h>       /* time_t, struct tm, time, localtime */
#include <misc/timespec_operations.h>

#define OFFSET  0 /* -5*3600 */

struct tm * obtener_tiempo_actual();
void loop();

int main ()
{
  while (1) {
    loop();
  }
  return 0;
}

void loop() {
  time_t rawtime_alarma;

  struct tm * tiempoinicial = obtener_tiempo_actual();
  struct tm * tiempoalarma = obtener_tiempo_actual();

  struct timespec ts_1s;
  double_to_timespec(1.0, &ts_1s);

  printf (
    "La hora actual es: %02d:%02d\n",
    tiempoinicial->tm_hour, tiempoinicial->tm_min
  );

  printf("Introduzca el tiempo para que se active la alarma (hh:mm): ");
  scanf("%02d:%02d", &tiempoalarma->tm_hour, &tiempoalarma->tm_min);

  printf(
    "La alarma se activará a las %02d:%02d.\n",
    tiempoalarma->tm_hour, tiempoalarma->tm_min
  );

  tiempoalarma->tm_sec = 0;

  // convertir estructura de tiempo de alarma a tiempo unix
  rawtime_alarma = mktime(tiempoalarma);

  while (1) {
    struct tm *tiempo_actual = obtener_tiempo_actual();
    printf (
      "\rLa hora actual es: %02d:%02d:%02d",
      tiempo_actual->tm_hour, tiempo_actual->tm_min, tiempo_actual->tm_sec
    );

    if ( (rawtime_alarma - mktime(tiempo_actual)) <= 0 ) {
      printf(
        "\n\n"
        "ALARMA ACTIVADA\n"
        "\a\a\a"
      );
      break;
    }

    // delay de 1 segundo
    nanosleep(&ts_1s, NULL);
  }
}

struct tm * obtener_tiempo_actual() {
  time_t rawtime;

  // obtener tiempo unix actual (segundos desde 1 de Enero de 1970)
  // y restar 5 horas (localtime no considera uso horario en MarteOS)
  time (&rawtime);
  rawtime += OFFSET;

  return localtime (&rawtime);
}