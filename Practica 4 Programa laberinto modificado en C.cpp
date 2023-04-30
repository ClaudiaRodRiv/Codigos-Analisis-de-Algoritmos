#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10 // se aumenta el n�mero de filas a 10
#define COLS 10 // se aumenta el n�mero de columnas a 10

void printMaze(int maze[ROWS][COLS]) // funci�n para imprimir el laberinto
{
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d \t", maze[i][j]); // imprime el valor de cada celda del laberinto
        }
        printf("\n");
    }
}

bool is_valid_move(int maze[ROWS][COLS], int x, int y) // funci�n para comprobar si un movimiento es v�lido
{
    // el movimiento es v�lido si la posici�n (x,y) est� dentro de los l�mites del laberinto
    // y si el valor de la celda es 0 (lo que significa que la celda no es un obst�culo)
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0;
}

bool dfs(int maze[ROWS][COLS], int x, int y, int end_x, int end_y, int path[ROWS * COLS][2], int *path_length) // funci�n de b�squeda en profundidad
{
    if (x == end_x && y == end_y) { // si se ha llegado al punto final
        path[*path_length][0] = x;
        path[*path_length][1] = y;
        (*path_length)++;
        return true; // se devuelve verdadero
    }

    maze[x][y] = 2; // se marca la celda como visitada
    int moves[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // arreglo de posibles movimientos: derecha, abajo, izquierda, arriba

    for (int i = 0; i < 4; i++) { // se itera sobre los movimientos posibles
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        if (is_valid_move(maze, nx, ny)) { // si el movimiento es v�lido
            if (dfs(maze, nx, ny, end_x, end_y, path, path_length)) { // se realiza una b�squeda en profundidad recursiva
                path[*path_length][0] = x;
                path[*path_length][1] = y;
                (*path_length)++;
                return true; // si se encontr� una soluci�n, se devuelve verdadero
            }
        }
    }

    return false; // si no se encontr� una soluci�n, se devuelve falso
}

int main() {
    // Configuraci�n del laberinto
    int maze[ROWS][COLS];
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Las paredes son representadas por 1, los caminos por 0
            maze[i][j] = rand() % 2;
        }
    }
    // Colocar entrada y salida
    maze[0][0] = 0;
    maze[ROWS-1][COLS-1] = 0;
    printf("Este es el laberinto:\n\n");
    printMaze(maze);

    int start_x = 0;
    int start_y = 0;
    int end_x = ROWS-1;
    int end_y = COLS-1;

    int path[ROWS * COLS][2];
    int path_length = 0;

    if (dfs(maze, start_x, start_y, end_x, end_y, path, &path_length)) {
        printf("\n�Laberinto resuelto! Camino:\n");
        for (int i = path_length - 1; i >= 0; i--) {
            printf("(%d, %d)\n", path[i][0], path[i][1]);
        }
    } else {
        printf("\nNo se encontro solucion.\n");
    }

    return 0;
}
