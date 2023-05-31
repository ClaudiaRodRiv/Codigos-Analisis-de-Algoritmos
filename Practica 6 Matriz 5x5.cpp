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
    // Ejemplo de matriz de costos 5x5
    int cost[5][5] = {
        {4, 7, 8, 6, 4},
        {6, 7, 3, 9, 2},
        {3, 8, 1, 2, 4},
        {7, 1, 7, 3, 7},
        {2, 9, 8, 9, 3}
    };
    
    // Dimensiones de la matriz de costos
    int M = sizeof(cost) / sizeof(cost[0]) - 1;
    int N = sizeof(cost[0]) / sizeof(int) - 1;
    
    // Convertir la matriz de costos a un arreglo de punteros
    int **cost_ptr = (int **)malloc((M + 1) * sizeof(int *));
    for (int i = 0; i <= M; i++) {
        cost_ptr[i] = cost[i];
    }
    
    // Calcular el costo mínimo de la ruta
    int minimum_cost_val = minimum_cost(cost_ptr, M, N);
    
    // Imprimir el resultado
    printf("El costo mínimo de la ruta es: %d\n", minimum_cost_val);
    
    return 0;
}

