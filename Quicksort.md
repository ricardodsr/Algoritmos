# Quicksort
O Quicksort é um algoritmo eficiente de classificação baseado na abordagem de dividir e conquistar. Ele divide a lista em torno de um elemento chamado "pivô", rearranja os elementos de forma que os menores que o pivô fiquem à esquerda e os maiores fiquem à direita, e, em seguida, repete o processo recursivamente nas duas metades resultantes até que a lista esteja completamente ordenada.

# Processo

1- Escolha do pivô: O algoritmo seleciona um elemento da lista para ser o pivô. Geralmente, o pivô é escolhido como o último elemento da lista, mas também pode ser escolhido de outras formas, como o primeiro elemento ou um elemento aleatório.

2- Particionamento: O algoritmo rearranja os elementos da lista de forma que todos os elementos menores que o pivô fiquem à esquerda dele e todos os elementos maiores fiquem à direita. Isso é feito movendo os elementos menores que o pivô para a esquerda e os maiores para a direita.

3- Recursão: O algoritmo repete o processo descrito acima para as duas metades resultantes da lista, ou seja, para a sublista à esquerda do pivô e para a sublista à direita do pivô. Esse processo é repetido recursivamente até que a lista esteja completamente ordenada.

4- Combinação: Como o Quicksort é um algoritmo de classificação in-place, ou seja, não requer espaço adicional para armazenar as sub-listas, não há uma etapa de combinação explícita. A lista é ordenada "in-place" durante o processo de particionamento e recursão.

# Codigo Fonte Python

    def swap(A, i, j):
    
        temp = A[i]
        A[i] = A[j]
        A[j] = temp
    
    
    # Partition using the Lomuto partition scheme
    def partition(a, start, end):
    
        # Pick the rightmost element as a pivot from the list
        pivot = a[end]
    
        # elements less than the pivot will be pushed to the left of `pIndex`
        # elements more than the pivot will be pushed to the right of `pIndex`
        # equal elements can go either way
        pIndex = start
    
        # each time we find an element less than or equal to the pivot,
        # `pIndex` is incremented, and that element would be placed
        # before the pivot.
        for i in range(start, end):
            if a[i] <= pivot:
                swap(a, i, pIndex)
                pIndex = pIndex + 1
    
        # swap `pIndex` with pivot
        swap(a, end, pIndex)
    
        # return `pIndex` (index of the pivot element)
        return pIndex
    
    
    # Quicksort routine
    def quicksort(a, start, end):
    
        # base condition
        if start >= end:
            return
    
        # rearrange elements across pivot
        pivot = partition(a, start, end)
    
        # recur on sublist containing elements less than the pivot
        quicksort(a, start, pivot - 1)
    
        # recur on sublist containing elements more than the pivot
        quicksort(a, pivot + 1, end)
    
    
    # Python implementation of the Quicksort algorithm
    if __name__ == '__main__':
    
        a = [9, -3, 5, 2, 6, 8, -6, 1, 3]
    
        quicksort(a, 0, len(a) - 1)
    
        # print the sorted list
        print(a)
 


A função quicksort recebe a lista arr e realiza a classificação utilizando o pivô como o último elemento da lista. A função cria duas listas vazias, smaller (menores que o pivô) e larger (maiores que o pivô), e percorre os elementos de arr para particioná-los nessas duas listas. Em seguida, a função realiza chamadas recursivas para classificar as sublistas smaller e larger, e, por fim, retorna a concatenação das sublistas classificadas com o pivô no meio.

# Codigo Fonte C++

    #include <iostream>
    #include <algorithm>
    using namespace std;
    
    // Partition using the Lomuto partition scheme
    int partition(int a[], int start, int end)
    {
        // Pick the rightmost element as a pivot from the array
        int pivot = a[end];
    
        // elements less than the pivot will be pushed to the left of `pIndex`
        // elements more than the pivot will be pushed to the right of `pIndex`
        // equal elements can go either way
        int pIndex = start;
    
        // each time we find an element less than or equal to the pivot, `pIndex`
        // is incremented, and that element would be placed before the pivot.
        for (int i = start; i < end; i++)
        {
            if (a[i] <= pivot)
            {
                swap(a[i], a[pIndex]);
                pIndex++;
            }
        }
    
        // swap `pIndex` with pivot
        swap (a[pIndex], a[end]);
    
        // return `pIndex` (index of the pivot element)
        return pIndex;
    }
    
    // Quicksort routine
    void quicksort(int a[], int start, int end)
    {
        // base condition
        if (start >= end) {
            return;
        }
    
        // rearrange elements across pivot
        int pivot = partition(a, start, end);
    
        // recur on subarray containing elements that are less than the pivot
        quicksort(a, start, pivot - 1);
    
        // recur on subarray containing elements that are more than the pivot
        quicksort(a, pivot + 1, end);
    }
    
    // C++ implementation of the Quicksort algorithm
    int main()
    {
        int a[] = { 9, -3, 5, 2, 6, 8, -6, 1, 3 };
        int n = sizeof(a)/sizeof(a[0]);
    
        quicksort(a, 0, n - 1);
    
        // print the sorted array
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    
        return 0;
    }

# Codigo Fonte Java

    import java.util.Arrays;
    
    class Main
    {
        public static void swap (int[] arr, int i, int j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    
        // Partition using the Lomuto partition scheme
        public static int partition(int[] a, int start, int end)
        {
            // Pick the rightmost element as a pivot from the array
            int pivot = a[end];
    
            // elements less than the pivot will be pushed to the left of `pIndex`
            // elements more than the pivot will be pushed to the right of `pIndex`
            // equal elements can go either way
            int pIndex = start;
    
            // each time we find an element less than or equal to the pivot,
            // `pIndex` is incremented, and that element would be placed
            // before the pivot.
            for (int i = start; i < end; i++)
            {
                if (a[i] <= pivot)
                {
                    swap(a, i, pIndex);
                    pIndex++;
                }
            }
    
            // swap `pIndex` with pivot
            swap(a, end, pIndex);
    
            // return `pIndex` (index of the pivot element)
            return pIndex;
        }
    
        // Quicksort routine
        public static void quicksort(int[] a, int start, int end)
        {
            // base condition
            if (start >= end) {
                return;
            }
    
            // rearrange elements across pivot
            int pivot = partition(a, start, end);
    
            // recur on subarray containing elements less than the pivot
            quicksort(a, start, pivot - 1);
    
            // recur on subarray containing elements more than the pivot
            quicksort(a, pivot + 1, end);
        }
    
        // Java implementation of the Quicksort algorithm
        public static void main(String[] args)
        {
            int[] a = { 9, -3, 5, 2, 6, 8, -6, 1, 3 };
    
            quicksort(a, 0, a.length - 1);
    
            // print the sorted array
            System.out.println(Arrays.toString(a));
        }
    }

O Quicksort é conhecido por sua eficiência média e seu desempenho geralmente supera outros algoritmos de classificação comuns, como o Bubble Sort ou o Insertion Sort. Sua complexidade de tempo médio é O(n log n), onde n é o número de elementos a serem classificados. No entanto, no pior caso, quando o pivô escolhido não divide a lista em partes quase iguais, a complexidade de tempo pode chegar a O(n^2).