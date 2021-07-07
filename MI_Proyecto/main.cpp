#include <iostream>
using namespace std;

struct vuelta
{
    int numeroDeVuelta;
    int duracion;
};

void imprimirTiempo(int duracion)
{
    int minutos=0;
    int segundos=0;

    segundos = duracion % 100;
    minutos = duracion / 100;

    cout << minutos << " min  " << segundos << " seg" << endl;
}

void leer(string mensaje, int &valor)
{
    cout << mensaje << endl;
    cin >> valor;
    return;
}

int main ()
{
    int cantVueltas=0;
    int distanciaKM=0;
    float reduccionTiempo=0;

    vuelta vueltaLenta;
    vuelta vueltaRapida;

    cout << "Cantidad de vueltas (max 20): " << endl;
    cin >> cantVueltas;

    vuelta vueltas[cantVueltas];

    leer("Distancia de la vuelta (Km)", distanciaKM);

   // position of each lap //
    
    for (int i = 0; i < cantVueltas; i++)
    {
        leer("Ingrese el numero de vuelta: ", vueltas[i].numeroDeVuelta);
        leer("Ingrese la duracion de la vuelta (MMSS): ", vueltas[i].duracion);
        
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

    reduccionTiempo = (vueltaRapida.duracion / vueltaLenta.duracion) - 1;
    // TODO: revisar esto con el profe

    // reduccionTiempo = ((vueltaRapida.duracion * 100) / vueltaLenta.duracion) - 1;

    cout << "Cantidad de vueltas: " << cantVueltas << endl;
    cout << "Distancia de la vuelta: " << distanciaKM << " Km" << endl;
    cout << "Vuelta mas Rapida: " << vueltaRapida.numeroDeVuelta << " Tiempo: ";
    imprimirTiempo(vueltaRapida.duracion);
    cout << "Vuelta mas Lenta: " << vueltaLenta.numeroDeVuelta << " Tiempo: ";
    imprimirTiempo(vueltaLenta.duracion);
    cout << "Porcentaje de reduccion de tiempo: " << reduccionTiempo << " %" << endl;
 
    system("pause");
    return 0;
}
