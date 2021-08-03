#include <iostream>
using namespace std;
#ifndef UTILIDADES_H
#define UTILIDADES_H

struct vuelta
{
    int numeroDeVuelta;
    int duracion;
    int fecha;
    int velocidad;
};

void imprimirTiempo(int duracion);
void imprimirFecha (int fechaC);
void ordenarVueltas(vuelta arr[], int n);
void leer(string mensaje, int &valor);
int convertirEnSegundos(int tiempo);
void imprimirMejoresVueltas(vuelta arr[], int n, int velocidadMedia);
int obtenerMejorVuelta(vuelta arr[], int n);
int obtenerPeorVuelta(vuelta arr[], int n);

#endif