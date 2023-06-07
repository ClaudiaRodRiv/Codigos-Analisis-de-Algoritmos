#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_CIUDADES 10

int distancias[MAX_CIUDADES][MAX_CIUDADES];
bool visitado[MAX_CIUDADES];
int rutaOptima[MAX_CIUDADES + 1]; // La ruta óptima incluye el regreso a la ciudad de origen

int numCiudades;

int min(int a, int b) {
    return (a < b) ? a : b;
}

void tsp(int ciudadActual, int ciudadesVisitadas, int costoActual, int numVisitadas, int* costoMinimo) {
    if (numVisitadas == numCiudades && distancias[ciudadActual][0] != 0) {
        if ((costoActual + distancias[ciudadActual][0]) < *costoMinimo) {
            *costoMinimo = costoActual + distancias[ciudadActual][0];
            for (int i = 0; i < numCiudades; i++) {
                rutaOptima[i] = visitado[i];
            }
            rutaOptima[numCiudades] = 0; // Regreso a la ciudad de origen (Nueva York)
        }
        return;
    }

    for (int i = 0; i < numCiudades; i++) {
        if (!visitado[i] && distancias[ciudadActual][i] != 0) {
            visitado[i] = true;
            tsp(i, ciudadesVisitadas | (1 << i), costoActual + distancias[ciudadActual][i], numVisitadas + 1, costoMinimo);
            visitado[i] = false;
        }
    }
}

int main() {
    // Inicializar las distancias entre las ciudades
    numCiudades = 4;
    distancias[0][0] = 0;
    distancias[0][1] = 10;
    distancias[0][2] = 15;
    distancias[0][3] = 20;
    distancias[1][0] = 10;
    distancias[1][1] = 0;
    distancias[1][2] = 35;
    distancias[1][3] = 25;
    distancias[2][0] = 15;
    distancias[2][1] = 35;
    distancias[2][2] = 0;
    distancias[2][3] = 30;
    distancias[3][0] = 20;
    distancias[3][1] = 25;
    distancias[3][2] = 30;
    distancias[3][3] = 0;

    // Inicializar el arreglo de visitados
    for (int i = 0; i < numCiudades; i++) {
        visitado[i] = false;
    }

    // Inicializar la ruta óptima con un valor alto
    int costoMinimo = INT_MAX;

    // Empezar en la ciudad de origen (Nueva York)
    visitado[0] = true;
    tsp(0, 1, 0, 1, &costoMinimo);

    // Imprimir la ruta óptima
    printf("Ruta optima:\n");
    printf("Nueva York -> ");
    for (int i = 0; i < numCiudades; i++) {
        if (rutaOptima[i]) {
            printf("%d -> ", i);
        }
    }
    printf("Nueva York\n");

    return 0;
}


