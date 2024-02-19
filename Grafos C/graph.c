#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAXV    20 // Not really needed. Or used...

typedef enum clr { WHT, GRY, BLK } Color;

typedef struct edge{
    int cost;
    int dest;
    struct edge *next;
} *Edge;

typedef struct graph {
    int size;
    Edge *e;
} *Graph;

/* IMPLEMENTATION NOTE:
To allow multiple sized graphs, a Graph is essentially a pointer to a structure.
That structure contains the size of the Graph and an array of pointers to Edges.
Each index of the array contains the adjacents to that node.

e.g. Node 1 can have 2 and 3 as its adjacents.
So, the cell with index 1 would contain a pointer to an Edge that contains 2, its cost and a pointer to another Edge,
which contains 3, its cost and a pointer to NULL.
*/

Graph newGraph (int size) {
    Graph g = (Graph) malloc( sizeof (struct graph) );
    g -> e = (Edge *) malloc ( sizeof (Edge) * size);

    for (int i = 0; i < size; g->e[i++] = NULL);

    return g;
}

void delGraph (Graph bird) {
    free(bird -> e);
    free(bird); // badumm tss!
}

int addEdge(Graph g, int parent, int destination, int cost) {

    Edge new = (Edge) malloc( sizeof (struct edge) );

    new -> dest = destination;
    new -> cost = cost;
    new -> next = g->e[parent];
    g->e[parent] = new;

    g->size++;

    return 0;
}

void printGraph (Graph g) {

    for (int i = 0; i < g->size; i++) {
        printf("EDGE: %d\n", i);

        if ( !g->e[i] )
            printf("DOESN'T CONNECT ANYWHERE\n");
        else
            for (Edge aux = g->e[i]; aux; aux = aux -> next)
                printf("CONNECTS TO: %d, WITH A COST OF: %d\n", aux->dest, aux->cost);
    }
}

// Test 2 2013 Ex. 2
/* Starting from a v node, count how many nodes we can reach, that are under a distance of N, assuming costs as 1*/
int succN (Graph g, int v, int N) {
    Color color[g->size]; /* Create color array. This is needed because if a node is already in the queue,
                            we don't want to visit it again (because we can update the distances badly) */
    int nr_edges = -1; // Final result starts in -1 because we don't want to count the starting node as reachable
    int dist[g->size];

    for (int i = 0; i < g->size; color[i++] = WHT, dist[i] = 0); // Initalizing color and distances arys

    Queue q = initQueue(15);
    queueEnqueue (&q, v);

    // Starting the algorithm
    while ( !queueEmpty(q) ) {
        int current;
        queueDequeue(&q, &current); // Get a node

        if (dist[current] > N) // Since we're using BFS, any node from now on has a distance > N, so we don't want that
            break;
        else
            nr_edges++; // Otherwise we obtained a reachable node, must update the count

        for (Edge aux = g -> e[current]; aux; aux = aux -> next) { // Go through its adjacents

            if (color[aux -> dest] == WHT) { // If they aren't on the queue
                queueEnqueue(&q, aux->dest); // Add
                dist[aux->dest] = dist[current] + 1; // Update distances
                color[aux->dest] = GRY; // Mark them as "on the queue"
            }
        }

        color[current] = BLK; // We're through with this node, let's never look at it again

    }

    delQueue(&q); // Better free that memory space
    return nr_edges;

}

// Exame Recurso 2013 - Ex. 4
// Determine if a path between 2 nodes exists, only by going through links superior to a given value (lower_lim).
// Maximizing the amount of water connected through pipes between two places.
int waterLink (Graph g, int source, int destination, int lower_lim) {
    Color color[g->size];

    for (int i = 0; i < g->size; color[i++] = WHT); // Initialize colors array

    Queue q = initQueue(15);
    queueEnqueue(&q, source); // Enqueue the first

    while ( ! queueEmpty(q) ) {
        int current;
        queueDequeue(&q, &current); // Remove one element

        for (Edge aux = g->e[current]; aux; aux = aux -> next) {

            if (color[aux -> dest] == WHT) { // If we haven't visited that node and it isn't on the queue

                if (aux -> cost > lower_lim) { // We are only interested in this node if the cost of getting to it is superior to our lower_lim

                    if (aux -> dest == destination) return 1; // If we have found our destination success!

                    queueEnqueue(&q, aux->dest); // Otherwise, carry on my wayward son
                    color[aux -> dest] = GRY; // Must set node as "in queue"

                }

            }
        }

        color[current] = BLK; // We're through with this node, let's never see it again
    }

    delQueue(&q); // We should delete this space
    return 0; // If we got this far, we weren't able to find anything. Let us cry somewhere else
}

// Extra exercise - similar to succN
// Discover if there's any connection between two nodes in a distance inferior to max_dist
int limitedSearch (Graph g, int source, int destination, int max_dist) {
    Color color[g->size];
    int dist[g->size];

    for (int i = 0; i < g->size; color[i++] = WHT, dist[i] = 0);

    Queue q = initQueue(15);
    queueEnqueue(&q, source);

    // Same strategy as before
    while ( !queueEmpty(q) ) {

        int current;
        queueDequeue(&q, &current); // Get a node

        for (Edge aux = g -> e[current]; aux; aux = aux -> next) {

            if (color[aux->dest] == WHT) { // Only interested in those that aren't on the queue or weren't visited
                dist[aux->dest] = dist[current] + aux -> cost; // Update the cost of getting to the current node
                color[aux->dest] = GRY; // Mark node as "in queue"
                queueEnqueue(&q, aux->dest); // Put in the queue

                if (aux -> dest == destination && dist[aux -> dest] < max_dist) // If we found our destination within given limits
                    return 1; // Success!

            }
        }

        color[current] = BLK; // Don't want to be seeing this node again

    }

    return 0; // If we got this far, we weren't able to find anything. Let us cry somewhere else

}


