#include <stdio.h>
#include <time.h>
#include <stdlib.h>	
#include <unistd.h>


int main ()
{
    time_t tiempo;
    struct tm *hora;
    int h=0, m=0, j=0, n=0, i=0;
    bool stat=0;

    time(&tiempo);
    hora = localtime(&tiempo);

    printf ( "\nEsta es la fecha y hora: %s\n", asctime (hora) );
    printf ( "A que hora quieres que suene la alarma? (h m): ");
    scanf ("%d %d",&h,&m);

    i=time(NULL);

    for(;;)
    {   
    sleep(1);
        if(time(NULL)!=i && stat!=1)
        {
            printf ( "%s\n", asctime (hora) );
            i=time(NULL);
        }

        time(&tiempo);
        hora = localtime( &tiempo);

        if((*hora).tm_hour==h && (*hora).tm_min==m && n<3)
        {
            printf("DESPIERTA!!\n");
            n++;
            stat=1;
        }
        else if (n==3)
        {
            i=time(NULL);
            while (n==3)
            {
                if (time(NULL)==i+4) n=0;
            }
        }
    }
}
