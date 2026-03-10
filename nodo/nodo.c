#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

/* TODO
   Definir la estructura Nodo.
   Debe contener un entero llamado valor.
*/
struct Nodo
{
int valor;
};
/* Crear un nodo dinámicamente */
Nodo* crearNodo(int valor)
{
   Nodo* nuevo = (Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo != NULL) {
        nuevo->valor = valor;
    }
    return nuevo;
}


/* Obtener el valor almacenado */
int obtenerValor(Nodo* nodo)
{
    if (nodo != NULL) {
        return nodo->valor;
    }
    return 0;
}

/* Modificar el valor almacenado */
void asignarValor(Nodo* nodo, int valor)
{
    if (nodo != NULL) {
        nodo->valor = valor;
    }
}


/* Liberar memoria del nodo */
void destruirNodo(Nodo* nodo)
{
    if (nodo != NULL) {
        free(nodo);
    }
}
