# Dijkstra’s
O algoritmo de Dijkstra é um algoritmo clássico para encontrar o caminho mais curto em um grafo ponderado, direcionado ou não direcionado, com pesos não negativos. Ele recebe esse nome em homenagem ao cientista da computação holandês Edsger Dijkstra, que o desenvolveu em 1956.

# Processo
1- Inicialização: O algoritmo atribui um valor de distância inicial para todos os vértices do grafo. Geralmente, o valor inicial é infinito para todos os vértices, exceto o vértice de partida, para o qual a distância inicial é definida como zero.

2- Seleção do vértice: O algoritmo seleciona o vértice de menor distância entre os vértices não visitados. Inicialmente, esse vértice será o vértice de partida.

3- Relaxamento das arestas: O algoritmo atualiza as distâncias dos vértices vizinhos ao vértice selecionado, se for possível alcançá-los por meio de uma aresta com um peso menor do que a distância atualmente registrada. Isso é conhecido como "relaxamento" das arestas.

4- Marcação do vértice: Após o relaxamento das arestas, o vértice selecionado é marcado como visitado e não será considerado novamente.

5- Repetição: Os passos 2 a 4 são repetidos até que todos os vértices sejam visitados ou até que o vértice de destino seja alcançado.

6 -Resultado: Após a conclusão do algoritmo, a menor distância para cada vértice é determinada. Além disso, o caminho mais curto de um vértice de partida a qualquer outro vértice pode ser reconstruído usando as informações armazenadas durante o processo.

O algoritmo de Dijkstra é frequentemente implementado utilizando uma estrutura de dados chamada "fila de prioridade" (priority queue), que permite recuperar eficientemente o vértice não visitado de menor distância a cada iteração.

# Codigo Fonte Python
    import heapq

    def dijkstra(graph, start):
        distances = {vertex: float('inf') for vertex in graph}
        distances[start] = 0

        pq = [(0, start)]

        while pq:
            current_distance, current_vertex = heapq.heappop(pq)

            if current_distance > distances[current_vertex]:
                continue

            for neighbor, weight in graph[current_vertex].items():
                distance = current_distance + weight

                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(pq, (distance, neighbor))

        return distances

A função dijkstra recebe o grafo representado por um dicionário, onde as chaves são os vértices e os valores são outros dicionários contendo os vizinhos e os pesos das arestas. A função inicializa um dicionário distances com valores infinitos para todos os vértices, exceto o vértice de partida, que é definido como zero. A fila de prioridade pq é usada para armazenar as distâncias e os vértices não visitados. O algoritmo itera pela fila de prioridade, atualizando as distâncias e visitando os vértices conforme necessário.

# Codigo Fonte Python 2

    import sys
    from heapq import heappop, heappush


    # A class to store a heap node
    class Node:
        def __init__(self, vertex, weight=0):
            self.vertex = vertex
            self.weight = weight

        # Override the __lt__() function to make `Node` class work with a min-heap
        def __lt__(self, other):
            return self.weight < other.weight


    # A class to represent a graph object
    class Graph:
        def __init__(self, edges, n):
            # allocate memory for the adjacency list
            self.adjList = [[] for _ in range(n)]

            # add edges to the directed graph
            for (source, dest, weight) in edges:
                self.adjList[source].append((dest, weight))


    def get_route(prev, i, route):
        if i >= 0:
            get_route(prev, prev[i], route)
            route.append(i)


    # Run Dijkstra’s algorithm on a given graph
    def findShortestPaths(graph, source, n):

        # create a min-heap and push source node having distance 0
        pq = []
        heappush(pq, Node(source))

        # set initial distance from the source to `v` as infinity
        dist = [sys.maxsize] * n

        # distance from the source to itself is zero
        dist[source] = 0

        # list to track vertices for which minimum cost is already found
        done = [False] * n
        done[source] = True

        # stores predecessor of a vertex (to a print path)
        prev = [-1] * n

        # run till min-heap is empty
        while pq:

            node = heappop(pq)  	# Remove and return the best vertex
            u = node.vertex 		# get the vertex number

            # do for each neighbor `v` of `u`
            for (v, weight) in graph.adjList[u]:
                if not done[v] and (dist[u] + weight) < dist[v]:		# Relaxation step
                    dist[v] = dist[u] + weight
                    prev[v] = u
                    heappush(pq, Node(v, dist[v]))

            # mark vertex `u` as done so it will not get picked up again
            done[u] = True

        route = []
        for i in range(n):
            if i != source and dist[i] != sys.maxsize:
                get_route(prev, i, route)
                print(f'Path ({source} —> {i}): Minimum cost = {dist[i]}, Route = {route}')
                route.clear()


    if __name__ == '__main__':

        # initialize edges as per the above diagram
        # (u, v, w) represent edge from vertex `u` to vertex `v` having weight `w`
        edges = [(0, 1, 10), (0, 4, 3), (1, 2, 2), (1, 4, 4), (2, 3, 9), (3, 2, 7),
                (4, 1, 1), (4, 2, 8), (4, 3, 2)]

        # total number of nodes in the graph (labelled from 0 to 4)
        n = 5

        # construct graph
        graph = Graph(edges, n)

        # run the Dijkstra’s algorithm from every node
        for source in range(n):
            findShortestPaths(graph, source, n)

