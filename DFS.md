# Depth-First Search, ou Busca em Profundidade.
Depth-First Search, ou Busca em Profundidade, é um algoritmo utilizado para percorrer ou buscar em uma estrutura de dados, como uma árvore ou um grafo, explorando o máximo possível em uma ramificação antes de retroceder. Ele segue uma abordagem mais "profunda" antes de explorar as outras ramificações.

# Depth-First Search (DFS) - Método Iterativo
O método Iterativo do DFS utiliza uma pilha para rastrear os vértices que precisam ser explorados. Aqui está um exemplo de implementação:

# Codigo Fonte
    def dfs_iterative(graph, start):
    visited = set()
    stack = [start]

    while stack:
        vertex = stack.pop()
        print(vertex)  # Aqui, você pode realizar as ações desejadas com o vértice

        if vertex not in visited:
            visited.add(vertex)
            neighbors = graph[vertex]
            stack.extend(neighbors)

Começamos definindo um conjunto visited para armazenar os vértices visitados e uma pilha stack para armazenar os vértices a serem explorados. Inicialmente, colocamos o vértice de partida na pilha. Em cada iteração do loop, removemos o último vértice da pilha utilizando o método pop() e realizamos as ações desejadas com esse vértice. Em seguida, verificamos se o vértice já foi visitado. Se não tiver sido visitado, adicionamos o vértice ao conjunto visited e adicionamos os vizinhos desse vértice na pilha utilizando o método extend(). Esse processo é repetido até que a pilha esteja vazia, o que indica que todos os vértices foram explorados.

# Depth-First Search (DFS) - Método Recursivo
O método Recursivo do DFS utiliza chamadas recursivas para explorar os vértices em uma estrutura de dados. Aqui está um exemplo de implementação:

# Codigo Fonte

    def dfs_recursive(graph, vertex, visited):
    print(vertex)  # Aqui, você pode realizar as ações desejadas com o vértice

    visited.add(vertex)
    neighbors = graph[vertex]

    for neighbor in neighbors:
        if neighbor not in visited:
            dfs_recursive(graph, neighbor, visited)

A função dfs_recursive é chamada recursivamente para realizar o DFS. Ela recebe o grafo, o vértice inicial e o conjunto visited como parâmetros. Realizamos as ações desejadas com o vértice inicial. Em seguida, adicionamos o vértice ao conjunto visited e obtemos os vizinhos desse vértice a partir do grafo. Percorremos cada vizinho e, se o vizinho ainda não tiver sido visitado, chamamos a função recursivamente para explorar esse vizinho. Essa chamada recursiva ocorre até que todos os vértices sejam visitados.

É importante ressaltar que a implementação recursiva do DFS pode consumir mais recursos devido às chamadas recursivas, o que pode levar a um estouro de pilha (stack overflow) em casos de grafos muito grandes ou complexos. Portanto, é recomendado utilizar a versão iterativa para grafos extensos.