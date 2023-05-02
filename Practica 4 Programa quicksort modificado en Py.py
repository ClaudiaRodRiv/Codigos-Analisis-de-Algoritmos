# Implementación Python3 de QuickSort

# Función para encontrar la posición de la partición
def partition(array, low, high):

	# Elija el elemento más a la derecha como pivote
	pivot = array[high]

	# Puntero para elemento mayor
	i = low - 1

	# Recorrer todos los elementos
	# comparar cada elemento con pivote
	for j in range(low, high):
		if array[j] <= pivot:

			# Si se encuentra un elemento más pequeño que el pivote
			# Intercambiarlo con el elemento mayor 
			i = i + 1

			# Intercambiando elemento en i con elemento en j
			(array[i], array[j]) = (array[j], array[i])

	# Intercambiar el elemento pivote con
	# El elemento mayor especificado por i
	(array[i + 1], array[high]) = (array[high], array[i + 1])

	# Devuelve la posición desde donde se realiza la partición
	return i + 1


# Función para realizar ordenación rápida
def quicksort(array, low, high):
	if low < high:

		# Encuentra un elemento pivote tal que:
		# Elementos más pequeños que el pivote están a la izquierda
		# Elementos mayores que el pivote están a la derecha
		pi = partition(array, low, high)

		# Llamada recursiva a la izquierda del pivote
		quicksort(array, low, pi - 1)

		# Llamada recursiva a la derecha del pivote
		quicksort(array, pi + 1, high)


# Driver code
import random

# Generar una matriz aleatoria de 10,000 elementos
array = [random.randint(0, 9999) for i in range(10000)]

# Obtener la longitud de la matriz
N = len(array)

# Llamada de función 
quicksort(array, 0, N - 1)
print('Sorted array:')
for x in array:
    print(x, end=" ")

# This code is contributed by Adnan Aliakbar, modificado Braulio Diaz