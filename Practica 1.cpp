#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

// Declaración de las funciones
void generarArreglo(int *arreglo, int tam);
void imprimirArreglo(int *arreglo, int tam);
int buscarElemento(int *arreglo, int tam, int elemento);
void ordenarArreglo(int *arreglo, int tam);
void calcularTiempo(int *arreglo, int tam);
void calcularConsumoMemoria(int *arreglo, int tam);

int main()
{
    int opcion, tam;
    int *arreglo = NULL;
    clock_t inicio, fin;
    double tiempo;

    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tam);

    // Verifica que el tamaño del arreglo sea al menos 5 elementos
    if(tam < 5){
        printf("\nEl tamano del arreglo debe ser de al menos 5 elementos.\n");
        return 0;
    }

    // Asigna memoria para el arreglo
    arreglo = (int*) malloc(tam * sizeof(int));

    do{
        printf("\nSeleccione una opcion:\n");
        printf("1. Generar arreglo aleatorio.\n");
        printf("2. Imprimir arreglo.\n");
        printf("3. Buscar elemento en arreglo.\n");
        printf("4. Ordenar arreglo.\n");
        printf("5. Calcular tiempo de ejecucion.\n");
        printf("6. Calcular consumo de memoria.\n");
        printf("7. Salir.\n\n");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                generarArreglo(arreglo, tam);
                printf("\nArreglo generado exitosamente.\n");
                break;
            case 2:
                imprimirArreglo(arreglo, tam);
                break;
            case 3:
                {
                    int elemento;
                    printf("\nIngrese el elemento a buscar: ");
                    scanf("%d", &elemento);
                    int posicion = buscarElemento(arreglo, tam, elemento);
                    if(posicion == -1){
                        printf("El elemento no se encuentra en el arreglo.\n");
                    }
                    else{
                        printf("El elemento se encuentra en la posicion %d del arreglo.\n", posicion);
                    }
                }
                break;
            case 4:
                ordenarArreglo(arreglo, tam);
                printf("\nArreglo ordenado exitosamente.\n");
                break;
            case 5:
                calcularTiempo(arreglo, tam);
                break;
            case 6:
                calcularConsumoMemoria(arreglo, tam);
                break;
            case 7:
                printf("\nHasta luego!\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
        }

    }while(opcion != 7);

    // Libera la memoria del arreglo
    free(arreglo);
    return 0;
}

// Función para generar un arreglo aleatorio
void generarArreglo(int *arreglo, int tam)
{
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        arreglo[i] = rand() % MAX;
    }
}

// Función para imprimir un arreglo
void imprimirArreglo(int *arreglo, int tam)
{
    printf("\n[ ");
    for(int i = 0; i < tam; i++){
        printf("%d ", arreglo[i]);
    }
    printf("]\n");
}

int buscarElemento(int *arreglo, int tam, int elemento)
{
    // Recorre el arreglo buscando el elemento
    for(int i = 0; i < tam; i++){
        if(arreglo[i] == elemento){ // Si encuentra el elemento
            return i; // Retorna el índice donde lo encontró
        }
    }
    return -1; // Si no encontró el elemento, retorna -1
}

void ordenarArreglo(int *arreglo, int tam)
{
    int i, j, indiceMenor, temp;

    // Recorre el arreglo buscando el menor elemento y lo coloca al inicio
    for(i = 0; i < tam - 1; i++){
        indiceMenor = i;
        for(j = i + 1; j < tam; j++){
            if(arreglo[j] < arreglo[indiceMenor]){
                indiceMenor = j;
            }
        }
        temp = arreglo[i];
        arreglo[i] = arreglo[indiceMenor];
        arreglo[indiceMenor] = temp;
    }
}

void calcularTiempo(int *arreglo, int tam)
{
    clock_t inicio, fin;
    double tiempo;

    // Toma el tiempo de inicio
    inicio = clock();
    generarArreglo(arreglo, tam);
    imprimirArreglo(arreglo, tam);
    buscarElemento(arreglo, tam, 0);
    ordenarArreglo(arreglo, tam);
    // Toma el tiempo de fin
    fin = clock();

    // Calcula el tiempo transcurrido
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("\nTiempo de ejecucion: %f segundos.\n", tiempo);
}

void calcularConsumoMemoria(int *arreglo, int tam)
{
    printf("\nConsumo de memoria:\n");
    printf("Opcion 1: %ld bytes.\n", tam * sizeof(int)); // El arreglo ocupa tam veces el tamaño de un entero
    printf("Opcion 2: %ld bytes.\n", tam * sizeof(int)); // El arreglo ocupa tam veces el tamaño de un entero
    printf("Opcion 3: %ld bytes.\n", tam * sizeof(int)); // El arreglo ocupa tam veces el tamaño de un entero
    printf("Opcion 4: %ld bytes.\n", 0); // No se reserva memoria adicional
    printf("Opcion 5: %ld bytes.\n", 0); // No se reserva memoria adicional
}
