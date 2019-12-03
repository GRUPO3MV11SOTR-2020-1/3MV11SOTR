// compilacion separada

/*  file.C  */

#include <stdio.h>
#include <stdlib.h>
#include"int_intPt.h"


#define max(a,b) (((a)>(b))?(a):(b))

struct int_intPt*get_numbers(int);

int main(int argc,char*argv[])
{
if(argc<2)
   {
    perror("argc<2");
    exit(1);
   }
struct int_intPt*p=get_numbers(atoi(argv[1]));

int i;
for(i=0;i<p->n;i++)
   {
    printf("%7d",p->intPt[i]);
   }
return argc;
}/*end main*/
