#include <iostream>
using namespace std;

#define VUELTAS 4

struct vuelta
{
    int numeroDeVuelta;
    int duracion;
    int fecha;
    int velocidad;
};

void imprimirTiempo(int duracion);
void calcularFecha (int fechaC);
void ordenarVueltas(vuelta arr[], int n);
void leer(string mensaje, int &valor);
int convertirEnSegundos(int tiempo);
void imprimirMejoresVueltas(vuelta arr[], int n, int velocidadMedia);
int buscarVuelta(vuelta arr[], int n, int x);

int main ()
{
    int distanciaKM = 0;
    int distanciaMetros;
    int tiempoTotalEnSeg = 0;
    int velocidadMedia = 0;
    int vueltaABuscar = 0;
    float reduccionTiempo = 0;

    vuelta vueltaLenta;
    vuelta vueltaRapida;

    vuelta vueltas[VUELTAS];

    leer("Distancia del recorrido (Km)", distanciaKM);
    distanciaMetros = distanciaKM * 1000;
    // position of each lap //
    
    for (int i = 0; i < VUELTAS; i++)
    {
        leer("Ingrese el numero de vuelta: ", vueltas[i].numeroDeVuelta);
        leer("Ingrese la duracion de la vuelta (MMSS): ", vueltas[i].duracion);
        leer("Ingrese la fecha de la vuelta (AAAAMMDD): ", vueltas[i].fecha);
        vueltas[i].velocidad = distanciaMetros / convertirEnSegundos(vueltas[i].duracion);
        tiempoTotalEnSeg += convertirEnSegundos(vueltas[i].duracion);
        
        if (i == 0)
        {
            vueltaRapida.duracion = vueltas[i].duracion;
            vueltaLenta.duracion = vueltas[i].duracion;
            vueltaLenta.numeroDeVuelta = vueltas[i].numeroDeVuelta;
            vueltaRapida.numeroDeVuelta = vueltas[i].numeroDeVuelta;
        }
        
        if (vueltas[i].duracion < vueltaRapida.duracion)
        {
            vueltaRapida.duracion = vueltas[i].duracion;
            vueltaRapida.numeroDeVuelta = vueltas[i].numeroDeVuelta;
        }

        if (vueltas[i].duracion > vueltaLenta.duracion)
        {
            vueltaLenta.duracion = vueltas[i].duracion;
            vueltaLenta.numeroDeVuelta = vueltas[i].numeroDeVuelta;
        }
        
    }
    cout << endl;

    ordenarVueltas(vueltas, VUELTAS);


    velocidadMedia = distanciaMetros / tiempoTotalEnSeg;
    imprimirMejoresVueltas(vueltas, VUELTAS, velocidadMedia);

    leer("Ingrese el numero de vuelta que desee buscar: ", vueltaABuscar);
    vueltaABuscar = vueltaABuscar - 1;
    if (vueltaABuscar >= 0)
    {
        cout << "Numero de vuelta: " << vueltas[vueltaABuscar].numeroDeVuelta << endl;
        cout << "Duracion de la vuelta: " << vueltas[vueltaABuscar].duracion << endl;
        cout << "Fecha de la vuelta: " << vueltas[vueltaABuscar].fecha << endl;
        cout << "Velocidad de la vuelta: " << vueltas[vueltaABuscar].velocidad << " m/s" << endl;
    }
    else
    {
        cout << "No se encontro la vuelta." << endl;
    }

    // TODO: revisar esto con el profe
    reduccionTiempo = (vueltaRapida.duracion / vueltaLenta.duracion) - 1;

    // reduccionTiempo = ((vueltaRapida.duracion * 100) / vueltaLenta.duracion) - 1;

    cout << "Cantidad de vueltas: " << VUELTAS << endl;
    cout << "Distancia de la vuelta: " << distanciaKM << " Km" << endl;
    cout << "Vuelta mas Rapida: " << vueltaRapida.numeroDeVuelta << " Tiempo: ";
    imprimirTiempo(vueltaRapida.duracion);
    cout << "Vuelta mas Lenta: " << vueltaLenta.numeroDeVuelta << " Tiempo: ";
    imprimirTiempo(vueltaLenta.duracion);
    cout << "Porcentaje de reduccion de tiempo: " << reduccionTiempo << " %" << endl;
 
    system("pause");
    return 0;
}

int busquedaBinaria(vuelta arr[], int n, int x) {
    int inicio = 0;
    int fin = n -1;
    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;
        
        if (arr[mitad].numeroDeVuelta == x)
            return mitad;
        
        if (arr[mitad].numeroDeVuelta > x)
        {
            fin = mitad - 1;
        }
        else
        {
            inicio = mitad + 1;
        }
    }
    return -1;
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

void calcularFecha (int fechaC)
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
