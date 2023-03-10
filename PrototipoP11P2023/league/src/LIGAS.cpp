#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include "LIGAS.h"

using namespace std;

    const int NUMERO_EQUIPOS1 = 5;
    const int NUMERO_EQUIPOS2 = 5;
    const int NUMERO_EQUIPOS3 = 5;
    const int NUMERO_JORNADAS = 4;
    const int MAX_PUNTUACION = 50;
    const int MIN_PUNTUACION = 0;
    const int MAXIMA_LONGITUD_CADENA = 100;
    float totalpromedio1=0;
    float totalpromedio2=0;
    float totalpromedio3=0;
    float PromedioDeLiga1=0;
    float PromedioDeLiga2=0;
    float PromedioDeLiga3=0;
    const char FACULTAD = 3;

int busquedaAleatorios(int minimo, int maximo);
void proceso();
void llenarMatriz1(float matriz[NUMERO_EQUIPOS1][NUMERO_JORNADAS + 1]);
void llenarMatriz2(float matriz[NUMERO_EQUIPOS2][NUMERO_JORNADAS + 1]);
void llenarMatriz3(float matriz[NUMERO_EQUIPOS3][NUMERO_JORNADAS + 1]);
void imprimirMatrizLinea();
void imprimirMatriz1(float matriz1[NUMERO_EQUIPOS1][NUMERO_JORNADAS + 1], char equipos[NUMERO_EQUIPOS1][MAXIMA_LONGITUD_CADENA]);
void imprimirMatriz2(float matriz2[NUMERO_EQUIPOS2][NUMERO_JORNADAS + 1], char equipos[NUMERO_EQUIPOS2][MAXIMA_LONGITUD_CADENA]);
void imprimirMatriz3(float matriz3[NUMERO_EQUIPOS3][NUMERO_JORNADAS + 1], char equipos[NUMERO_EQUIPOS2][MAXIMA_LONGITUD_CADENA]);

void proceso()
{
    bool repetir = true;
    char res='s';
    system("cls");
    srand(getpid());
    float matriz1[NUMERO_EQUIPOS1][NUMERO_JORNADAS + 1];
    float matriz2[NUMERO_EQUIPOS2][NUMERO_JORNADAS + 1];
    float matriz3[NUMERO_EQUIPOS3][NUMERO_JORNADAS + 1];
    char equipos1[NUMERO_EQUIPOS1][MAXIMA_LONGITUD_CADENA] = {"Green","Yellow","Red","Gray","Blue"};
    char equipos2[NUMERO_EQUIPOS2][MAXIMA_LONGITUD_CADENA] = {"Jutiapa","Santos","America","Valhalla","Mosku"};
    char equipos3[NUMERO_EQUIPOS3][MAXIMA_LONGITUD_CADENA] = {"Suecia","USA","Mexico","UK","Alemania"};

    do{
    system("cls");
    totalpromedio1=0;
    totalpromedio2=0;
    totalpromedio3=0;
    PromedioDeLiga1=0;
    PromedioDeLiga2=0;
    PromedioDeLiga3=0;
    llenarMatriz1(matriz1);
    PromedioDeLiga1=totalpromedio1/NUMERO_EQUIPOS1;
    imprimirMatriz1(matriz1, equipos1);

    llenarMatriz2(matriz2);
    PromedioDeLiga2=totalpromedio2/NUMERO_EQUIPOS2;
    imprimirMatriz2(matriz2, equipos2);

    llenarMatriz3(matriz3);
    PromedioDeLiga3=totalpromedio3/NUMERO_EQUIPOS3;
    imprimirMatriz3(matriz3, equipos3);
    if (PromedioDeLiga1>PromedioDeLiga2 && PromedioDeLiga1>PromedioDeLiga3)
    {
        cout << "La mejor liga es la LIGA PRIMERA DIVISION con el promedio de: " << PromedioDeLiga1 << endl;
    } else
    if (PromedioDeLiga2>PromedioDeLiga1 && PromedioDeLiga2>PromedioDeLiga1)
    {
        cout << "La mejor liga es la LIGA DE ASCENSO con el promedio de: " << PromedioDeLiga2 << endl;
    } else
    if (PromedioDeLiga3>PromedioDeLiga2 && PromedioDeLiga3>PromedioDeLiga1)
    {
        cout << "La mejor liga es las LIGAS MAYORES con el promedio de: " << PromedioDeLiga3 << endl;
    } else
    {
        cout << "Tienen promedios iguales" << endl;
    }
    cout <<"El promedio de las 3: " << (PromedioDeLiga1+PromedioDeLiga2+PromedioDeLiga3)/3 << endl;
    cout << "desea otro? s/n ";
    cin >> res;
    if (res=='s')
    {
        repetir=true;
    }
    else
    {
        repetir=false;
    }
    }while (repetir);
}
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz1(float matriz1[NUMERO_EQUIPOS1][NUMERO_JORNADAS + 1])
{
    int y, x;
    for (y = 0; y < NUMERO_EQUIPOS1; y++)
    {
        float suma = 0;
        for (x = 0; x < NUMERO_JORNADAS; x++)
        {
            int calificacion = busquedaAleatorios(MIN_PUNTUACION, MAX_PUNTUACION);

            matriz1[y][0] = calificacion;
            int calificacion2 = busquedaAleatorios(MIN_PUNTUACION, MAX_PUNTUACION);

            matriz1[y][1] = calificacion2;
            int calificacion3 = busquedaAleatorios(MIN_PUNTUACION, MAX_PUNTUACION);

            matriz1[y][2] = calificacion3;
            int calificacion4 = busquedaAleatorios(MIN_PUNTUACION, MAX_PUNTUACION);

            matriz1[y][3] = calificacion4;
            suma= matriz1[y][0]+matriz1[y][1]+matriz1[y][2]+matriz1[y][3];
        }
        // Agregar promedio
        float promedio = suma/ NUMERO_JORNADAS;
        matriz1[y][NUMERO_JORNADAS] = promedio;
        totalpromedio1= (float)promedio+totalpromedio1;

    }
}

