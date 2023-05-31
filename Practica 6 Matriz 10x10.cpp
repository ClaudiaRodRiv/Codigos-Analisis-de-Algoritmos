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
	
// Ejemplo de matriz de costos 10x10
int cost_10x10[10][10] = {
    {4, 2, 5, 6, 8, 2, 1, 3, 9, 4},
    {7, 9, 1, 4, 3, 5, 2, 6, 7, 8},
    {3, 6, 4, 7, 8, 2, 5, 3, 1, 9},
    {8, 5, 2, 1, 9, 6, 7, 4, 3, 2},
    {9, 7, 4, 2, 3, 6, 8, 1, 5, 7},
    {1, 3, 6, 9, 2, 5, 4, 7, 8, 1},
    {2, 8, 7, 3, 5, 1, 9, 4, 6, 3},
    {5, 4, 9, 8, 1, 3, 6, 2, 7, 5},
    {6, 1, 3, 5, 4, 7, 8, 9, 2, 6},
    {2, 9, 8, 6, 7, 4, 3, 5, 1, 2}
};

// Dimensiones de la matriz de costos 10x10
int M_10x10 = sizeof(cost_10x10) / sizeof(cost_10x10[0]) - 1;
int N_10x10 = sizeof(cost_10x10[0]) / sizeof(int) - 1;

// Convertir la matriz de costos a un arreglo de punteros
int **cost_ptr_10x10 = (int **)malloc((M_10x10 + 1) * sizeof(int *));
for (int i = 0; i <= M_10x10; i++) {
    cost_ptr_10x10[i] = cost_10x10[i];
}

// Calcular el costo mínimo de la ruta para la matriz 10x10
int minimum_cost_val_10x10 = minimum_cost(cost_ptr_10x10, M_10x10, N_10x10);

// Imprimir el resultado
printf("El costo mínimo de la ruta en la matriz 10x10 es: %d\n", minimum_cost_val_10x10);
    
    return 0;
}

