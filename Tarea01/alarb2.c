#include<stdio.h>
#include<stdlib.h>
#include<time.h>

time_t now;
struct tm *right_now;

int main()
{

    int hour, minutes;

    printf("Ingrese las Horas:");
    scanf("%d",&hour);
    printf("\nIngrese los Minutos: ");
    scanf("%d",&minutes);

    system("cls");

    while(1)
    {
            time(&now);
            right_now=localtime(&now);

            if(hour == right_now->tm_hour & minutes == right_now->tm_min)
            {
                    printf("\nALARMA ALARMA");
                    printf("\a");
                    break;
             }
    }
    return 0;
}
