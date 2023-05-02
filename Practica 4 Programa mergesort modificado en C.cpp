#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fusiona dos subarreglos de arr[].
// El primer subarreglo es arr[l..m]
// El segundo subarreglo es arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// crear arreglos temporales 
	int L[n1], R[n2];

	// Copiar datos a arreglos temporales 
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Fusionar las matrices temporales de nuevo en arr[l..r]*/
	i = 0; // Indice inicial del primer subarreglo
	j = 0; // Indice inicial del segundo subarreglo
	k = l; // Indice inicial del subarreglo fusionado
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	//Copiar los elementos restantes de L[], si hay hay alguna 
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	//Copiar los elementos restantes de R[], si hay hay alguna 
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l es para el índice izquierdo y r es el índice derecho del sub-matriz de arr a ordenar
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Igual que (l+r)/2, pero evita el desbordamiento de
		// grandes l y h
		int m = l + (r - l) / 2;

		// Ordenar la primera y la segunda mitad
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
 
// Función para imprimir una matriz
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
    int arr[10000];
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 10000;
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("El arreglo es:\n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nEl arreglo ordenado es:\n");
    printArray(arr, n);
    return 0;
}