void llenarMatriz2(float matriz2[NUMERO_EQUIPOS2][NUMERO_JORNADAS + 1])
{
    int y, x;
    for (y = 0; y < NUMERO_EQUIPOS2; y++)
    {
        float suma = 0;
        for (x = 0; x < NUMERO_JORNADAS; x++)
        {
            int calificacion = busquedaAleatorios(MIN_PUNTUACION, MAX_PUNTUACION);

            matriz2[y][0] = calificacion;
            int calificacion2 = busquedaAleatorios(MIN_PUNTUACION, MAX_PUNTUACION);

            matriz2[y][1] = calificacion2;
            int calificacion3 = busquedaAleatorios(MIN_PUNTUACION, MAX_PUNTUACION);

            matriz2[y][2] = calificacion3;
            int calificacion4 = busquedaAleatorios(MIN_PUNTUACION, MAX_PUNTUACION);

            matriz2[y][3] = calificacion4;
            suma= matriz2[y][0]+matriz2[y][1]+matriz2[y][2]+matriz2[y][3];
        }
        // Agregar promedio
        float promedio = suma/ NUMERO_JORNADAS;
        matriz2[y][NUMERO_JORNADAS] = promedio;
        totalpromedio2= (float)promedio+totalpromedio2;
    }
}

void llenarMatriz3(float matriz3[NUMERO_EQUIPOS3][NUMERO_JORNADAS + 1])
{
    int y, x;
    for (y = 0; y < NUMERO_EQUIPOS3; y++)
    {
        float suma = 0;
        for (x = 0; x < NUMERO_JORNADAS; x++)
        {
            int calificacion = busquedaAleatorios(MIN_PUNTUACION, MAX_PUNTUACION);

            matriz3[y][0] = calificacion;
            int calificacion2 = busquedaAleatorios(MIN_PUNTUACION, MAX_PUNTUACION);

            matriz3[y][1] = calificacion2;
            int calificacion3 = busquedaAleatorios(MIN_PUNTUACION, MAX_PUNTUACION);

            matriz3[y][2] = calificacion3;
            int calificacion4 = busquedaAleatorios(MIN_PUNTUACION, MAX_PUNTUACION);

            matriz3[y][3] = calificacion4;
            suma= matriz3[y][0]+matriz3[y][1]+matriz3[y][2]+matriz3[y][3];
        }
        // Agregar promedio
        float promedio = suma/ NUMERO_JORNADAS;
        matriz3[y][NUMERO_JORNADAS] = promedio;
        totalpromedio3= (float)promedio+totalpromedio3;
    }
}

