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

# Binary Search Algorithm - Método Recursivo:
O método Recursivo do algoritmo de Busca Binária utiliza chamadas recursivas para dividir o conjunto de dados em partes menores até encontrar o elemento desejado ou determinar que ele não está presente. Aqui está um exemplo de implementação:

# Codigo Fonte Python

    def binary_search_recursive(arr, target, low, high):
    if low > high:
        return -1

    mid = (low + high) // 2

    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search_recursive(arr, target, mid + 1, high)
    else:
        return binary_search_recursive(arr, target, low, mid - 1)

Neste método, a função binary_search_recursive é chamada recursivamente para realizar a busca binária. Ela recebe os parâmetros arr (conjunto de dados), target (elemento alvo), low (limite inferior) e high (limite superior). A função verifica se o limite inferior é maior do que o limite superior, o que indica que o elemento não está presente. Caso contrário, calculamos o índice médio (mid) e comparamos o valor no índice médio com o valor alvo. Se eles são iguais, retornamos o índice médio. Caso contrário, chamamos a função recursivamente para a metade esquerda ou direita do conjunto de dados, dependendo do valor alvo ser menor ou maior que o valor no índice médio.