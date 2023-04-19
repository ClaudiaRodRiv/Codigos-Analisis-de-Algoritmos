#include <stdio.h>

// Función factorial recursiva
int factorial(int n) {
    // Caso base: Si n es igual a 0, entonces el factorial es 1
    if (n == 0) {
        return 1;
    }
    // Caso recursivo: Si n no es igual a 0, entonces el factorial es n * (n-1)!
    else {
        return n * factorial(n-1);
    }
}

int main() {
    int n;
    // Pedir al usuario que ingrese un entero no negativo
    printf("Ingresa un entero no negativo: ");
    scanf("%d", &n);
    // Calcular el factorial del número ingresado y mostrarlo en pantalla
    printf("\nEl factorial de %d es %d\n", n, factorial(n));
    return 0;
}


