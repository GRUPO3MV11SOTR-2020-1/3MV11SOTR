#include "types.h"
#include "stat.h"
#include "user.h"

// volatile unsigned long long espera = 0;

int
main(int argc, char *argv[])
{
	printf(1, "argc: %d\n", argc);
	printf(1, "%s: Hola Xv6! %s\n", argv[0], argv[1]);
	for(;;);
	// for (espera = 0; espera <= 450000ULL; ++espera);
	exit();
}
