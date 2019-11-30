#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main ()
{
    time_t tiempo;
    struct tm *hora;
    int h=0, m=0, n=0, i;
    bool stat=0;

    time(&tiempo);
    hora = localtime(&tiempo);

    printf ( "Esta es la hora: %s\n\n", asctime (hora) );
    printf ( "¿A que hora quieres que suene la alarma?: ");
    scanf ("%d %d",&h,&m);

    i=time(NULL);

    for(;;)
    {
        if(time(NULL)!=i && stat!=1)
        {
            system("cls");
            printf ( "%s\n", asctime (hora) );
            i=time(NULL);
        }

        time(&tiempo);
        hora = localtime( &tiempo);

        if((*hora).tm_hour==h && (*hora).tm_min==m && n<10)
        {
            printf("\a");
            printf("DESPIERTA!!\n");
            n++;
            stat=1;
        }
        else if (n==10)
        {
            i=time(NULL);
            while (n==10)
            {
                if (time(NULL)==i+4) n=0;
            }
        }
    }
}
