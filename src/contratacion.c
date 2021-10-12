#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "contratacion.h"
#include "utn_pedirCadena.h"

void utn_menuContratacion (Pantalla aEmpleados [], int lenArrayPantallas, Contratacion , int )
{
	int opcion;
	int lugarLibre;
	int IDdarDeBaja;
	do{
		if (utn_getNumeroInt(&opcion, "\nBienvenido \nUtilice el teclado numerico para elecionar una opcion:\n1)Altas:\n2)Modificar:\n3)Baja:\n4)Informar:", "\nA seleccionado una opcion Invalida", 1, 4, 10)==0)
			{
			switch (opcion)
				{
					case 1:
						if (DameUnLugarLibre(aEmpleados, lenArray, &lugarLibre)==0)
							{
								loadPantalla(aEmpleados);
							}
					break;
					case 2:
						utn_subMenu(aEmpleados, lenArray);
					break;
					case 3:
						if (imprimirArray(aEmpleados, lenArray)==0)
							{
								if (utn_getNumeroInt(&IDdarDeBaja, "\nIngrese ID del empleado que desea darle la baja del sistema: \nVolver al menu principal", "Error opcion incorrecta", 0, 1000, 5)==0)
								{
									if (darDeBaja(aEmpleados, IDdarDeBaja, lenArray)==0)
									{
										printf ("El empleado con ID: %d, ha sido dado de baja.", IDdarDeBaja);
									}
									else
									{
										printf ("El id ingresado no pertenece a ningun empleado.");
									}
								}
							}
					break;
					case 4:

					break;
				}
			}
	}while (opcion <4);

}
