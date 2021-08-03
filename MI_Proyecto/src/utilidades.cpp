#include "../includes/utilidades.h"

int obtenerMejorVuelta(vuelta arr[], int n)
{
    vuelta mejorVuelta;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            mejorVuelta = arr[i];
            j = i;
        }
        if (mejorVuelta.duracion > arr[i].duracion)
        {
            mejorVuelta = arr[i];
            j = i;
        }
    }
    return j;
}

int obtenerPeorVuelta(vuelta arr[], int n)
{
    vuelta peorVuelta;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            peorVuelta = arr[i];
            j = i;
        }
        if (peorVuelta.duracion < arr[i].duracion)
        {
            peorVuelta = arr[i];
            j = i;
        }
    }
    return j;
}


void imprimirMejoresVueltas(vuelta arr[], int n, int velocidadMedia)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].velocidad > velocidadMedia)
        {
            cout << "Vuelta: " << arr[i].numeroDeVuelta << " supera la velocidad media." << endl;
        }
    }
}

void imprimirFecha (int fechaC)
{
    int dia=0;
    int mes=0;
    int mesC=0;
    int anio=0;

    anio = fechaC / 10000;
    mes = (fechaC % 10000);
    mesC = mes / 100;
    dia = fechaC % 100;

    cout << "Dia: " << dia << " Mes: " << mesC << " Anio: " << anio << endl;
}

void imprimirTiempo(int duracion)
{
    int minutos=0;
    int segundos=0;

    segundos = duracion % 100;
    minutos = duracion / 100;

    cout << minutos << " min  " << segundos << " seg" << endl;
}

int convertirEnSegundos(int tiempo)
{
    int minutos=0;
    int segundos=0;
    int tiempoEnSegundos;

    segundos = tiempo % 100;
    minutos = tiempo / 100;
    tiempoEnSegundos = segundos + (minutos * 60);
    return tiempoEnSegundos;
}

void ordenarVueltas(vuelta arr[], int n)
{
    vuelta aux;
    int i, j;
    i = 0;
    bool ordenado = false;
    while (i < n && !ordenado)
    {
        ordenado = true;

        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j].numeroDeVuelta > arr[j+1].numeroDeVuelta)
            {
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void leer(string mensaje, int &valor)
{
    cout << mensaje << endl;
    cin >> valor;
    return;
}