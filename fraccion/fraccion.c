#include <stdio.h>
#include <stdlib.h>
#include "fraccion.h"

/* TODO
   Definir la estructura Fraccion
   Debe contener:
   - numerador
   - denominador
*/
struct Fraccion
{
    int numerador;
   int denominador;
};


/* TODO
   Crear una función auxiliar para calcular
   el máximo común divisor (MCD)
*/
int mcd(int a, int b)
{
   int temporal;
   if (a < 0) a = -a;
   if (b < 0) b = -b;
    
   while (b != 0) {
        temporal = b;
        b = a % b;
        a = temporal;
    }
    return 1;
}


/* Crear fracción */
Fraccion* crearFraccion(int num, int den)
{
if (den == 0) {
        printf("Error: El denominador no puede ser de cero.\n");
        return NULL;
}
Fraccion* nueva = (Fraccion*)malloc(sizeof(Fraccion));
    if (nueva == NULL) return NULL;
nueva->numerador = num;
nueva->denominador = den;
simplificar(nueva);
return nueva;
}
/* Simplificar fracción */
void simplificar(Fraccion* f)
{
if (f == NULL) return;
int comun = mcd(f->numerador, f->denominador);
   f->numerador /= comun;
   f->denominador /= comun; 
   if (f->denominador < 0) {
    f->numerador = -f->numerador;
    f->denominador = -f->denominador;
   }
}


/* Sumar fracciones */
Fraccion* sumar(Fraccion* a, Fraccion* b)
{
   if (a == NULL || b == NULL) return NULL;
   int num_res = (a->numerador * b->denominador) + (a->denominador * b->numerador);
    int den_res = a->denominador * b->denominador;
   return crearFraccion(num_res, den_res);
   return NULL;
}
/* Imprimir fracción */
void imprimir(Fraccion* f)
{
if (f != NULL) {
        printf("%d/%d", f->numerador, f->denominador);
    } else {
        printf("NULL");
    }
}


/* Liberar memoria */
void destruir(Fraccion* f)
{
if (f != NULL) {
        free(f);
    }
}
