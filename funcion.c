// compilacion separada

/*  funcion.C  */

#include <stdio.h>
#include <stdlib.h>
#include"int_intPt.h"


struct int_intPt*get_numbers(int a)
{
	struct int_intPt*result;int i=0;
	if(a){
		result=(struct int_intPt*)malloc(sizeof(*result));
		result->n=a;
		result->intPt=(int*)malloc((result->n)*sizeof(int));

		while(a--){
			printf("Entero %7d:",a+1);
			scanf("%d",result->intPt+i);
			i++;
		}
		return result;
	}else{
		return NULL;
	}
}/*end get_numbers()*/

