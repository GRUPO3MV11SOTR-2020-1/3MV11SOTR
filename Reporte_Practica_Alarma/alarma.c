#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]){

	int tipo=0, cantidad=0;
	int hora,minuto,segundo;
	int t_en_seg=0;     //Tiempo en Segundos

	time_t seconds;         //returns the time since the Epoch (January 1, 1970)
	//-----------------------------------------------------------------------------------
	printf("\n\nSeleccione una de las siguientes opciones para el tiempo de la alarma: \n");
	printf("\n1 para Horas");
	printf("\n2 para Minutos");
	printf("\n3 para Segundos\n");
	printf("\n");
	//------------------------------------------------------------------------------------
	scanf("%d", &tipo);                //Se guarda el tipo de tiempo, horas,min o seg
	//printf("Tipo = %d\n", tipo);
	//------------------------------------------------------------------------------------
	printf("\nDigite la cantidad de tiempo: ");
	scanf("%d", &cantidad);           // se guarda la cantidad de tiempo
	//printf("cantidad= %d\n", cantidad);
	//------------------------------------------------------------------------------------
	if (tipo == 1 ){
		printf("\nSe ha configurado la alarma dentro de %d HORAS\n", cantidad);
	}
	else if (tipo ==2 ){
		printf("\nSe ha configurado la alarma dentro de %d MINUTOS\n", cantidad);
	}
	else if (tipo == 3 ){
		printf("\nSe ha configurado la alarma dentro de %d SEGUNDOS\n", cantidad);
	}
	//------------------------------------------------------------------------------------
			                            	
	                    		
	for(hora=0; hora<=24; hora++){
		for(minuto=0; minuto<60; minuto++){
			for(segundo=0; segundo<60; segundo++){
						                            												
				printf("\n %02i : %02i : %02i ",hora, minuto, segundo);
								
				//--------------------- Ciclo para contar los segundos --------------------------
				seconds = time(NULL);   //Actualiza los segundos
				t_en_seg = seconds+1;
				while(seconds < t_en_seg){//Compara la variable seconds para saber si paso un segundo
					seconds = time(NULL);         //Actualiza los segundos
				}
				//-------------------------------------------------------------------------------
				
				if(tipo == 1 && cantidad <=hora){
					printf("\n\n\t\t			TIEMPO AGOTADO!!! \n");
					printf("\t\t			TIEMPO AGOTADO!!! \n");
					printf("\t\t			TIEMPO AGOTADO!!! \n");
					printf("\t\t			TIEMPO AGOTADO!!! \n\n\n\n");
					return 0;
				}
				
				else if(tipo == 2 && cantidad <=minuto){
					printf("\n\n\t\t			TIEMPO AGOTADO!!! \n");
					printf("\t\t			TIEMPO AGOTADO!!! \n");
					printf("\t\t			TIEMPO AGOTADO!!! \n");
					printf("\t\t			TIEMPO AGOTADO!!! \n\n\n\n");
					return 0;
				}

				else if(tipo==3 && cantidad<=segundo){
					printf("\n\n\t\t			TIEMPO AGOTADO!!! \n");
					printf("\t\t			TIEMPO AGOTADO!!! \n");
					printf("\t\t			TIEMPO AGOTADO!!! \n");
					printf("\t\t			TIEMPO AGOTADO!!! \n\n\n\n");
					return 0;
				}
				//sleep(1);  
			}
		}
	}
	return 0;
}
