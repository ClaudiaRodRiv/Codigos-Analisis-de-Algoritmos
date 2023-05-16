#include <stdio.h>
#include <math.h>

// Estructura para representar cada punto (x, y)
struct Punto {
    double x;
    double y;
};

// Función principal del programa
int main() {
    int n;
    struct Punto puntos[1000];

    // Pedir al usuario que ingrese el número de puntos a procesar
    printf("Cuantos puntos va a ingresar: ");
    scanf("%d", &n);

    // Pedir al usuario que ingrese cada uno de los puntos, separados por espacios
    printf("\nIngrese los puntos (x, y) separados por un espacio:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &puntos[i].x, &puntos[i].y);
    }

    // Calcular la distancia entre cada par de puntos y encontrar la distancia mínima
    double distancia_minima = sqrt(pow(puntos[0].x - puntos[1].x, 2) + pow(puntos[0].y - puntos[1].y, 2));
    int indice_punto_1 = 0, indice_punto_2 = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = sqrt(pow(puntos[i].x - puntos[j].x, 2) + pow(puntos[i].y - puntos[j].y, 2));
            if (d < distancia_minima) {
                distancia_minima = d;
                indice_punto_1 = i;
                indice_punto_2 = j;
            }
        }
    }

    // Imprimir los puntos más cercanos
    printf("\nLos puntos mas cercanos son: (%g, %g) y (%g, %g)\n",
           puntos[indice_punto_1].x, puntos[indice_punto_1].y, puntos[indice_punto_2].x, puntos[indice_punto_2].y);

    // Indicar que el programa se ha ejecutado correctamente
    return 0;
}