# Codigo Fonte Java

    import java.util.*;
    
    // A class to store a graph edge
    class Edge
    {
        int source, dest, weight;
    
        public Edge(int source, int dest, int weight)
        {
            this.source = source;
            this.dest = dest;
            this.weight = weight;
        }
    }
    
    // A class to store a heap node
    class Node
    {
        int vertex, weight;
    
        public Node(int vertex, int weight)
        {
            this.vertex = vertex;
            this.weight = weight;
        }
    }
    
    // A class to represent a graph object
    class Graph
    {
        // A list of lists to represent an adjacency list
        List<List<Edge>> adjList = null;
    
        // Constructor
        Graph(List<Edge> edges, int n)
        {
            adjList = new ArrayList<>();
    
            for (int i = 0; i < n; i++) {
                adjList.add(new ArrayList<>());
            }
    
            // add edges to the directed graph
            for (Edge edge: edges) {
                adjList.get(edge.source).add(edge);
            }
        }
    }
    
    class Main
    {
        private static void getRoute(int[] prev, int i, List<Integer> route)
        {
            if (i >= 0)
            {
                getRoute(prev, prev[i], route);
                route.add(i);
            }
        }
    
        // Run Dijkstra’s algorithm on a given graph
        public static void findShortestPaths(Graph graph, int source, int n)
        {
            // create a min-heap and push source node having distance 0
            PriorityQueue<Node> minHeap;
            minHeap = new PriorityQueue<>(Comparator.comparingInt(node -> node.weight));
            minHeap.add(new Node(source, 0));
    
            // set initial distance from the source to `v` as infinity
            List<Integer> dist;
            dist = new ArrayList<>(Collections.nCopies(n, Integer.MAX_VALUE));
    
            // distance from the source to itself is zero
            dist.set(source, 0);
    
            // boolean array to track vertices for which minimum
            // cost is already found
            boolean[] done = new boolean[n];
            done[source] = true;
    
            // stores predecessor of a vertex (to a print path)
            int[] prev = new int[n];
            prev[source] = -1;
    
            // run till min-heap is empty
            while (!minHeap.isEmpty())
            {
                // Remove and return the best vertex
                Node node = minHeap.poll();
    
                // get the vertex number
                int u = node.vertex;
    
                // do for each neighbor `v` of `u`
                for (Edge edge: graph.adjList.get(u))
                {
                    int v = edge.dest;
                    int weight = edge.weight;
    
                    // Relaxation step
                    if (!done[v] && (dist.get(u) + weight) < dist.get(v))
                    {
                        dist.set(v, dist.get(u) + weight);
                        prev[v] = u;
                        minHeap.add(new Node(v, dist.get(v)));
                    }
                }
    
                // mark vertex `u` as done so it will not get picked up again
                done[u] = true;
            }
    
            List<Integer> route = new ArrayList<>();
    
            for (int i = 0; i < n; i++)
            {
                if (i != source && dist.get(i) != Integer.MAX_VALUE)
                {
                    getRoute(prev, i, route);
                    System.out.printf("Path (%d —> %d): Minimum cost = %d, Route = %s\n",
                                    source, i, dist.get(i), route);
                    route.clear();
                }
            }
        }
    
        public static void main(String[] args)
        {
            // initialize edges as per the above diagram
            // (u, v, w) represent edge from vertex `u` to vertex `v` having weight `w`
            List<Edge> edges = Arrays.asList(
                    new Edge(0, 1, 10), new Edge(0, 4, 3), new Edge(1, 2, 2),
                    new Edge(1, 4, 4), new Edge(2, 3, 9), new Edge(3, 2, 7),
                    new Edge(4, 1, 1), new Edge(4, 2, 8), new Edge(4, 3, 2)
            );
    
            // total number of nodes in the graph (labelled from 0 to 4)
            int n = 5;
    
            // construct graph
            Graph graph = new Graph(edges, n);
    
            // run the Dijkstra’s algorithm from every node
            for (int source = 0; source < n; source++) {
                findShortestPaths(graph, source, n);
            }
        }
    }

