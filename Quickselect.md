# Quickselect
O Quickselect é um algoritmo relacionado ao Quicksort e é utilizado para encontrar o k-ésimo menor elemento em uma lista não ordenada. Ele segue a abordagem de dividir e conquistar, semelhante ao Quicksort, mas, em vez de ordenar toda a lista, foca apenas na parte relevante para encontrar o k-ésimo menor elemento.

# Processo

1- Escolha do pivô: O algoritmo seleciona um pivô a partir da lista não ordenada. Geralmente, o pivô é escolhido aleatoriamente, mas também pode ser escolhido de outras formas, como o primeiro ou o último elemento da lista.

2- Particionamento: O algoritmo rearranja os elementos da lista de forma que todos os elementos menores que o pivô fiquem à esquerda dele e todos os elementos maiores fiquem à direita. Isso é feito movendo os elementos menores que o pivô para a esquerda e os maiores para a direita.

3- Verificação da posição do pivô: Após o particionamento, o pivô está em sua posição final na lista. Se a posição do pivô for igual a k - 1 (onde k é o índice do elemento desejado), então o elemento pivô é exatamente o k-ésimo menor elemento. Caso contrário, o algoritmo decide em qual parte (esquerda ou direita) continuar a busca, com base na posição do pivô em relação a k - 1.

4- Repetição: Os passos 1 a 3 são repetidos recursivamente para a parte relevante da lista até que o k-ésimo menor elemento seja encontrado.

# Codigo Fonte em Python
    def quickselect(arr, k):
    if k < 1 or k > len(arr):
        return None

    pivot = arr[random.randint(0, len(arr) - 1)]
    smaller = [x for x in arr if x < pivot]
    larger = [x for x in arr if x > pivot]

    if k - 1 < len(smaller):
        return quickselect(smaller, k)
    elif k - 1 >= len(arr) - len(larger):
        return quickselect(larger, k - (len(arr) - len(larger)))
    else:
        return pivot

A função quickselect recebe uma lista arr e o índice do elemento desejado k. A função verifica se o índice é válido e escolhe um pivô aleatório. A partir do pivô, a função divide a lista em duas partes: smaller (elementos menores que o pivô) e larger (elementos maiores que o pivô). Em seguida, o algoritmo decide em qual parte continuar a busca com base na posição do pivô em relação a k - 1. A chamada recursiva é feita para continuar o processo até que o k-ésimo menor elemento seja encontrado.

O Quickselect é um algoritmo eficiente para encontrar o k-ésimo menor elemento em uma lista não ordenada, com complexidade média de tempo O(n), onde n é o número de elementos na lista. Ele pode ser útil em situações em que não é necessário ordenar toda a lista, mas apenas encontrar um elemento específico.