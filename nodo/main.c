#include <stdio.h>
#include "nodo.h"

int main()
{
    printf("Prueba del TAD Nodo\n");

    Nodo* n = crearNodo(10);
    Nodo* n = NULL;

if (n != NULL) {
        printf("Valor inicial: %d\n", obtenerValor(n));
    }
asignarValor(n, 25);

printf("Nuevo valor: %d\n", obtenerValor(n)); 
destruirNodo(n);
    return 0;
}
