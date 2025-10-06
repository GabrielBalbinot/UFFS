#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void swap(int *, int *);
void bubble(int *, int);
void printArray(int *, int);
int particiona(int *, int, int);
void quicksort(int *, int, int);
void heapify(int *, int, int);
void heapSort(int *, int);
int ordenouCerto(int *, int *, int *, int);

int main()
{
    int n = 50000;
    clock_t begin, end;
    double time_spent;
    srand(time(NULL));
    
    int *arr1, *arr2, *arr3;
    arr1 = malloc(sizeof(int) * n);
    arr2 = malloc(sizeof(int) * n);
    arr3 = malloc(sizeof(int) * n);
    
    for (int i=0; i < n; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
        
    
    begin = clock();
    bubble(arr1, n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    printf("Tempo de execução Bubble Sort: %f milisegundos\n\n", time_spent);
    
    begin = clock();
    quicksort(arr2, 0, n-1);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    printf("Tempo de execução Quick Sort: %f milisegundos\n\n", time_spent);
    
    begin = clock();
    heapSort(arr3, n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    printf("Tempo de execução Heap Sort: %f milisegundos\n\n", time_spent);
    
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

void bubble(int *arr, int n) {
    
    for (int i=0; i < n; i++) {
        
        for (int j=0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
        
    }
}

int particiona(int *arr, int low, int high) {
    
    //srand(time(NULL));
    //int pivotIndex = low + rand() % (high - low + 1);
    int pivotIndex = high;
    int i = low - 1;
    
    for (int j=low; j <= high; j++) {
        if (arr[j] < arr[pivotIndex]) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i+1], &arr[pivotIndex]);
    return i+1;
}

void quicksort(int *arr, int low, int high) {
    
    if (low < high) {
        
        int pivot = particiona(arr, low, high);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
        
    }
}

void heapify(int *arr, int n, int i) {
   int largest = i;
   int left = 2 * i + 1;
   int right = 2 * i + 2;

   if (left < n && arr[left] > arr[largest]) {        largest = left;    }
   if (right < n && arr[right] > arr[largest]) {      largest = right;    }
   if (largest != i) {
       swap(&arr[i], &arr[largest]);
       heapify(arr, n, largest);
   }
}

void heapSort(int *arr, int n) {
   for (int i = n / 2 - 1; i >= 0; i--) {
       heapify(arr, n, i);
   }
   for (int i = n - 1; i > 0; i--) {
       swap(&arr[0], &arr[i]);
       heapify(arr, i, 0);
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
