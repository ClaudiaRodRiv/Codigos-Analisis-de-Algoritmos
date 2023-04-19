#include <stdio.h>

// Función para ordenar el arreglo usando Stooge sort
void stoogesort(int arr[], int l, int h) {
   if (l >= h) { // Si el subarreglo tiene un solo elemento o ninguno, entonces está ordenado.
      return;
   }
   if (arr[l] > arr[h]) { // Si el primer elemento es mayor que el último, se intercambian.
      int temp = arr[l];
      arr[l] = arr[h];
      arr[h] = temp;
   }
   if (h - l + 1 > 2) { // Si el tamaño del subarreglo es mayor que 2, se continúa el proceso de ordenamiento.
      int t = (h - l + 1) / 3; // Se calcula la longitud de los dos tercios del arreglo.
      stoogesort(arr, l, h - t); // Se ordenan los primeros dos tercios del arreglo.
      stoogesort(arr, l + t, h); // Se ordena la última parte del arreglo.
      stoogesort(arr, l, h - t); // Se vuelven a ordenar los primeros dos tercios del arreglo.
   }
}

int main() {
   int arr[] = {7, 3, 9, 1, 5}; // Arreglo a ordenar
   int n = sizeof(arr) / sizeof(arr[0]); // Tamaño del arreglo
   stoogesort(arr, 0, n - 1); // Se llama a la función stoogesort para ordenar el arreglo
   printf("Arreglo ordenado: ");
   for (int i = 0; i < n; i++) { // Se imprime el arreglo ordenado
      printf("%d ", arr[i]);
   }
   return 0;
}

