#include<stdio.h>
#include<time.h>


int main()
{
	time_t seconds, s;
	struct tm* current_time;
	int hora, min, seg,  hora_actual;
	int ho,minute,sec,t_sec, t_total;
	int dif,r;

//tiempo en segundos

        s=time(NULL);
        time(&seconds);

	//tiempo local
	current_time=localtime(&s);

//imprimiendo la hora
 
       printf("hora actual: %02d:%02d:%02d\n", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
		
       printf("introduzca hora de alarma. ");
       printf("hora: ");
       scanf("%02d",&hora);
       printf("minutos: ");
       scanf("%02d",&min);
       printf("segundos: ");
       scanf("%02d",&seg);

	ho=current_time->tm_hour;
	minute=current_time->tm_min;
	sec=current_time->tm_sec;

//implementacion de if para hora pasada

      if((hora<ho)||(hora==ho&&min<minute)||(hora==ho&&min==minute&&seg<sec))
         {
		 printf("la hora de alarma ya paso\n");
		 r=1;
	 }
      else 
	{
		t_sec=((hora)*3600)+((min)*60)+(seg);
		//dif=t_sec - hora_actual;
	}

//tiempo_total=time(&s)+t_s;
       while(dif>=0)
       {
	       s=time(NULL);
	       time(&sec);
	       current_time=localtime(&s);
	       ho=current_time->tm_hour;
	       minute=current_time->tm_min;
	       sec=current_time->tm_sec;

	  hora_actual=(ho*3600)+(minute*60)+sec;
	  dif= t_sec - hora_actual;
	
       }


       if(dif<=0)
       {
	printf("ALARMA! ALARMA! ALARMA!\n!");
       }
       else if(r==1)
       {
	     printf ("vuelva a correr el programa");
       }

       return 0;
    }
























