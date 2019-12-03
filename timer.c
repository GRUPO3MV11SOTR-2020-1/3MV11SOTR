// C implementation of digital clock 
#include <stdio.h> 
#include <time.h>  
// driver code 
int main() 
{ 
time_t seconds,s, val = 1; 
struct tm* current_time; 
int hora,minutos,segundos,hora_actual;
int hour,min,sec,t_sec,tiempo_total;
int p = 0,diferencia;
// time in seconds 
s = time(NULL);
time(&seconds);
  
// to get current time 
current_time = localtime(&s); 
                              
// print time in minutes, 
// hours and seconds 
printf("La hora actual es : %02d:%02d:%02d\n", 
  current_time->tm_hour, 
  current_time->tm_min, 
  current_time->tm_sec); 


printf ("A que hora desea programar su alarma?\n");
printf ("introdusca la hora \n");
scanf ("%02d",&hora);
printf ("introdusca los minutos\n");
scanf ("%02d",&minutos);
printf ("introdusca los segundos\n");
scanf ("%02d",&segundos);

hour = current_time->tm_hour;
min = current_time->tm_min;
sec = current_time->tm_sec;

if ((hora < hour)||(hora == hour && minutos < min )||(hora == hour && minutos == min && segundos < sec ))
{
	printf ("la hora ya paso\n");
	
}
 else 
       {
	     t_sec = ((hora)*3600)+((minutos)*60)+(segundos);
       }


//tiempo_total =  time(&seconds) + t_sec;

while ( diferencia >= 0 )
{
	s=time(NULL);
	time(&seconds);
	current_time=localtime(&s);
	hour = current_time->tm_hour;
	min = current_time->tm_min;
	sec = current_time->tm_sec;
	
	hora_actual = (hour*3600)+(min*60)+sec;
	
	diferencia = t_sec - hora_actual;
        
      //	printf("%d\n",diferencia);
}

if (diferencia  <= 0)
{
	printf("ALARMA!!!!\n");
	printf("ALARMA!!!!\n");
	printf("ALARMA!!!!\n");
    
}

return 0; 
}    
