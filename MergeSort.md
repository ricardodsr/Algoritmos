# Merge Sort 
O Merge Sort é um algoritmo de classificação eficiente e popular que segue a abordagem de dividir e conquistar. Ele divide a lista não ordenada em pequenas sub-listas, ordena essas sub-listas recursivamente e depois combina-as para obter a lista final ordenada.

# Processo do Merge Sort

1- Divisão: O algoritmo divide a lista não ordenada ao meio até que haja apenas um elemento em cada sub-lista. Isso é feito recursivamente até que não seja mais possível dividir.

2- Ordenação: Após a divisão, o algoritmo começa a ordenar as sub-listas combinando-as em uma lista ordenada. Para fazer isso, compara-se o primeiro elemento de cada sub-lista e os coloca em ordem crescente. Esse processo continua até que todas as sub-listas sejam combinadas em uma única lista ordenada.

3- Combinação: Nesta etapa, as sub-listas ordenadas são combinadas repetidamente para formar sub-listas maiores, até que toda a lista original seja recriada na ordem correta.

# Codigo Fonte Python

        # Merge two sorted sublists `A[low … mid]` and `A[mid+1 … high]`
        def merge(A, aux, low, mid, high):
        
            k = low
            i = low
            j = mid + 1
        
        # while there are elements in the left and right runs
            while i <= mid and j <= high:
        
                if A[i] <= A[j]:
                    aux[k] = A[i]
                    k = k + 1
                    i = i + 1
                else:
                    aux[k] = A[j]
                    k = k + 1
                    j = j + 1
        
        # copy remaining elements
            while i <= mid:
                aux[k] = A[i]
                k = k + 1
                i = i + 1
        
        # No need to copy the second half (since the remaining items
        # are already in their correct position in the auxiliary array)
        
        # copy back to the original list to reflect sorted order
            for i in range(low, high + 1):
                A[i] = aux[i]
        
        
        # Sort list `A[low…high]` using auxiliary list aux
        def mergesort(A, aux, low, high):
        
            # base case
            if high <= low:                     # if run size <= 1
                return
        
            # find midpoint
            mid = (low + ((high - low) >> 1))
        
            # recursively split runs into two halves until run size <= 1,
            # then merge them and return up the call chain
        
            mergesort(A, aux, low, mid)         # split/merge left half
            mergesort(A, aux, mid + 1, high)    # split/merge right half
        
            merge(A, aux, low, mid, high)       # merge the two half runs
        
        
        # Function to check if `A` is sorted in ascending order or not
        def isSorted(A):
        
            prev = A[0]
            for i in range(1, len(A)):
                if prev > A[i]:
                    print("MergeSort Fails!!")
                    return False
        
                prev = A[i]
        
            return True
        
        
        # Implementation of merge sort algorithm in Python
        if __name__ == '__main__':
        
            A = [12, 3, 18, 24, 0, 5, -2]
            aux = A.copy()
        
            # sort list `A` using auxiliary list `aux`
            mergesort(A, aux, 0, len(A) - 1)
        
            if isSorted(A):
                print(A)

