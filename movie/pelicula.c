#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"


struct Pelicula
{
char* titulo;
short anio;
char* genero;
char* directores[MAX_DIRECTORES];
short numDirectores;
};


char* copiarCadena(const char* texto)
{
 if (!texto) return NULL;
 char* copia = (char*)malloc(strlen(texto) + 1); 
   if (copia) {
        strcpy(copia, texto);
    }
    return copia;
}

Pelicula* crearPelicula(const char* titulo, int anio, const char* genero)
{
    Pelicula* p = (Pelicula*)malloc(sizeof(Pelicula));
    if (!p) return NULL;
   p->titulo = copiarCadena(titulo);
   p->genero = copiarCadena(genero);
   p->anio = (short)anio;
   p->numDirectores = 0;
   return p;
}

/* Imprimir película */
void imprimir(Pelicula* p)
{
   if (!p) return;
    printf("TITULO: %s\n", p->titulo); 
    printf("ANIO: %d\n", p->anio); 
    printf("GENERO: %s\n", p->genero); 
    printf("DIRECTOR(ES):\n"); 
    for (int i = 0; i < p->numDirectores; i++) {
        printf("- %s\n", p->directores[i]); 
    }
}

/* Cambiar género */
void cambiarGenero(Pelicula* p, const char* nuevoGenero)
{
if (!p || !nuevoGenero) return;
    free(p->genero);
    p->genero = copiarCadena(nuevoGenero);
}


/* Agregar director */
void agregarDirector(Pelicula* p, const char* director)
{
if (!p || !director) return;
    if (p->numDirectores < MAX_DIRECTORES) {
        p->directores[p->numDirectores] = copiarCadena(director);
        p->numDirectores++;
    } else {
        printf("Error: Maximo de directores alcanzado.\n");
    }
}


/* Liberar memoria */
void destruir(Pelicula* p)
{
if (!p) return;
    free(p->titulo);
    free(p->genero);
    for (int i = 0; i < p->numDirectores; i++) {
        free(p->directores[i]);
    }
    free(p);
}
