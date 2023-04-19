#include <stdio.h>

// Funci�n para ordenar el arreglo usando Stooge sort
void stoogesort(int arr[], int l, int h) {
   if (l >= h) { // Si el subarreglo tiene un solo elemento o ninguno, entonces est� ordenado.
      return;
   }
   if (arr[l] > arr[h]) { // Si el primer elemento es mayor que el �ltimo, se intercambian.
      int temp = arr[l];
      arr[l] = arr[h];
      arr[h] = temp;
   }
   if (h - l + 1 > 2) { // Si el tama�o del subarreglo es mayor que 2, se contin�a el proceso de ordenamiento.
      int t = (h - l + 1) / 3; // Se calcula la longitud de los dos tercios del arreglo.
      stoogesort(arr, l, h - t); // Se ordenan los primeros dos tercios del arreglo.
      stoogesort(arr, l + t, h); // Se ordena la �ltima parte del arreglo.
      stoogesort(arr, l, h - t); // Se vuelven a ordenar los primeros dos tercios del arreglo.
   }
}

int main() {
   int arr[] = {7, 3, 9, 1, 5}; // Arreglo a ordenar
   int n = sizeof(arr) / sizeof(arr[0]); // Tama�o del arreglo
   stoogesort(arr, 0, n - 1); // Se llama a la funci�n stoogesort para ordenar el arreglo
   printf("Arreglo ordenado: ");
   for (int i = 0; i < n; i++) { // Se imprime el arreglo ordenado
      printf("%d ", arr[i]);
   }
   return 0;
}