# Codigo Fonte C++

    #include <iostream>
    #include <vector>
    #include <queue>
    #include <climits>
    using namespace std;
    
    // Data structure to store a graph edge
    struct Edge {
        int source, dest, weight;
    };
    
    // Data structure to store a heap node
    struct Node {
        int vertex, weight;
    };
    
    // A class to represent a graph object
    class Graph
    {
    public:
        // a vector of vectors of `Edge` to represent an adjacency list
        vector<vector<Edge>> adjList;
    
        // Graph Constructor
        Graph(vector<Edge> const &edges, int n)
        {
            // resize the vector to hold `n` elements of type vector<Edge>
            adjList.resize(n);
    
            // add edges to the directed graph
            for (Edge const &edge: edges)
            {
                // insert at the end
                adjList[edge.source].push_back(edge);
            }
        }
    };
    
    void printPath(vector<int> const &prev, int i, int source)
    {
        if (i < 0) {
            return;
        }
        printPath(prev, prev[i], source);
        if (i != source) {
            cout << ", ";
        }
        cout << i;
    }
    
    // Comparison object to be used to order the heap
    struct comp
    {
        bool operator()(const Node &lhs, const Node &rhs) const {
            return lhs.weight > rhs.weight;
        }
    };
    
    // Run Dijkstra’s algorithm on the given graph
    void findShortestPaths(Graph const &graph, int source, int n)
    {
        // create a min-heap and push source node having distance 0
        priority_queue<Node, vector<Node>, comp> min_heap;
        min_heap.push({source, 0});
    
        // set initial distance from the source to `v` as infinity
        vector<int> dist(n, INT_MAX);
    
        // distance from the source to itself is zero
        dist[source] = 0;
    
        // boolean array to track vertices for which minimum
        // cost is already found
        vector<bool> done(n, false);
        done[source] = true;
    
        // stores predecessor of a vertex (to a print path)
        vector<int> prev(n, -1);
    
        // run till min-heap is empty
        while (!min_heap.empty())
        {
            // Remove and return the best vertex
            Node node = min_heap.top();
            min_heap.pop();
    
            // get the vertex number
            int u = node.vertex;
    
            // do for each neighbor `v` of `u`
            for (auto i: graph.adjList[u])
            {
                int v = i.dest;
                int weight = i.weight;
    
                // Relaxation step
                if (!done[v] && (dist[u] + weight) < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    min_heap.push({v, dist[v]});
                }
            }
    
            // mark vertex `u` as done so it will not get picked up again
            done[u] = true;
        }
    
        for (int i = 0; i < n; i++)
        {
            if (i != source && dist[i] != INT_MAX)
            {
                cout << "Path (" << source << " —> " << i << "): Minimum cost = "
                    << dist[i] << ", Route = [";
                printPath(prev, i, source);
                cout << "]" << endl;
            }
        }
    }
    
    int main()
    {
        // initialize edges as per the above diagram
        // (u, v, w) represent edge from vertex `u` to vertex `v` having weight `w`
        vector<Edge> edges =
        {
            {0, 1, 10}, {0, 4, 3}, {1, 2, 2}, {1, 4, 4}, {2, 3, 9},
            {3, 2, 7}, {4, 1, 1}, {4, 2, 8}, {4, 3, 2}
        };
    
        // total number of nodes in the graph (labelled from 0 to 4)
        int n = 5;
    
        // construct graph
        Graph graph(edges, n);
    
        // run the Dijkstra’s algorithm from every node
        for (int source = 0; source < n; source++) {
            findShortestPaths(graph, source, n);
        }
    
        return 0;
    }

O algoritmo de Dijkstra é amplamente utilizado em problemas de caminho mais curto, como encontrar a rota mais rápida entre dois pontos em um mapa ou otimizar a rede de transporte. Sua complexidade de tempo é O((V + E) log V), onde V é o número de vértices e E é o número de arestas no grafo.