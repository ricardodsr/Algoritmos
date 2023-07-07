# Heap Sort
O Heap Sort é um algoritmo de classificação baseado em estruturas de dados chamadas "heaps", que são árvores binárias especiais. Ele utiliza a propriedade de um heap, em que o elemento pai de cada nó é sempre maior ou igual aos elementos filhos, para ordenar os elementos em uma lista.

# Processo
1- Construção do Heap: O algoritmo constrói um heap máximo a partir da lista desordenada. Isso envolve rearranjar os elementos da lista para que a propriedade do heap seja satisfeita. A construção começa do final da lista e vai até o início, percorrendo os elementos em ordem reversa.

2- Extração do Máximo: O algoritmo remove o elemento máximo do heap (que é o primeiro elemento da lista) e o coloca no final da lista. Em seguida, reconstrói o heap para os elementos restantes.

3- Repetição: Os passos 2 e 3 são repetidos até que todos os elementos tenham sido extraídos e a lista esteja completamente ordenada.

# Codigo Fonte Python

    def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

 A função heapify é responsável por garantir a propriedade do heap para um nó específico. Ela recebe a lista arr, o tamanho do heap n e o índice do nó i. A função compara o nó i com seus filhos esquerdo (left) e direito (right), e se necessário, troca o nó com o filho de maior valor. Esse processo é realizado recursivamente para garantir que todo o heap esteja em ordem.

A função heap_sort realiza o processo de construção do heap inicial chamando a função heapify para todos os nós não folha. Em seguida, o algoritmo realiza a extração do máximo, trocando o primeiro elemento (máximo) com o último elemento da lista e ajustando o heap com a função heapify. Isso é repetido até que todos os elementos estejam ordenados.

O Heap Sort é um algoritmo de classificação eficiente com complexidade de tempo O(n log n) em todos os casos. Ele é adequado para classificar grandes conjuntos de dados e também possui a vantagem de ser in-place, ou seja, não requer espaço adicional para armazenar os elementos durante o processo de classificação.