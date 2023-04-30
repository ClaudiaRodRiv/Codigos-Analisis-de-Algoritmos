#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funci�n que utiliza la t�cnica Divide y Conquista para encontrar el m�ximo elemento en un arreglo.
int DAC_Max(int a[], int index, int l)
{
    int max;
    if (l - 1 == 0) {
        // Si el arreglo tiene solo un elemento, ese elemento es el m�ximo.
        return a[index];
    }
    if (index >= l - 2) {
        // Si el arreglo tiene dos elementos, el m�ximo es el mayor de los dos elementos.
        if (a[index] > a[index + 1])
            return a[index];
        else
            return a[index + 1];
    }

    // Llamada recursiva a la funci�n DAC_Max para encontrar el m�ximo elemento del sub-arreglo.
    max = DAC_Max(a, index + 1, l);

    // Comparaci�n del elemento actual con el m�ximo encontrado en el sub-arreglo.
    if (a[index] > max)
        return a[index];
    else
        return max;
}

// Funci�n que utiliza la t�cnica Divide y Conquista para encontrar el m�nimo elemento en un arreglo.
int DAC_Min(int a[], int index, int l)
{
    int min;
    if (l - 1 == 0) {
        // Si el arreglo tiene solo un elemento, ese elemento es el m�nimo.
        return a[index];
    }
    if (index >= l - 2) {
        // Si el arreglo tiene dos elementos, el m�nimo es el menor de los dos elementos.
        if (a[index] < a[index + 1])
            return a[index];
        else
            return a[index + 1];
    }

    // Llamada recursiva a la funci�n DAC_Min para encontrar el m�nimo elemento del sub-arreglo.
    min = DAC_Min(a, index + 1, l);

    // Comparaci�n del elemento actual con el m�nimo encontrado en el sub-arreglo.
    if (a[index] < min)
        return a[index];
    else
        return min;
}

int main()
{
    // Inicializaci�n del arreglo con 10,000 elementos.
    int a[10000];

    // Generaci�n de n�meros aleatorios para el arreglo.
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        a[i] = rand() % 1000; // N�meros aleatorios entre 0 y 999.
    }

    // Llamada a las funciones DAC_Max y DAC_Min para encontrar el m�ximo y m�nimo elemento del arreglo.
    int max = DAC_Max(a, 0, 10000);
    int min = DAC_Min(a, 0, 10000);

    // Impresi�n del resultado.
    printf("El numero minimo en el arreglo es: %d\n", min);
    printf("\nEl numero maximo en el arreglo es: %d\n", max);

    return 0;
}

