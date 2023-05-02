# Programa en Python para la implementación de MergeSort

import random
def mergeSort(arr):
	if len(arr) > 1:

		# Encontrar la mitad de la matriz
		mid = len(arr)//2

		# Dividiendo los elementos del arreglo
		L = arr[:mid]

		# en 2 mitades
		R = arr[mid:]

		# Ordenando la primera mitad
		mergeSort(L)

		# Ordenando la segunda mitad
		mergeSort(R)

		i = j = k = 0

		# Copiar datos a matrices temporales L[] and R[]
		while i < len(L) and j < len(R):
			if L[i] <= R[j]:
				arr[k] = L[i]
				i += 1
			else:
				arr[k] = R[j]
				j += 1
			k += 1

		# Comprobando si quedó algún elemento
		while i < len(L):
			arr[k] = L[i]
			i += 1
			k += 1

		while j < len(R):
			arr[k] = R[j]
			j += 1
			k += 1

# Para imprimir la lista

def printList(arr):
	for i in range(len(arr)):
		print(arr[i], end=" ")
	print()


# código de conductor, modificado el arreglo a 10k valores
if __name__ == '__main__':
    arr = [random.randint(0, 10000) for i in range(10000)]
    print("El arreglo es:", end="\n")
    printList(arr)
    mergeSort(arr)
    print("El arreglo ordenado: ", end="\n")
    printList(arr)



