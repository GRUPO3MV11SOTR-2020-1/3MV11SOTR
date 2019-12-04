#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
	time_t tiempo;
	struct tm *hora;
	int h=0, m=0, n=0, i=0;
	bool stat=0;

	time(&tiempo);
	hora=localtime(&tiempo);

	printf("Esta es la hora: %s\n\n", asctime(hora));
	printf("¿A que hora quiere que suene la alarma (hh mm):? \n");
	scanf ("%d %d",&h,&m);
	printf("-------------------------------------------------------");

	i=time(NULL);

	do
	{
		if(time(NULL)!=1 && stat!=1)
		{
			//printf("%s\n", asctime(hora));
			i=time(NULL);
		}	
		time(&tiempo);
		hora=localtime(&tiempo);
		if((*hora).tm_hour==h && (*hora).tm_min==m && n<10 )
		{
			printf("\a");
			printf("ALARMA!!\n");
			n++;
			stat=1;
		}
		else if(n==5)
		{
			i=time(NULL);
			while(n==5)
			{
				if(time(NULL)==i+4) n=0;
			}
		}
	}while(n!=5);
	return 0;
}
