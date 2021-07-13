#include <iostream>
#include "includes/utilidades.h"
using namespace std;

int main ()
{
    int dias = 30;
    int vueltas = 20;

    int distanciaKM = 0;
    int distanciaMetros;
    int tiempoTotalEnSeg = 0;
    int velocidadMedia = 0;
    int vueltaABuscar = 0;
    float tiempoPromedio = 0;
    int entrenamientoMejorVuelta;
    int entrenamientoPeorVuelta;

    vuelta vueltaLenta;
    vuelta vueltaRapida;

    vuelta vueltasLentas[dias];
    vuelta vueltasRapidas[dias];

    vuelta vueltasMes[dias][vueltas];

    leer("Distancia del recorrido (Km)", distanciaKM);
    distanciaMetros = distanciaKM * 1000;

    for (int j = 0; j < dias; j++)
    {
        cout << "\tDia " << j + 1 << endl;
        for (int i = 0; i < vueltas; i++)
        {
            leer("Ingrese el numero de vuelta: ", vueltasMes[j][i].numeroDeVuelta);
            leer("Ingrese la duracion de la vuelta (MMSS): ", vueltasMes[j][i].duracion);
            leer("Ingrese la fecha de la vuelta (AAAAMMDD): ", vueltasMes[j][i].fecha);
            vueltasMes[j][i].velocidad = distanciaMetros / convertirEnSegundos(vueltasMes[j][i].duracion);
            tiempoTotalEnSeg += convertirEnSegundos(vueltasMes[j][i].duracion);
            
            if (i == 0)
            {
                vueltaRapida = vueltasMes[j][i];
                vueltaLenta = vueltasMes[j][i];
            }
            
            if (vueltasMes[j][i].duracion < vueltaRapida.duracion)
            {
                vueltaRapida = vueltasMes[j][i];
            }

            if (vueltasMes[j][i].duracion > vueltaLenta.duracion)
            {
                vueltaLenta = vueltasMes[j][i];
            }
        }
        ordenarVueltas(vueltasMes[j], vueltas);

        velocidadMedia = distanciaMetros / tiempoTotalEnSeg;

        cout << "Velocidad media: " << velocidadMedia << " m/s" << endl;
        cout << "------------------------------" << endl;
        imprimirMejoresVueltas(vueltasMes[j], vueltas, velocidadMedia);
        cout << endl;

        leer("Ingrese el numero de vuelta que desee buscar: ", vueltaABuscar);
        vueltaABuscar = vueltaABuscar - 1;
        cout << endl;


        if (vueltaABuscar >= 0)
        {
            cout << "Numero de vuelta: " << vueltasMes[j][vueltaABuscar].numeroDeVuelta << endl;
            cout << "Duracion de la vuelta: "; imprimirTiempo(vueltasMes[j][vueltaABuscar].duracion);
            cout << "Fecha de la vuelta: "; imprimirFecha(vueltasMes[j][vueltaABuscar].fecha);
            cout << "Velocidad de la vuelta: " << vueltasMes[j][vueltaABuscar].velocidad << " m/s" << endl;
        }
        else
        {
            cout << "No se encontro la vuelta." << endl;
        }
        vueltaABuscar = vueltaABuscar - 1;
        

        tiempoPromedio = tiempoTotalEnSeg / vueltas;

        cout << "------------------------------------------------" << endl;
        cout << "Cantidad total de vueltas: " << vueltas << endl << endl;

        cout << "Distancia de las vueltas: " << distanciaKM << " KM" << endl << endl;

        cout << "Vuelta mas Rapida: " << vueltaRapida.numeroDeVuelta << " Tiempo: ";
        imprimirTiempo(vueltaRapida.duracion);
        cout << "Vuelta mas Lenta: " << vueltaLenta.numeroDeVuelta << " Tiempo: ";
        imprimirTiempo(vueltaLenta.duracion);
        cout << "Tiempo promedio: " << tiempoPromedio << " segundos" << endl << endl;

        vueltasLentas[j] = vueltaLenta;
        vueltasRapidas[j] = vueltaRapida;
    }

    entrenamientoMejorVuelta = obtenerMejorVuelta(vueltasRapidas, dias);
    entrenamientoPeorVuelta = obtenerPeorVuelta(vueltasLentas, dias);
    
    cout << "------------------------------------------------" << endl;
    cout << "\tMejor vuelta del mes:" << endl;
    vuelta mejorVueltaDelMes = vueltasRapidas[entrenamientoMejorVuelta];
    imprimirFecha(mejorVueltaDelMes.fecha);
    cout << "Numero: " << mejorVueltaDelMes.numeroDeVuelta << endl;
    cout << "Tiempo: ";
    imprimirTiempo(mejorVueltaDelMes.duracion);
    cout << "Velocidad: " << mejorVueltaDelMes.velocidad << endl;
    cout << "------------------------------------------------" << endl;
    cout << "\tPeor vuelta del mes:" << endl;
    cout << "Tiempo: ";
    imprimirTiempo(vueltasLentas[entrenamientoPeorVuelta].duracion);
    cout << endl;
    system("pause");
    return 0;
}
