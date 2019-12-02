#include<stdio.h>
#include<time.h>

int main()
{
time_t now,t;
struct tm* current_time;
int hora,min,seg,hora_actual;
int ho, minute, sec, t_sec, t_total;
int dif,r;


t=time(NULL);
time(&now);

current_time=local(&t);

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

if((hora<ho)||(hora==ho&min<minute)||(hora==ho&&min==minute&&seg<sec))
{
printf("la hora de alarma ya paso\n");
r=1;
}
else
{
t_sec=((hora)*3600)+((min)*60)+(seg);
}


while(dif>=0)
{
  t=time(NULL);
  time(&sec);
  current_time=localtime(&t);
  ho=current_time->tm_hour;
  minute=current_time->tm_min;
  sec=current_time->tm_sec;

hora_actual=(ho*3600)+(minute*60)+sec;
dif=t_sec-hora_actual;
}


if(dif<=0)
{
printf("ALARMA! ALARMA! ALARMA!\n");
}
else if(r==1)
{
printf("vualva a correr el programa");
}

return 0;
}