# Codigo Fonte em C 

        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h>
        
        #define N 15
        
        // Merge two sorted subarrays `arr[low … mid]` and `arr[mid+1 … high]`
        void Merge(int arr[], int aux[], int low, int mid, int high)
        {
            int k = low, i = low, j = mid + 1;
        
            // while there are elements in the left and right runs
            while (i <= mid && j <= high)
            {
                if (arr[i] <= arr[j]) {
                    aux[k++] = arr[i++];
                }
                else {
                    aux[k++] = arr[j++];
                }
            }
        
            // copy remaining elements
            while (i <= mid) {
                aux[k++] = arr[i++];
            }
        
            // No need to copy the second half (since the remaining items
            // are already in their correct position in the auxiliary array)
        
            // copy back to the original array to reflect sorted order
            for (int i = low; i <= high; i++) {
                arr[i] = aux[i];
            }
        }
        
        // Sort array `arr[low…high]` using auxiliary array `aux`
        void mergesort(int arr[], int aux[], int low, int high)
        {
            // base case
            if (high <= low) {        // if run size <= 1
                return;
            }
        
            // find midpoint
            int mid = (low + ((high - low) >> 1));
        
            // recursively split runs into two halves until run size <= 1,
            // then merge them and return up the call chain
        
            mergesort(arr, aux, low, mid);          // split/merge left half
            mergesort(arr, aux, mid + 1, high);     // split/merge right half
        
            Merge(arr, aux, low, mid, high);        // merge the two half runs.
        }
        
        // Function to check if arr is sorted in ascending order or not
        int isSorted(int arr[])
        {
            int prev = arr[0];
            for (int i = 1; i < N; i++)
            {
                if (prev > arr[i])
                {
                    printf("MergeSort Fails!!");
                    return 0;
                }
                prev = arr[i];
            }
        
            return 1;
        }
        
        // Implementation of merge sort algorithm in C
        int main(void)
        {
            int arr[N], aux[N];
            srand(time(NULL));
        
            // generate random input of integers
            for (int i = 0; i < N; i++) {
                aux[i] = arr[i] = (rand() % 100) - 50;
            }
        
            // sort array `arr` using auxiliary array `aux`
            mergesort(arr, aux, 0, N - 1);
        
            if (isSorted(arr))
            {
                for (int i = 0; i < N; i++) {
                    printf("%d ", arr[i]);
                }
            }
        
            return 0;
        }

# Codigo Fonte em Java

        import java.util.Arrays;
    
    class Main
    {
        // Merge two sorted subarrays `arr[low … mid]` and `arr[mid+1 … high]`
        public static void merge(int[] arr, int[] aux, int low, int mid, int high)
        {
            int k = low, i = low, j = mid + 1;
    
            // while there are elements in the left and right runs
            while (i <= mid && j <= high)
            {
                if (arr[i] <= arr[j]) {
                    aux[k++] = arr[i++];
                }
                else {
                    aux[k++] = arr[j++];
                }
            }
    
            // copy remaining elements
            while (i <= mid) {
                aux[k++] = arr[i++];
            }
    
            // No need to copy the second half (since the remaining items
            // are already in their correct position in the auxiliary array)
    
            // copy back to the original array to reflect sorted order
            for (i = low; i <= high; i++) {
                arr[i] = aux[i];
            }
        }
    
        // Sort array `arr[low…high]` using auxiliary array `aux`
        public static void mergesort(int[] arr, int[] aux, int low, int high)
        {
            // base case
            if (high <= low) {        // if run size <= 1
                return;
            }
    
            // find midpoint
            int mid = (low + ((high - low) >> 1));
    
            // recursively split runs into two halves until run size <= 1,
            // then merge them and return up the call chain
    
            mergesort(arr, aux, low, mid);          // split/merge left half
            mergesort(arr, aux, mid + 1, high);     // split/merge right half
    
            merge(arr, aux, low, mid, high);        // merge the two half runs
        }
    
        // Function to check if arr is sorted in ascending order or not
        public static boolean isSorted(int[] arr)
        {
            int prev = arr[0];
            for (int i = 1; i < arr.length; i++)
            {
                if (prev > arr[i])
                {
                    System.out.println("MergeSort Fails!!");
                    return false;
                }
                prev = arr[i];
            }
    
            return true;
        }
    
        // Implementation of merge sort algorithm in Java
        public static void main(String[] args)
        {
            int[] arr = { 12, 3, 18, 24, 0, 5, -2 };
            int[] aux = Arrays.copyOf(arr, arr.length);
    
            // sort array `arr` using auxiliary array `aux`
            mergesort(arr, aux, 0, arr.length - 1);
    
            if (isSorted(arr)) {
                System.out.println(Arrays.toString(arr));
            }
        }
    }

O algoritmo Merge Sort é conhecido pela sua eficiência e estabilidade, o que significa que ele preserva a ordem relativa de elementos com valores iguais durante a classificação. Sua complexidade de tempo é O(n log n), onde n é o número de elementos a serem classificados. Isso faz dele uma ótima escolha para classificar grandes conjuntos de dados.