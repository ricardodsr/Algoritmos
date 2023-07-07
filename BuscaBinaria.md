# Busca Binaria

A Busca Binária é um algoritmo eficiente para encontrar um elemento em um conjunto ordenado de dados. Ele segue uma abordagem de dividir e conquistar, reduzindo pela metade o espaço de busca a cada etapa. Os métodos Iterativo e Recursivo são duas maneiras diferentes de implementar esse algoritmo.

# Binary Search Algorithm - Método Iterativo:
O método Iterativo do algoritmo de Busca Binária utiliza um loop para iterar sobre o conjunto de dados até encontrar o elemento desejado ou determinar que ele não está presente. Aqui está um exemplo de implementação:
    
# Codigo Fonte Python
    def binary_search_iterative(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1

Neste método, começamos definindo um intervalo de busca, representado pelas variáveis low (limite inferior) e high (limite superior). Em cada iteração, calculamos o índice médio (mid) do intervalo atual. Comparamos o valor no índice médio com o valor alvo. Se eles são iguais, retornamos o índice médio. Caso contrário, ajustamos os limites low e high dependendo se o valor alvo é maior ou menor que o valor no índice médio. Repetimos esse processo até encontrar o elemento desejado ou determinar que ele não está presente.
