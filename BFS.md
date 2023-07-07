# BSF ou Busca em Largura
Breadth-First Search, ou Busca em Largura, é um algoritmo utilizado para percorrer ou buscar em uma estrutura de dados, como uma árvore ou um grafo, de forma sistematizada. Ele explora todos os vértices vizinhos de um vértice inicial antes de avançar para os vértices mais distantes.

# Breadth-First Search (BFS) - Método Iterativo:
O método Iterativo do BFS utiliza uma fila para rastrear os vértices que precisam ser explorados. Aqui está um exemplo de implementação:

# Codigo Fonte python

    from collections import deque
    def bfs_iterative(graph, start):
        visited = set()
        queue = deque([start])

        while queue:
            vertex = queue.popleft()
            print(vertex)  # Aqui, você pode realizar as ações desejadas com o vértice

            if vertex not in visited:
                visited.add(vertex)
                neighbors = graph[vertex]
                queue.extend(neighbors)

Começamos por definir um conjunto visited para armazenar os vértices visitados e uma fila queue para armazenar os vértices a serem explorados. Inicialmente, colocamos o vértice de partida na fila. Em cada iteração do loop, removemos o primeiro vértice da fila utilizando o método popleft() e realizamos as ações desejadas com esse vértice. Em seguida, verificamos se o vértice já foi visitado. Se não tiver sido visitado, adicionamos o vértice ao conjunto visited e adicionamos os vizinhos desse vértice na fila utilizando o método extend(). Esse processo é repetido até que a fila esteja vazia, o que indica que todos os vértices foram explorados.

# Breadth-First Search (BFS) - Método Recursivo:
O método Recursivo do BFS não é comumente utilizado, já que o algoritmo em si é naturalmente implementado de forma iterativa. No entanto, é possível realizar uma implementação recursiva do BFS utilizando chamadas recursivas. Aqui está um exemplo de implementação:

# Codigo Fonte python

    def bfs_recursive(graph, queue, visited):
    if not queue:
        return

    vertex = queue.pop(0)
    print(vertex)  # Aqui, você pode realizar as ações desejadas com o vértice

    if vertex not in visited:
        visited.add(vertex)
        neighbors = graph[vertex]
        queue.extend(neighbors)

    bfs_recursive(graph, queue, visited)

A função bfs_recursive é chamada recursivamente para realizar o BFS. Ela recebe o grafo, a fila e o conjunto visited como parâmetros. Se a fila estiver vazia, a recursão é encerrada. Caso contrário, removemos o primeiro vértice da fila utilizando o método pop(0) e realizamos as ações desejadas com esse vértice. Em seguida, verificamos se o vértice já foi visitado. Se não tiver sido visitado, adicionamos o vértice ao conjunto visited e adicionamos os vizinhos desse vértice na fila utilizando o método extend(). Chamamos então a função recursivamente para continuar o processo até que a fila esteja vazia.

É importante ressaltar que a implementação recursiva do BFS pode consumir mais recursos devido às chamadas recursivas e ao uso de uma fila como argumento, o que pode levar a um estouro de pilha (stack overflow) em casos de grafos muito grandes ou complexos.