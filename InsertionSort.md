# Insertion Sort
O Insertion Sort é um algoritmo simples de classificação que percorre uma lista de elementos e, a cada iteração, insere um elemento na posição correta em uma sublista já ordenada. Ele é semelhante ao processo de ordenação de cartas em uma mão de baralho.

# Processo

1- Divisão em sublistas: O algoritmo divide a lista em duas partes: uma sublista já ordenada e uma sublista não ordenada. Inicialmente, a sublista ordenada contém apenas o primeiro elemento da lista, enquanto a sublista não ordenada contém o restante dos elementos.

2- Seleção do elemento: O algoritmo seleciona o próximo elemento da sublista não ordenada.

3- Inserção na posição correta: O elemento selecionado é inserido na posição correta na sublista ordenada, deslocando os elementos maiores para a direita. Para encontrar a posição correta, o algoritmo compara o elemento selecionado com os elementos da sublista ordenada, começando do último elemento e movendo-se para a esquerda até encontrar uma posição em que o elemento selecionado seja maior.

4- Repetição: Os passos 2 e 3 são repetidos até que todos os elementos da sublista não ordenada sejam inseridos na sublista ordenada. Ao final do processo, a lista estará completamente ordenada.

# Codigo fonte interativo em Python

        # Function to perform insertion sort on a list
    def insertionSort(A):
    
        # Start from the second element
        # (the element at index 0 is already sorted)
        for i in range(1, len(A)):
    
            value = A[i]
            j = i
    
            # find index `j` within the sorted subset `A[0…i-1]`
            # where element `A[i]` belongs
            while j > 0 and A[j - 1] > value:
                A[j] = A[j - 1]
                j = j - 1
    
            # Note that sublist `A[j…i-1]`is shifted to
            # the right by one position, i.e., `A[j+1…i]`
    
            A[j] = value
    
    
    if __name__ == '__main__':
    
        A = [3, 8, 5, 4, 1, 9, -2]
    
        insertionSort(A)
    
        # print the sorted list
        print(A)

# Codigo Fonte recursivo em Python

        # Recursive function to perform insertion sort on sublist `A[i…n]`
    def insertionSort(A, i, n):
    
        value = A[i]
        j = i
    
        # find index `j` within the sorted subset `A[0…i-1]`
        # where element `A[i]` belongs
        while j > 0 and A[j - 1] > value:
            A[j] = A[j - 1]
            j = j - 1
    
        A[j] = value
    
        # Note that sublist `A[j…i-1]`is shifted to
        # the right by one position, i.e., `A[j+1…i]`
    
        if i + 1 <= n:
            insertionSort(A, i + 1, n)
    
    
    if __name__ == '__main__':
    
        A = [3, 8, 5, 4, 1, 9, -2]
    
        # start from the second element (the element at index 0 is already sorted)
        insertionSort(A, 1, len(A) - 1)
    
        # print the sorted list
        print(A)

O Insertion Sort é eficiente para classificar pequenas listas ou quando a lista já está quase ordenada. No entanto, sua complexidade de tempo média é O(n^2), onde n é o número de elementos a serem classificados. Portanto, para listas grandes, outros algoritmos de classificação, como o Merge Sort ou o Quick Sort, geralmente são preferidos.