#include <iostream>
using namespace std;

#define VUELTAS 2
#define DIAS 2

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
int obtenerMejorVuelta(vuelta arr[], int n);
int obtenerPeorVuelta(vuelta arr[], int n);

int main ()
{
    int distanciaKM = 0;
    int distanciaMetros;
    int tiempoTotalEnSeg = 0;
    int velocidadMedia = 0;
    int vueltaABuscar = 0;
    float reduccionTiempo = 0;
    int entrenamientoMejorVuelta;
    int entrenamientoPeorVuelta;

    vuelta vueltaLenta;
    vuelta vueltaRapida;

    vuelta vueltasLentas[DIAS];
    vuelta vueltasRapidas[DIAS];

    vuelta vueltas[VUELTAS];
    vuelta vueltasMes[DIAS][VUELTAS];

    leer("Distancia del recorrido (Km)", distanciaKM);
    distanciaMetros = distanciaKM * 1000;
    // position of each lap //
    for (int j = 0; j < DIAS; j++)
    {
        cout << "Dia " << j + 1 << endl;
        for (int i = 0; i < VUELTAS; i++)
        {
            leer("Ingrese el numero de vuelta: ", vueltasMes[j][i].numeroDeVuelta);
            leer("Ingrese la duracion de la vuelta (MMSS): ", vueltasMes[j][i].duracion);
            leer("Ingrese la fecha de la vuelta (AAAAMMDD): ", vueltasMes[j][i].fecha);
            vueltasMes[j][i].velocidad = distanciaMetros / convertirEnSegundos(vueltasMes[j][i].duracion);
            tiempoTotalEnSeg += convertirEnSegundos(vueltasMes[j][i].duracion);
            
            if (i == 0 && j == 0)
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
        ordenarVueltas(vueltasMes[j], VUELTAS);
        velocidadMedia = distanciaMetros / tiempoTotalEnSeg;
        imprimirMejoresVueltas(vueltasMes[j], VUELTAS, velocidadMedia);
        leer("Ingrese el numero de vuelta que desee buscar: ", vueltaABuscar);
        vueltaABuscar = vueltaABuscar - 1;
        if (vueltaABuscar >= 0)
        {
            cout << "Numero de vuelta: " << vueltasMes[j][vueltaABuscar].numeroDeVuelta << endl;
            cout << "Duracion de la vuelta: " << vueltasMes[j][vueltaABuscar].duracion << endl;
            cout << "Fecha de la vuelta: " << vueltasMes[j][vueltaABuscar].fecha << endl;
            cout << "Velocidad de la vuelta: " << vueltasMes[j][vueltaABuscar].velocidad << " m/s" << endl;
        }
        else
        {
            cout << "No se encontro la vuelta." << endl;
        }
        vueltaABuscar = vueltaABuscar - 1;
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

        vueltasLentas[j] = vueltaLenta;
        vueltasRapidas[j] = vueltaRapida;
    }

    entrenamientoMejorVuelta = obtenerMejorVuelta(vueltasRapidas, DIAS);
    entrenamientoPeorVuelta = obtenerPeorVuelta(vueltasLentas, DIAS);

    cout << "   Mejor vuelta del mes:" << endl;
    vuelta mejorVueltaDelMes = vueltasRapidas[entrenamientoMejorVuelta];
    cout << "Fecha: ";
    calcularFecha(mejorVueltaDelMes.fecha);
    cout << "Numero: " << mejorVueltaDelMes.numeroDeVuelta << endl;
    cout << "Tiempo: ";
    imprimirTiempo(mejorVueltaDelMes.duracion);
    cout << "Velocidad: " << mejorVueltaDelMes.velocidad << endl;

    cout << "   Peor vuelta del mes:" << endl;
    cout << "Tiempo: ";
    imprimirTiempo(vueltasLentas[entrenamientoPeorVuelta].duracion);

    cout << endl;
    system("pause");
    return 0;
}

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
