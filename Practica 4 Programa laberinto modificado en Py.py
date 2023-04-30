def resolver_laberinto(laberinto, inicio, fin):
    # Función auxiliar para determinar si una posición es un movimiento válido.
    # Un movimiento es válido si la posición está dentro de los límites del laberinto,
    # la celda en esa posición no está bloqueada y no se ha visitado antes.
    def es_movimiento_valido(x, y):
        return 0 <= x < len(laberinto) and 0 <= y < len(laberinto[0]) and laberinto[x][y] == 0

    # Función auxiliar para realizar la búsqueda en profundidad (DFS).
    # El algoritmo DFS se utiliza para encontrar el camino más corto desde el inicio hasta el fin.
    # La función devuelve una lista de tuplas que representan el camino desde el inicio hasta el fin.
    def dfs(x, y):
        if (x, y) == fin:
            return [(x, y)]

        laberinto[x][y] = 2  # Marcar la celda como visitada
        for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if es_movimiento_valido(nx, ny):
                camino = dfs(nx, ny)
                if camino:
                    return [(x, y)] + camino

        return None

    return dfs(*inicio)


# Ejemplo de uso
laberinto = [
    [0, 0, 0, 1, 0, 0, 0, 0],
    [1, 1, 0, 1, 0, 1, 1, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 1, 1, 0],
    [0, 0, 0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 1, 1, 0],
    [0, 0, 0, 1, 1, 1, 0, 0],
]

inicio = (0, 0)
fin = (6, 7)

# Llamar a la función resolver_laberinto para obtener el camino más corto desde el inicio hasta el fin.
camino = resolver_laberinto(laberinto, inicio, fin)

# Verificar si se encontró una solución e imprimir el camino si se encontró.
if camino:
    print("¡Laberinto resuelto! Camino:", camino)
else:
    print("No se encontró una solución.")