void imprimirMatrizLinea()
{
    int x;
    cout << "+--------";
    for (x = 0; x < NUMERO_JORNADAS + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}
void imprimirMatriz1(float matriz1[NUMERO_EQUIPOS1][NUMERO_JORNADAS + 1], char equipos1[NUMERO_EQUIPOS1][MAXIMA_LONGITUD_CADENA])
{
    int y, x;
    float promedioMayor = matriz1[0][NUMERO_JORNADAS];
    float promedioMenor = matriz1[0][NUMERO_JORNADAS];
    char equipo1PromedioMayor[MAXIMA_LONGITUD_CADENA];
    char equipo1PromedioMenor[MAXIMA_LONGITUD_CADENA];
    cout << "" << endl;
    cout << "" << endl;
    cout << "\t\t   LIGA PRIMERA DIVISION" << endl;

    imprimirMatrizLinea();

    cout << setw(8) << "Equipo";
    cout  << setw(10) << "2010" ;
    cout  << setw(10) << "2011" ;
    cout  << setw(10) << "2012" ;
    cout  << setw(10)<< "2014" ;
    cout << setw(11) << "Prom" << endl;
    imprimirMatrizLinea();
    promedioMenor=100;
    promedioMayor=0;
    for (y = 0; y < NUMERO_EQUIPOS1; y++)
    {
        cout << "!" << setw(8) << equipos1[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_JORNADAS; x++)
        {
            int calificacion = matriz1[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz1[y][NUMERO_JORNADAS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(equipo1PromedioMayor, equipos1[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(equipo1PromedioMenor, equipos1[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    float promedioDeLiga1= totalpromedio1/NUMERO_EQUIPOS1;
    cout << "Equipo con mayor promedio: " << setw(10) << equipo1PromedioMayor << " Promedio: " << setw(10) << promedioMayor << endl;
    cout << "Equipo con menor promedio: " << setw(10) << equipo1PromedioMenor << " Promedio: " << setw(10) << promedioMenor << endl;
    cout << "promedio total de la liga de primera division es de: " << setw(9) << PromedioDeLiga1 << endl;

    cout << "" << endl;
}

void imprimirMatriz2(float matriz2[NUMERO_EQUIPOS2][NUMERO_JORNADAS + 1], char equipos2[NUMERO_EQUIPOS2][MAXIMA_LONGITUD_CADENA])
{
    int y, x;
    float promedioMayor = matriz2[0][NUMERO_JORNADAS];
    float promedioMenor = matriz2[0][NUMERO_JORNADAS];
    char equipo2PromedioMayor[MAXIMA_LONGITUD_CADENA];
    char equipo2PromedioMenor[MAXIMA_LONGITUD_CADENA];
    cout << "" << endl;
    cout << "" << endl;
    cout << "\t\t\tLIGA DE ASCENSO" << endl;

    imprimirMatrizLinea();

    cout << setw(8) << "Equipo";
    cout  << setw(10) << "2010" ;
    cout  << setw(10) << "2011" ;
    cout  << setw(10) << "2012" ;
    cout  << setw(10)<< "2014" ;
    cout << setw(11) << "Prom" << endl;
    imprimirMatrizLinea();
    promedioMenor=100;
    promedioMayor=0;
    for (y = 0; y < NUMERO_EQUIPOS2; y++)
    {
        cout << "!" << setw(8) << equipos2[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_JORNADAS; x++)
        {
            int calificacion = matriz2[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz2[y][NUMERO_JORNADAS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(equipo2PromedioMayor, equipos2[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(equipo2PromedioMenor, equipos2[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    float PromedioDeLiga2= totalpromedio2/NUMERO_EQUIPOS2;
    cout << "Equipo con mayor promedio " << setw(10) << equipo2PromedioMayor << " Promedio: " << setw(10) << promedioMayor << endl;
    cout << "Equipo con mayor promedio " << setw(10) << equipo2PromedioMenor << " Promedio: " << setw(10) << promedioMenor << endl;
    cout << "promedio total de la liga de ascenso es de: " << setw(9) << PromedioDeLiga1 << endl;
    cout << "" << endl;
}

void imprimirMatriz3(float matriz3[NUMERO_EQUIPOS3][NUMERO_JORNADAS + 1], char equipos3[NUMERO_EQUIPOS3][MAXIMA_LONGITUD_CADENA])
{
    int y, x;
    float promedioMayor = matriz3[0][NUMERO_JORNADAS];
    float promedioMenor = matriz3[0][NUMERO_JORNADAS];
    char equipo3PromedioMayor[MAXIMA_LONGITUD_CADENA];
    char equipo3PromedioMenor[MAXIMA_LONGITUD_CADENA];
    cout << "" << endl;
    cout << "" << endl;
    cout << "\t\t\tLIGAS MAYORES" << endl;

    imprimirMatrizLinea();

    cout << setw(8) << "Equipo";
    cout  << setw(10) << "2010" ;
    cout  << setw(10) << "2011" ;
    cout  << setw(10) << "2012" ;
    cout  << setw(10)<< "2014" ;
    cout << setw(11) << "Prom" << endl;
    imprimirMatrizLinea();
    promedioMenor=100;
    promedioMayor=0;
    for (y = 0; y < NUMERO_EQUIPOS3; y++)
    {
        cout << "!" << setw(8) << equipos3[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_JORNADAS; x++)
        {
            int calificacion = matriz3[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz3[y][NUMERO_JORNADAS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(equipo3PromedioMayor, equipos3[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(equipo3PromedioMenor, equipos3[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    float promedioDeLiga3= totalpromedio3/NUMERO_EQUIPOS3;
    cout << "Equipo con mayor promedio " << setw(10) << equipo3PromedioMayor << " Promedio: " << setw(10) << promedioMayor << endl;
    cout << "Equipo con menor promedio " << setw(10) << equipo3PromedioMenor << " Promedio: " << setw(10) << promedioMenor << endl;
    cout << "promedio total de la liga Mayor es de: " << setw(9) << promedioDeLiga3 << endl;
    cout << "" << endl;
}


