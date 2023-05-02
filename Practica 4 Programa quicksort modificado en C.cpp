#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// // Funci�n para intercambiar los elementos
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Particionar la matriz usando el �ltimo elemento como pivote
int partition(int arr[], int low, int high)
{
    // Eligiendo el pivote
    int pivot = arr[high];
    
    // Indice del elemento m�s peque�o e indica
    // La posici�n correcta del pivote encontrada hasta ahora
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        
        // // Si el elemento actual es m�s peque�o que el pivote
        if (arr[j] < pivot) {
            
            // Incremento del �ndice del elemento m�s peque�o
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// La funci�n principal que implementa QuickSort
// arr[] --> Array a ordenar,
// bajo --> �ndice inicial,
// alto --> �ndice final

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        
        // pi es �ndice de partici�n, arr[p]
        // ahora est� en el lugar correcto
        int pi = partition(arr, low, high);
        
        // ordenar por separado los elementos anteriores
        // partici�n y despu�s de la partici�n
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Driver code
int main()
{
    // Generar matriz aleatoria de 10.000 elementos
    int arr[10000];
    srand(time(NULL)); // Generador de n�meros aleatorios semilla
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 10000; // Generar n�mero aleatorio entre 0 y 9999
    }

    int N = sizeof(arr) / sizeof(arr[0]);

    // Llamada de funci�n
    quickSort(arr, 0, N - 1);
    printf("Arreglo Ordenado: \n");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    return 0;
}

