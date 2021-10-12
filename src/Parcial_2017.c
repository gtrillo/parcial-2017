#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "utn_menu.h"
#define LENEMPLEADOS 1000

int main(void)
{
	Pantalla aPantallas [LENEMPLEADOS];

	setbuf (stdout, NULL);
	pantalla_inicializarArray(aPantallas, LENEMPLEADOS);
	utn_menu (aPantallas, LENEMPLEADOS);
	return EXIT_SUCCESS;
}



