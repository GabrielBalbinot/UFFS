#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void swap(int *, int *);
long bubble(int *, int);
long insertion(int *, int);
void printArray(int *, int);
int particiona(int *, int, int, long *);
void quicksort(int *, int, int, long *);
void heapify(int *, int, int, long *);
void heapSort(int *, int, long *);
int ordenouCerto(int *, int *, int *, int);

int main()
{
    int n = 1000;
    long t;
    clock_t begin, end;
    double time_spent;
    srand(time(NULL));
    
    int *arr1, *arr2, *arr3, *arr4;
    arr1 = malloc(sizeof(int) * n);
    arr2 = malloc(sizeof(int) * n);
    arr3 = malloc(sizeof(int) * n);
    arr4 = malloc(sizeof(int) * n);
    
    for (int i=0; i < n; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
        
    // Contagem de tempo e trocas realizadas para Bubble Sort
    begin = clock();
    t = bubble(arr1, n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    printf("---- Bubble Sort ----\nTrocas: %ld\nTempo de execução: %f milisegundos\n\n", t, time_spent);
    
    // Contagem de tempo e trocas realizadas para Insertion Sort
    begin = clock();
    t = insertion(arr3, n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    printf("---- Insertion Sort ----\nTrocas: %ld\nTempo de execução: %f milisegundos\n\n", t, time_spent);
    
    // Contagem de tempo e trocas realizadas para Quick Sort
    begin = clock();
    t = 0;
    quicksort(arr2, 0, n-1, &t);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    printf("---- Quick Sort ----\nTrocas: %ld\nTempo de execução: %f milisegundos\n\n", t, time_spent);
    
    // Contagem de tempo e trocas realizadas para Heap  Sort
    begin = clock();
    t = 0;
    heapSort(arr3, n, &t);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    printf("---- Heap Sort ----\nTrocas: %ld\nTempo de execução: %f milisegundos\n\n", t, time_spent);
    
    if (ordenouCerto(arr1, arr2, arr3, n) != 1) {
        printf("Erro na ordenação");
    }
    
    return 0;
}

void swap (int *a, int *b){
   int temp=*(b);
   *b=*a;
   *a=temp;
}

void printArray(int *arr, int n) {
    for (int i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

long bubble(int *arr, int n) {
    
    long t = 0;
    
    for (int i=0; i < n; i++) {
        
        for (int j=0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                t++;
                swap(&arr[j], &arr[j+1]);
            }
        }
        
    }
    return t;
}

long insertion(int *arr, int n) {
    
    long t = 0;
    
    for (int i=1; i < n; i++) {
        
        int key = arr[i];
        int j = i-1;
        
        while (j >= 0 && arr[j] > key) {
            t++;
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
        
    }
    
    return t;
    
}

int particiona(int *arr, int low, int high, long *t) {
    
    //srand(time(NULL));
    //int pivotIndex = low + rand() % (high - low + 1);
    int pivotIndex = high;
    int i = low - 1;
    
    for (int j=low; j <= high; j++) {
        //printf("C: %d\n", c);
        if (arr[j] < arr[pivotIndex]) {
            i++;
            (*t)++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i+1], &arr[pivotIndex]);
    return i+1;
}

void quicksort(int *arr, int low, int high, long *t) {
    
    if (low < high) {
        
        int pivot = particiona(arr, low, high, t);
        quicksort(arr, low, pivot-1, t);
        quicksort(arr, pivot+1, high, t);
        
    }
}

void heapify(int *arr, int n, int i, long *t) {
   int largest = i;
   int left = 2 * i + 1;
   int right = 2 * i + 2;

   if (left < n && arr[left] > arr[largest]) {
       largest = left;
   }
   if (right < n && arr[right] > arr[largest]) {
       largest = right;
   }
   if (largest != i) {
       (*t)++;
       swap(&arr[i], &arr[largest]);
       heapify(arr, n, largest, t);
   }
}

void heapSort(int *arr, int n, long *t) {
   for (int i = n / 2 - 1; i >= 0; i--) {
       heapify(arr, n, i, t);
   }
   for (int i = n - 1; i > 0; i--) {
       swap(&arr[0], &arr[i]);
       heapify(arr, i, 0, t);
   }
}

int ordenouCerto(int *arr1, int *arr2, int *arr3, int n) {
    
    for (int i=0; i < n; i++) {
        
        if (arr1[i] != arr2[i] || arr1[i] != arr3[i] || arr2[i] != arr3[i]) {
            printf("Arr1[%d]: %d\nArr2[%d]: %d\nArr3[%d]: %d\n", i, arr1[i], i, arr2[i], i, arr3[i]);
            return 0;
        }
        
    }
    
    return 1;
}
