#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función que utiliza la técnica Divide y Conquista para encontrar el máximo elemento en un arreglo.
int DAC_Max(int a[], int index, int l)
{
    int max;
    if (l - 1 == 0) {
        // Si el arreglo tiene solo un elemento, ese elemento es el máximo.
        return a[index];
    }
    if (index >= l - 2) {
        // Si el arreglo tiene dos elementos, el máximo es el mayor de los dos elementos.
        if (a[index] > a[index + 1])
            return a[index];
        else
            return a[index + 1];
    }

    // Llamada recursiva a la función DAC_Max para encontrar el máximo elemento del sub-arreglo.
    max = DAC_Max(a, index + 1, l);

    // Comparación del elemento actual con el máximo encontrado en el sub-arreglo.
    if (a[index] > max)
        return a[index];
    else
        return max;
}

// Función que utiliza la técnica Divide y Conquista para encontrar el mínimo elemento en un arreglo.
int DAC_Min(int a[], int index, int l)
{
    int min;
    if (l - 1 == 0) {
        // Si el arreglo tiene solo un elemento, ese elemento es el mínimo.
        return a[index];
    }
    if (index >= l - 2) {
        // Si el arreglo tiene dos elementos, el mínimo es el menor de los dos elementos.
        if (a[index] < a[index + 1])
            return a[index];
        else
            return a[index + 1];
    }

    // Llamada recursiva a la función DAC_Min para encontrar el mínimo elemento del sub-arreglo.
    min = DAC_Min(a, index + 1, l);

    // Comparación del elemento actual con el mínimo encontrado en el sub-arreglo.
    if (a[index] < min)
        return a[index];
    else
        return min;
}

int main()
{
    // Inicialización del arreglo con 10,000 elementos.
    int a[10000];

    // Generación de números aleatorios para el arreglo.
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        a[i] = rand() % 1000; // Números aleatorios entre 0 y 999.
    }

    // Llamada a las funciones DAC_Max y DAC_Min para encontrar el máximo y mínimo elemento del arreglo.
    int max = DAC_Max(a, 0, 10000);
    int min = DAC_Min(a, 0, 10000);

    // Impresión del resultado.
    printf("El numero minimo en el arreglo es: %d\n", min);
    printf("\nEl numero maximo en el arreglo es: %d\n", max);

    return 0;
}

