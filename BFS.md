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