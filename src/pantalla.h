#ifndef PANTALLA_H_
#define PANTALLA_H_
#include "pantalla.h"
typedef struct
{
	int type;
	float price;
	int id;
	char name [128];
	char address [128];
	int flagEmpty; //esta variable sera utilizada para saber si una posicion esta disponible o no 0: ocupado 1: libre
}Pantalla;

int pantalla_inicializarArray(Pantalla aPantallas[],int lenPantallas);
int loadPantalla (Pantalla* pPantalla);
int imprimirArray (Pantalla array[], int lenArray);
int utn_getNumeroInt (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
int utn_getTextAlfanumerico(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
int DameUnLugarLibre (Pantalla pPantallas[], int lenArray, int* retornoPosicionLibre);
int BuscarPorId (Pantalla aPantallas[], int indiceIngresado, int lenArray);
int darDeBaja (Pantalla aPantallas[], int indiceIngresado, int lenArray);
#endif /* PANTALLA_H_ */
