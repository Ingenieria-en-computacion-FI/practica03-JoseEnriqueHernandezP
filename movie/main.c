#include <stdio.h>
#include "pelicula.h"

int main()
{

    printf("Prueba del TAD Pelicula\n");

    Pelicula* p = crearPelicula("The Matrix", 1999, "Accion");
    Pelicula* p = NULL;
    
    agregarDirector(p, "Steven Spielberg");
    agregarDirector(p, "Stanley Kubrick");

    imprimir(p);


    printf("\nCambiar genero\n");

    cambiarGenero(p, "Ciencia Ficcion");

   imprimir(p)


    destruir(p);

    return 0;
}