// Test 2010 - Ex. 6
// Discover if the path in a given array is a valid path
int validPath (Graph g, int path[], int n) {
    int i = 0; // Going through path ary

    while (i < n-1) {
        int adjacent = 0;
        int j = i + 1; // Checking the node ahead in the path

        // Search through the adjacents to the current node for path[ j ]
        for (Edge aux = g->e[ path[i] ]; aux && !adjacent; aux = aux -> next)

            if ( aux -> dest == path[ j ] ) // If we've found the next node in the path
                adjacent = 1; // The path is still valid

        if (!adjacent) // However if we've exited the for and haven't found an adjacent
            return 0; // Insuccess

        i++; // Move forward
    }

    return 1;
}

// Exame 2011 - Ex. 5
// Calculating the degrees of each node.
// Each entry lowers the degree by one. Each exit adds one
void fullDegrees (Graph g) {
    int degrees[g->size]; // Create an array
    for (int i = 0; i < g->size; degrees[i++] = 0); // Since we'll be incrementing and decrementing, set to 0

    for (int i = 0; i < g->size; i++) { // Go through each node
        for (Edge aux = g -> e[i]; aux; aux = aux -> next) { // And its adjacents
            degrees[i]++; // Each adjacent means +1 to the current node
            degrees[aux -> dest]--; // Also means that this adjacent will be decremented
        }
    }

    for (int i = 0; i < g->size; i++)
        printf("EDGE: %d, DEGREES: %d\n", i, degrees[i]);
}


int main() {
    Graph g = newGraph(20);

    // Draw this graph on paper to check those algorithms
    // Don't forget to include edge 0. That one doesn't connect anywhere.
    // Neither has any nodes connecting to it. It's printed anyway.
    addEdge(g, 1, 2, 2);
    addEdge(g, 2, 3, 4);
    addEdge(g, 2, 6, 3);
    addEdge(g, 3, 4, 5);
    addEdge(g, 4, 2, 9);
    addEdge(g, 4, 5, 1);
    addEdge(g, 5, 6, 2);

    printf("ANSWER TO EX 2, TEST 2013, STARTING IN EDGE 1, UP TO A MAXIMUM OF 2: %d\n", succN(g, 1, 2));
    printf("ANSWER SHOULD BE 3 (1 CONNECTS TO 2, WHICH CONNECTS TO 4 AND 6)\n\n");

    printf("ANSWER TO WATERLINK, STARTING IN EDGE 1, SEARCHING 4, WITH A LOWER LIMIT OF 1 IS: ");
    waterLink(g, 1, 4, 1) ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");
    printf("CORRECT ANSWER IS POSSIBLE\n\n");

    printf("ANSWER TO WATERLINK, STARTING IN EDGE 1, SEARCHING 4, WITH A LOWER LIMIT OF 3 IS: ");
    waterLink(g, 1, 4, 3) ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");
    printf("CORRECT ANSWER IS IMPOSSIBLE\n\n");

    printf("ANSWER TO WATERLINK, STARTING IN EDGE 1, SEARCHING 4, WITH A LOWER LIMIT OF 2 IS: ");
    waterLink(g, 1, 4, 2) ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");
    printf("CORRECT ANSWER IS IMPOSSIBLE\n\n");

    printf("ANSWER TO WATERLINK, STARTING IN EDGE 2, SEARCHING 4, WITH A LOWER LIMIT OF 3 IS: ");
    waterLink(g, 2, 4, 3) ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");
    printf("CORRECT ANSWER IS POSSIBLE\n\n");

    printf("ANSWER TO LIMITEDSEARCH, STARTING IN 1, SEARCHING 4 WITH A LIMITED FUEL OF 10: ");
    limitedSearch(g, 1, 4, 10) ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");
    printf("CORRECT ANSWER IS IMPOSSIBLE\n\n");

    printf("ANSWER TO LIMITEDSEARCH, STARTING IN 1, SEARCHING 4 WITH A LIMITED FUEL OF 11: ");
    limitedSearch(g, 1, 4, 11) ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");
    printf("CORRECT ANSWER IS IMPOSSIBLE\n\n");

    printf("ANSWER TO LIMITEDSEARCH, STARTING IN 1, SEARCHING 4 WITH A LIMITED FUEL OF 12: ");
    limitedSearch(g, 1, 4, 12) ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");
    printf("CORRECT ANSWER IS POSSIBLE\n\n");

    printf("ANSWER TO LIMITEDSEARCH, STARTING IN 2, SEARCHING 5 WITH A LIMITED FUEL OF 13: ");
    limitedSearch(g, 2, 5, 13) ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");
    printf("CORRECT ANSWER IS POSSIBLE\n\n");

    int path[4] = {1, 2, 3, 4};
    printf("ANSWER TO VALIDPATH, FOR 1, 2, 3, 4: ");
    validPath(g, path, 4) ? printf("VALID\n") : printf("INVALID\n");
    printf("CORRECT ANSWER IS VALID\n\n");

    int path2[4] = {6, 1, 2, 3};
    printf("ANSWER TO VALIDPATH, FOR 6, 1, 2, 3: ");
    validPath(g, path2, 4) ? printf("VALID\n") : printf("INVALID\n");
    printf("CORRECT ANSWER IS INVALID\n\n");

    printf("ANSWER TO FULLDEGREES:\n");
    fullDegrees(g);
    printf("SHOULD BE: 0 - 0; 1 - 1; 2 - 0; 3 - 0; 4 - 1; 5 - 0; 6 - -2;\n\n");

    printGraph(g);

    delGraph(g);

    return 0;
}
