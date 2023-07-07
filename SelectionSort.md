# Selection Sort 

O Selection Sort é um algoritmo simples de classificação que encontra repetidamente o menor elemento restante em uma lista não ordenada e o coloca em sua posição correta. Ele percorre a lista várias vezes, dividindo-a em uma parte ordenada e outra não ordenada.

# Selection Sort - Método Iterativo:
No método Iterativo do Selection Sort, a lista é dividida em duas partes: a parte ordenada, que é construída da esquerda para a direita, e a parte não ordenada, que contém os elementos restantes. O algoritmo encontra o menor elemento na parte não ordenada e o coloca na posição correta na parte ordenada.

# Codigo Fonte Python
    def selection_sort_iterative(arr):
    for i in range(len(arr)):
        min_index = i

        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j

        arr[i], arr[min_index] = arr[min_index], arr[i]

Nesya implementação, a função selection_sort_iterative recebe uma lista arr e realiza o processo de seleção iterativo. O primeiro loop for percorre a lista da esquerda para a direita, representando a parte ordenada. A cada iteração, o algoritmo encontra o índice do menor elemento na parte não ordenada (loop for interno) e troca-o com o elemento na posição correta na parte ordenada.

# Selection Sort - Método Recursivo:
No método Recursivo do Selection Sort, o algoritmo utiliza chamadas recursivas para dividir a lista em partes ordenadas e não ordenadas. A cada chamada recursiva, encontra o menor elemento na parte não ordenada e o coloca na posição correta na parte ordenada.

# Codigo Fonte Python
    def selection_sort_recursive(arr, start=0):
    if start >= len(arr) - 1:
        return

    min_index = start

    for i in range(start + 1, len(arr)):
        if arr[i] < arr[min_index]:
            min_index = i

    arr[start], arr[min_index] = arr[min_index], arr[start]

    selection_sort_recursive(arr, start + 1)
A função selection_sort_recursive recebe uma lista arr e um parâmetro opcional start que indica o índice a partir do qual o algoritmo deve começar a ordenação. O caso base da recursão é quando start é maior ou igual ao índice do último elemento da lista. Em cada chamada recursiva, o algoritmo encontra o índice do menor elemento na parte não ordenada e troca-o com o elemento na posição correta na parte ordenada. A chamada recursiva é feita para continuar o processo até que todos os elementos estejam na posição correta.

O Selection Sort é um algoritmo de classificação simples, mas não é muito eficiente em grandes listas devido à sua complexidade de tempo quadrática O(n^2). No entanto, pode ser útil em casos específicos em que o número de elementos é pequeno ou quando é necessário minimizar o número de trocas de elementos.