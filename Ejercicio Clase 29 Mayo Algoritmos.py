def best_fit(blockSize, m, processSize, n):
    allocation = [-1] * n  # Lista para almacenar la asignación de memoria
    # Recorrer todos los procesos
    for i in range(n):
        bestIdx = -1
        # Buscar el bloque de memoria más pequeño que sea suficiente para el proceso actual
        for j in range(m):
            if blockSize[j] >= processSize[i]:
                if bestIdx == -1:
                    bestIdx = j
                elif blockSize[j] < blockSize[bestIdx]:
                    bestIdx = j
        # Si se encuentra un bloque adecuado, asignar el proceso a ese bloque y actualizar el tamaño restante
        if bestIdx != -1:
            allocation[i] = bestIdx
            blockSize[bestIdx] -= processSize[i]
    # Mostrar la asignación de memoria
    print("Proceso\tTamaño\tBloque")
    for i in range(n):
        print(i, "\t", processSize[i], end="\t")
        if allocation[i] != -1:
            print(allocation[i])
        else:
            print("No se asignó memoria")

# Ejemplo de uso
blockSize = [100, 500, 200, 300, 600]
processSize = [212, 417, 112, 426]
m = len(blockSize)
n = len(processSize)
best_fit(blockSize, m, processSize, n)
