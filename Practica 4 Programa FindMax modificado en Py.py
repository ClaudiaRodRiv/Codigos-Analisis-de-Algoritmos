import random

# Función para encontrar el máximo elemento en un array utilizando Divide y Conquista
def DAC_Max(a, inicio, fin):
    # Si el array tiene sólo un elemento, devolverlo
    if inicio == fin:
        return a[inicio]
    # Si el array tiene dos elementos, devolver el mayor
    if inicio + 1 == fin:
        return max(a[inicio], a[fin])
    # Si el array tiene más de dos elementos, dividirlo en dos y encontrar el máximo de ambas partes
    mitad = (inicio + fin) // 2
    return max(DAC_Max(a, inicio, mitad), DAC_Max(a, mitad+1, fin))

# Función para encontrar el mínimo elemento en un array utilizando Divide y Conquista
def DAC_Min(a, inicio, fin):
    # Si el array tiene sólo un elemento, devolverlo
    if inicio == fin:
        return a[inicio]
    # Si el array tiene dos elementos, devolver el menor
    if inicio + 1 == fin:
        return min(a[inicio], a[fin])
    # Si el array tiene más de dos elementos, dividirlo en dos y encontrar el mínimo de ambas partes
    mitad = (inicio + fin) // 2
    return min(DAC_Min(a, inicio, mitad), DAC_Min(a, mitad+1, fin))

# Driver code para probar las funciones DAC_Max y DAC_Min con un array de 10000 elementos
if __name__ == '__main__':
    # Generar un array de 10000 números aleatorios entre 1 y 1000
    a = [random.randint(1, 1000) for _ in range(10000)]
    
    # Encontrar el máximo y el mínimo utilizando las funciones DAC_Max y DAC_Min
    maximo = DAC_Max(a, 0, len(a)-1)
    minimo = DAC_Min(a, 0, len(a)-1)

    # Imprimir el resultado
    print("El máximo número en el array es:", maximo)
    print("El mínimo número en el array es:", minimo)
