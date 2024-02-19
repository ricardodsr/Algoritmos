#include <stdio.h>

typedef int** Graph;

int N;

/* 2a) */
int getDegree(int index, Graph g) {
    int result = 0;
    for (int j = 0; j < N; j++)
        result += g[index][j];
    return result;
}

// Percorrer adjacentes
// Obter pagerank de cada adjacente pelo vetor
// Dividir pelo grau desse adjacente
void updatePRank(Graph g, float pk[], float pk1[]) {

    for (int i = 0; i < N; i++) {
        pk1[i] = 0;
        for (int j = 0; j < N; j++) {
            if ( g[i][j] ) {
                int degree = getDegree(j, g);
                pk1[ i ] += pk[ j ] / (float)degree;
            }
        }
    }
}


/* 2b) */
// Gerar pagerank para iteração 0
// Fazer um ciclo com updatePRank para gerar até k
void pageranks (Graph g, int k, float *pk) {

    for (int i = 0; i < N; pk[i++] = 1.0/N); // Gerar vetor para iteração 0

    float pk1[N];

    for (int i = 0; i <= k; i++) { // Gerar as seguintes k iterações
        if (i % 2)
            updatePRank(g, pk, pk1);
        else
            updatePRank(g, pk1, pk);

        /* NOTA: As chamadas alternadas é porque o updatePRank devolve o vetor da chamada seguinte no pk1
        Por preguiça, em vez de estar a copiar o pk1 para pk, nas chamadas pares usa-se pk, nas chamadas ímpares pk1 */

    }
}

int main() {
    return 0;
}
