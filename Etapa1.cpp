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







/*
Un ciclista desea obtener una aplicaci??n que le permita obtener datos estad??sticos sobre sus entrenamientos
con el fin de mejorar en su actividad. 
El ciclista nos cuenta que registra una cantidad aleatoria de vueltas, que elige tambi??n de forma aleatoria,
de las 20 vueltas que realiza en cada entrenamiento. 
De cada vuelta siempre se conoce: 
??? Su posici??n (primera vuelta, segunda vuelta, etc) 
??? Su duraci??n, expresada como un n??mero entero en el formato MMSS (minutos,segundos) 
Tambi??n se conoce la extensi??n de la vuelta expresada en Km, para todas las vueltas es la misma
ya que el ciclista realiza los entrenamientos en un circuito cerrado.


                  ETAPA   1

Desarrollar una aplicaci??n que permita al ciclista: 
 a. Cargar los datos de las vueltas seleccionadas. Se debe poder cargar los datos de una cantidad arbitraria de vueltas determinada por el ciclista. 
 b. Cu??l fue, de las ingresadas, la vuelta m??s r??pida y su tiempo. 
 c. Cu??l fue, de las ingresadas, la vuelta m??s lenta y su tiempo. 
 d. Cu??l es el porcentaje de reducci??n de tiempo entre el peor y mejor tiempo (Tmin / TMax -1)

*/
