#include <stdio.h>
#include <stdlib.h>

int minimum_cost(int **cost, int M, int N) {
    // Crear una matriz auxiliar para almacenar los costos acumulados
    int **dp = (int **)malloc((M + 1) * sizeof(int *));
    for (int i = 0; i <= M; i++) {
        dp[i] = (int *)malloc((N + 1) * sizeof(int));
    }
    
    // Inicializar el primer elemento de la matriz auxiliar con el costo en (0,0)
    dp[0][0] = cost[0][0];
    
    // Calcular los costos acumulados de la primera columna
    for (int i = 1; i <= M; i++) {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
    }
    
    // Calcular los costos acumulados de la primera fila
    for (int j = 1; j <= N; j++) {
        dp[0][j] = dp[0][j - 1] + cost[0][j];
    }
    
    // Calcular los costos acumulados del resto de la matriz
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = cost[i][j] + ((dp[i - 1][j] < dp[i][j - 1]) ? 
                                     ((dp[i - 1][j] < dp[i - 1][j - 1]) ? dp[i - 1][j] : dp[i - 1][j - 1]) :
                                     ((dp[i][j - 1] < dp[i - 1][j - 1]) ? dp[i][j - 1] : dp[i - 1][j - 1]));
        }
    }
    
    // El costo mínimo de la ruta será el valor en la posición (M,N) de la matriz auxiliar
    int minimum_cost = dp[M][N];
    
    // Liberar memoria de la matriz auxiliar
    for (int i = 0; i <= M; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return minimum_cost;
}

int main() {
	
// Ejemplo de matriz de costos 100x100 (generada aleatoriamente)
int cost_100x100[100][100];
for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
        cost_100x100[i][j] = rand() % 100; // Generar números aleatorios entre 0 y 99
    }
}

// Dimensiones de la matriz de costos 100x100
int M_100x100 = sizeof(cost_100x100) / sizeof(cost_100x100[0]) - 1;
int N_100x100 = sizeof(cost_100x100[0]) / sizeof(int) - 1;

// Convertir la matriz de costos a un arreglo de punteros
int **cost_ptr_100x100 = (int **)malloc((M_100x100 + 1) * sizeof(int *));
for (int i = 0; i <= M_100x100; i++) {
    cost_ptr_100x100[i] = cost_100x100[i];
}

// Calcular el costo mínimo de la ruta para la matriz 100x100
int minimum_cost_val_100x100 = minimum_cost(cost_ptr_100x100, M_100x100, N_100x100);

// Imprimir el resultado
printf("El costo mínimo de la ruta en la matriz 100x100 es: %d\n", minimum_cost_val_100x100);
    
    return 0;
}
