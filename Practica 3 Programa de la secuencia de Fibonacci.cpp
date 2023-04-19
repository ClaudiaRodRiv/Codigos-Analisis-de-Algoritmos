#include <stdio.h>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm; // Declaraci�n de variables

    printf("Ingresa el numero de terminos que deseas mostrar: "); // Pedimos al usuario ingresar el n�mero de t�rminos que desea mostrar
    scanf("%d", &n); // Escaneamos el n�mero de t�rminos ingresado por el usuario y lo almacenamos en la variable 'n'

    printf("\nSecuencia de Fibonacci: "); // Imprimimos el encabezado de la secuencia de Fibonacci

    for (int i = 1; i <= n; i++) { // Iteramos desde 1 hasta el n�mero de t�rminos ingresado por el usuario
        printf("%d, ", t1); // Imprimimos el t�rmino actual de la secuencia
        nextTerm = t1 + t2; // Calculamos el siguiente t�rmino de la secuencia sumando los dos t�rminos anteriores
        t1 = t2; // Actualizamos el valor de 't1' con el valor actual de 't2'
        t2 = nextTerm; // Actualizamos el valor de 't2' con el valor actual de 'nextTerm'
    }

    return 0; // Indicamos que el programa se ha ejecutado correctamente
}


