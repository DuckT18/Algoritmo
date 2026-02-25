#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
void mergeSort(int arr[], int l, int r);
void printArray(int arr[], int n);
void copyArray(int source[], int dest[], int n);

void merge(int arr[], int l, int m, int r);
int partition(int arr[], int low, int high);

int main() {
    int n, choice;
    srand(time(NULL));

    printf("Digite o tamanho do array para os testes: ");
    scanf("%d", &n);

    int *originalArr = (int *)malloc(n * sizeof(int));
    int *testArr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) originalArr[i] = rand() % 10000;

    do {
        copyArray(originalArr, testArr, n);
        printf("\n--- MENU DE ALGORITMOS DE ORDENACAO ---\n");
        printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n5. Merge Sort\n0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            if (n <= 20) {
                printf("Array Original: ");
                printArray(testArr, n);
            }

            clock_t start = clock();

            switch (choice) {
                case 1: bubbleSort(testArr, n); break;
                case 2: selectionSort(testArr, n); break;
                case 3: insertionSort(testArr, n); break;
                case 4: quickSort(testArr, 0, n - 1); break;
                case 5: mergeSort(testArr, 0, n - 1); break;
            }

            clock_t end = clock();
            double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

            if (n <= 20) {
                printf("Array Ordenado: ");
                printArray(testArr, n);
            }
            printf("Tempo de execucao: %f segundos\n", time_taken);
        }
    } while (choice != 0);

    free(originalArr);
    free(testArr);
    return 0;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = source[i];
}