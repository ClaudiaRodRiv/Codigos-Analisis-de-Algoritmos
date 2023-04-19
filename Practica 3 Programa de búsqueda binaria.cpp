#include <stdio.h>

// Función de búsqueda binaria que recibe como parámetros un arreglo ordenado,
// su tamaño y el elemento que se desea buscar. Retorna el índice del elemento si
// está presente en el arreglo, o -1 si no lo está.
int binary_search(int arr[], int n, int x) {
    int low = 0;  // Índice del primer elemento del subarreglo donde se está buscando.
    int high = n - 1;  // Índice del último elemento del subarreglo donde se está buscando.
    
    // Mientras el subarreglo no sea vacío.
    while (low <= high) {
        int mid = (low + high) / 2;  // Índice del elemento del medio del subarreglo.
        if (arr[mid] == x) {
            // Si el elemento del medio es el que se busca, se retorna su índice.
            return mid;
        } else if (arr[mid] < x) {
            // Si el elemento del medio es menor que el buscado, se descarta la mitad
            // izquierda del subarreglo y se sigue buscando en la mitad derecha.
            low = mid + 1;
        } else {
            // Si el elemento del medio es mayor que el buscado, se descarta la mitad
            // derecha del subarreglo y se sigue buscando en la mitad izquierda.
            high = mid - 1;
        }
    }
    
    // Si el elemento no se encontró en el arreglo, se retorna -1.
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};  // Arreglo ordenado donde se buscará el elemento.
    int n = sizeof(arr) / sizeof(arr[0]);  // Tamaño del arreglo.
    int x;  // Elemento que se desea buscar en el arreglo.
    
    // Se pide al usuario que ingrese el elemento que desea buscar.
    printf("Ingrese el elemento que desea buscar en el arreglo: ");
    scanf("%d", &x);
    
    // Se llama a la función de búsqueda binaria para buscar el elemento en el arreglo.
    int index = binary_search(arr, n, x);
    
    // Se imprime el resultado de la búsqueda.
    if (index != -1) {
        printf("\nEl elemento %d esta en el indice %d del arreglo.\n", x, index);
    } else {
        printf("\nEl elemento %d no esta en el arreglo.\n", x);
    }
    
    return 0;
}


