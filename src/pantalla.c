#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#define ESTADO_LIBRE 1
#define ESTADO_OCUPADO 0
#define LEN_ARRAY 128
/**
 *\brief funsion para inicializar array
 *\param puntero a la dirrecion de memoria donde se aloja el array
 *\param largo del array
 *\retorna 0 en el caso de que este todo bien y -1 en caso de error
 */
static int elegirOpcion (int* opcion);
static void imprimirOpciones (void);
static int modificarSector (int* pArray);
static int modificarSalario (float* pArray);
static int modificarNombre (char array[]);
static int modificarApellido (char array[]);
static int DameUnIdNuevo(void);
int pantalla_inicializarArray(Pantalla aPantallas[],int lenPantallas)
{
	int retorno;
	int i;

	if (aPantallas != NULL && lenPantallas > 0)
	{
		for (i = 0; i < lenPantallas; i++)
		{
			aPantallas[i].flagEmpty = 1;
			retorno = 0;
		}
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}

int loadPantalla (Pantalla* pPantalla)
{
	int retorno;
	int typeAux;
	float priceAux;
	char nameAux [128];
	char addressAux [128];

	if (pPantalla != NULL)
	{
		if (utn_getNumeroInt (&typeAux, "Ingrese tipo de pantalla [0 LCD - 1 LED]", "A ingresado un tipo erroneo", 0, 1, 5)==0)
		{
			if (utn_getNumeroFloat(&priceAux, "Ingrese precio por día", "Precio fuera del rango", 1, 1000000, 5)==0)
			{
				if (utn_getText(nameAux, 128, "Ingrese nombre", "El tipo de cadena ingresada no corresponde a un texto", 5)==0)
				{
					if (utn_getTextAlfanumerico(addressAux, 128, "\nIngrese dirrecion", "El tipo de cadena ingresada no corresponde a un texto", 5)==0)
					{
								pPantalla->type = typeAux;
								pPantalla->price = priceAux;
								strncpy(pPantalla->name, nameAux, sizeof (pPantalla->name));
								strncpy(pPantalla->address, addressAux, sizeof (pPantalla->address));
								pPantalla->id = DameUnIdNuevo();
								pPantalla ->flagEmpty = ESTADO_OCUPADO;
								retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}

static int DameUnIdNuevo(void)
{
	static int contador = 0;
	contador++;
	return contador;
}

int DameUnLugarLibre (Pantalla pPantallas[], int lenArray, int* retornoPosicionLibre)
{
	int retorno;
	int indice;
	int auxLugarLibre;
	if (pPantallas != NULL)
	{
		for (indice = 0; indice < lenArray; indice++)
		{
			if (pPantallas[indice].flagEmpty == 1)
			{
				auxLugarLibre = indice;
				retorno = 0;
				break;
			}
		}
	}
	*retornoPosicionLibre = auxLugarLibre;
	return retorno;
}

int BuscarPorId (Pantalla aPantallas[], int indiceIngresado, int lenArray)
{
	int retorno;
	int indice;

	for (indice = 0; indice < lenArray; indice++)
	{
		if (indiceIngresado == aPantallas[indice].id && aPantallas[indice].flagEmpty == ESTADO_OCUPADO)
		{
			retorno = 0;
			break;
		}
		else
		{
			retorno = -1;
		}
	}
	return retorno;
}

int darDeBaja (Pantalla aPantallas[], int indiceIngresado, int lenArray)
{
		int retorno;
		int indice;

		for (indice = 0; indice < lenArray; indice++)
		{
			if (indiceIngresado == aPantallas[indice].id && aPantallas[indice].flagEmpty == ESTADO_OCUPADO)
			{
				aPantallas[indice].flagEmpty = ESTADO_LIBRE;
				retorno = 0;
				break;
			}
			else
					{
						retorno = -1;
					}
		}
		return retorno;
}

int imprimirArray (Pantalla array[], int lenArray)
{
	int indice;
	int retorno = -1;
	if (array != NULL && lenArray >= 0)
	{
	for (indice = 0; indice < lenArray; indice++)
	{
		if (array[indice].flagEmpty == ESTADO_OCUPADO)
		{
			printf ("\nID: %d - NOMBRE: %s - TIPO: %d - PRECIO: %f - DIRECCION: %s", array[indice].id, array[indice].name, array[indice].type, array[indice].price, array[indice].address);
			retorno = 0;
		}
	}
	}
	return retorno;
}


int modificarEmpleado(Pantalla* aEmpleados)
{
	int IDaModificar;
	int retorno = -1;
	int auxSector;
	float auxSalary;
	char auxName[51];
	char auxLastName[51];

	if (aEmpleados != NULL)
	{
		if (elegirOpcion(&IDaModificar) == 0)
		{
			retorno = 1;
			switch (IDaModificar)
			{
				case 1:
					if (modificarSector(&auxSector) == 0)
					{
						aEmpleados->type = auxSector;
					}
					break;
				case 2:
					if (modificarSalario(&auxSalary) == 0)
					{
						aEmpleados->price = auxSalary;
					}
					break;
				case 3:
					if (modificarNombre(auxName) == 0)
					{
						strncpy(aEmpleados->name, auxName, LEN_ARRAY);
					}
					break;
				case 4:
					if (modificarApellido(auxLastName) == 0)
					{
						strncpy(aEmpleados->address, auxLastName, LEN_ARRAY);
					}
			}
		}
	}
	return retorno;
}

static int elegirOpcion (int* opcion)
{
	int retorno = -1;
	int auxOpcion;

	imprimirOpciones();
	if (utn_getNumeroInt(&auxOpcion,"\nUtilice el teclado numerico para seleccionar una opcion:\n","Error",1,4,2) == 0)
	{
		retorno = 0;
		*opcion = auxOpcion;
	}
	return retorno;
}

static void imprimirOpciones (void)
{
	printf ("\n¿Que campo desea modificar?");
	printf("\n1. tipo");
	printf("\n2. precio");
	printf("\n3. Nombre");
	printf("\n4. direccion");
}

static int modificarSector (int* pArray)
{
	int retorno = -1;
	char mensaje[100];
	int auxSector;
	strncpy(mensaje, "\nIngrese el tipo:",sizeof(mensaje));
	if (utn_getNumeroInt(&auxSector,mensaje,"Error",1,100,2) == 0)
	{
		retorno = 0;
		*pArray = auxSector;
	}
	return retorno;
}

static int modificarSalario (float* pArray)
{
	int retorno = -1;
	char mensaje[100];
	float auxSalario;
	strncpy(mensaje, "\nIngrese precio",sizeof(mensaje));
	if (utn_getNumeroFloat(&auxSalario, mensaje, "Error", 0, 10000, 2)== 0)
	{
		retorno = 0;
		*pArray = auxSalario;
	}
	return retorno;
}

static int modificarNombre (char array[])
{
	int retorno = -1;
	char mensaje[100];
	char auxName[LEN_ARRAY];
	strncpy(mensaje, "\nIngrese el nombre",sizeof(mensaje));
	if (utn_getText(auxName, LEN_ARRAY, mensaje, "Error",2) == 0)
	{
		retorno = 0;
		strncpy(array, auxName, LEN_ARRAY);
	}
	return retorno;
}

static int modificarApellido (char array[])
{
	int retorno = -1;
	char mensaje[100];
	char auxApellido[LEN_ARRAY];
	strncpy(mensaje, "\nIngrese la direccion",sizeof(mensaje));
	if (utn_getText(auxApellido, LEN_ARRAY, mensaje, "Error",2) == 0)
	{
		retorno = 0;
		strncpy(array, auxApellido,LEN_ARRAY);
	}
	return retorno;
}
