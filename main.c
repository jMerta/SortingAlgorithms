#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void bubblesort (int A[],int n);
void write_array(int A[], int n);
void create_array(int A[], int n);
void copy_array(int X[], int Y[], int n);
void reverse_array(int A[],int n);
void quicksort_lomuto(int A[], int p, int r);
int partition_lomuto(int A[], int p, int r);
void swap (int *i, int *j);
void quicksort_hoare(int A[], int p, int r);
int partition_hoare(int A[],int p, int r);
void selectionsort(int A[],int n);
void heapsort(int A[],int n);
void heapify(int A[], int i,int n);



int main() {
    char finish;
    do{
        int*  bubbleArray = malloc(1000000 * sizeof(int)),heapsortArray = malloc(1000000 * sizeof(int)),qsHoareArray = malloc(1000000 * sizeof(int)),qsLomutoArray = malloc(1000000 * sizeof(int)),selectionsortArray = malloc(1000000 * sizeof(int));
        int n = 1000000;
        create_array(bubbleArray, n);
        /////////Skopiowanie tablicy////////////
        copy_array(bubbleArray, heapsortArray, n);
        copy_array(bubbleArray, qsHoareArray, n);
        copy_array(bubbleArray, qsLomutoArray, n);
        copy_array(bubbleArray, selectionsortArray, n);
        ///////////////////////////////////////
        printf("\n\nStworzono tablice");
        ////////////Bubble sort wylosowanej tablicy
        clock_t bubblesortRandomTimer,bubblesortOrderedTimer,bubblesortReversedTimer;
        bubblesortRandomTimer = clock();

        bubblesort(bubbleArray,n);

        bubblesortRandomTimer = clock() - bubblesortRandomTimer;
        double time_taken = ((double)bubblesortRandomTimer)/CLOCKS_PER_SEC;

        printf("\nTime taken to bubble sort random array: %lf ", time_taken);
        //////////Bubble sort dla posortowanej tablicy
        bubblesortOrderedTimer = clock();
        bubblesort(bubbleArray,n);

        bubblesortOrderedTimer = clock() - bubblesortOrderedTimer;
        double time_taken2 = ((double)bubblesortOrderedTimer)/CLOCKS_PER_SEC;

        printf("\nTime taken to bubble sort sorted array: %lf ", time_taken2);
        ///////////Bubble sort dla odwróconej tablicy
        reverse_array(bubbleArray,n);
        bubblesortReversedTimer = clock();
        bubblesort(bubbleArray,n);
        bubblesortReversedTimer = clock()- bubblesortReversedTimer;
        double time_taken3 = ((double)bubblesortReversedTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to bubblesort reversed array: %lf ", time_taken3);
        /////////////////////////Quicksort lomuto dla wylosowanej tablicy
        clock_t qsLomutoRandomTimer, qsLomutoOrderedTimer, qsLomutoReversedTimer;
        qsLomutoRandomTimer = clock();
        quicksort_lomuto(qsLomutoArray,0,n);
        qsLomutoRandomTimer = clock() - qsLomutoRandomTimer;
        double rndLomutoTimeTaken = ((double)qsLomutoRandomTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to quicksort lomuto random array: %lf ", rndLomutoTimeTaken);
        ///////////////Quicksort lomuto dla posortowanej tablicy/*
        qsLomutoOrderedTimer = clock();
        quicksort_lomuto(qsLomutoArray,0,n);
        qsLomutoOrderedTimer = clock() - qsLomutoOrderedTimer;
        double ordLomutoTimeTaken = ((double)qsLomutoOrderedTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to quicksort lomuto ordered array: %lf ", ordLomutoTimeTaken);
        ///////////////Quicksort lomuto dla odwróconej tablicy
        reverse_array(qsLomutoArray,n);
        qsLomutoReversedTimer = clock();
        quicksort_lomuto(qsLomutoArray,0,n);
        qsLomutoReversedTimer = clock() - qsLomutoReversedTimer;
        double revLomutoTimeTaken = ((double)qsLomutoReversedTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to quicksort lomuto reversed array: %lf ", revLomutoTimeTaken);


        //////////////////////////////Selectionsort dla wylosowanej tablicy
        clock_t selectionRandomTimer, selectionOrderedTimer, selectionReversedTimer;
        selectionRandomTimer = clock();
        selectionsort(selectionsortArray,n);
        selectionRandomTimer = clock() - selectionRandomTimer;
        double rndSelectionTimeTaken = ((double)selectionRandomTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to selectionsort random array: %lf ", rndSelectionTimeTaken);
        ////////////////////////////Selection sort dla posortowanej tablicy
        selectionOrderedTimer = clock();
        selectionsort(selectionsortArray,n);
        selectionOrderedTimer = clock() - selectionOrderedTimer;
        double ordSelectionTimeTaken = ((double)selectionOrderedTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to selection sort ordered array: %lf ", ordSelectionTimeTaken);
        ////////////////////////////Selection sort dla odwróconej tablicy
        reverse_array(selectionsortArray,n);
        selectionReversedTimer = clock();
        selectionsort(selectionsortArray,n);
        selectionReversedTimer = clock() - selectionReversedTimer;
        double revSelectionTimer = ((double)selectionReversedTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to selection sort reversed array: %lf ", revSelectionTimer);


        //////////////////////////////Quick sort hoare dla wylosowanej tablicy
        clock_t hoareRandomTimer, hoareOrderedTimer, hoareReversedTimer;
        hoareRandomTimer = clock();
        quicksort_hoare(qsHoareArray,0,n);
        hoareRandomTimer = clock()- hoareRandomTimer;
        double  rndHoareTimeTaken = ((double)hoareRandomTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to hoare quick sort random array: %lf ", rndHoareTimeTaken);
        /////////////////////////hoare dla posortowanej tablicy
        hoareOrderedTimer = clock();
        quicksort_hoare(qsHoareArray,0,n);
        hoareOrderedTimer = clock() - hoareOrderedTimer;
        double ordHoareTimeTaken = ((double)hoareOrderedTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to hoare quicksort ordered array: %lf " , ordHoareTimeTaken);
        /////////////////////////// hoare dla odwróconej tablicy
        reverse_array(qsHoareArray,n);
        hoareReversedTimer = clock();
        quicksort_hoare(qsHoareArray,0,n);
        hoareReversedTimer = clock() - hoareReversedTimer;
        double revHoareTimeTaken  = ((double)hoareReversedTimer)/CLOCKS_PER_SEC;
        printf("\n Time taken to hoare quicksort reversed array: %lf ", revHoareTimeTaken);


        //////////////////////// heaposort dla wylosowanej tablicy
        clock_t heapRandomTimer, heapOrderedTimer, heapReversedTimer;
        heapRandomTimer = clock();
        heapsort(heapsortArray,n);
        heapRandomTimer = clock() - heapRandomTimer;
        double rndHeapTimeTaken = ((double)heapRandomTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to heapsort random array: %lf ", rndHeapTimeTaken);
        ///////////////////////////// heapsort dla posortowanej tablicy
        heapOrderedTimer = clock();
        heapsort(heapsortArray,n);
        heapOrderedTimer = clock() - heapOrderedTimer;
        double ordHeapTimeTaken = ((double)heapOrderedTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to heapsort ordered array: %lf ", ordHeapTimeTaken);
        ///////////////////////////// heapsort dla odwróconej tablicy
        reverse_array(heapsortArray,n);
        heapReversedTimer = clock();
        heapsort(heapsortArray,n);
        heapReversedTimer = clock() - heapReversedTimer;
        double revHeapTimeTaken = ((double)heapReversedTimer);
        printf("\nTime taken to heapsort reversed array: %lf ", revHeapTimeTaken);

        printf("\n\nDo you wish to repeat Y/N?\n\n");
        finish = getch();
    }while (finish =='Y' || finish == 'y');

    return 0;
}
///////////////////////////////////////////////// Funkcje pomocnicze i tworzące tablice

void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}


void write_array(int A[], int n)
{
    int i;
    for (i=0; i<n; i++){
        printf("%d",A[i]);
        printf("\t");
    }

}
void create_array(int A[], int n)
{

    int i;
    srand(time(0));
    for(i=0; i<n;i++)
    {
        A[i]=rand() %1001;
    }
}
void copy_array(int X[], int Y[], int n)
{
    int i;
    for(i=0;i<n;i++){
        Y[i]=X[i];
    }
}

void reverse_array(int A[], int n){
    int i,j,temp;
    i=0; j=n-1;
    while (i<j){
        temp =A[i];
        A[i] = A[j];
        A[j]=temp;
        i++;
        j--;
    }
}
/////////////////////////////////////// Sortowania

void bubblesort(int A[], int n){
    int i,j,temp,change;

    for ( i =0; i<n-1; i++){
        change=0;
        for (j=0; j<n-1-i;j++)
        {
            if (A[j] > A[j+1])
            {
                temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
                change=1;
            }
        }
        if(!change) break;
    }
}

void quicksort_lomuto(int A[], int p, int r){
    if (p<r){
        int q = partition_lomuto(A, p, r-1);
        quicksort_lomuto(A, p, q-1);
        quicksort_lomuto(A, q+1, r-1);
    }
}

int partition_lomuto(int A[], int p, int r)
{
    int j;
    int x = A[r];
    int i = p-1;
    for ( j = p; j <= r-1; j++)
    {
        if (A[j] <= x)
        {
            i = i+1;
            swap (&A[i], &A[j]);
        }
    }
    swap (&A[i+1], &A[r]);
    return i+1;
}
void selectionsort(int A[], int n){
    int i,j;
    for(i=0;i<n; i++){

        for(j= i + 1;j<=n -1;j++){
            if(A[j]< A[i]){
                swap(&A[j],&A[i]);
            }
        }
    }
}

void quicksort_hoare(int A[], int p, int r){
    if (p<r){
        int q = partition_hoare(A, p, r-1);
        quicksort_hoare(A, p, q);
        quicksort_hoare(A, q+1, r-1);
    }

}
int partition_hoare(int A[],int p, int r) {
    int pivot = A[p];
    int i = p - 1;
    int j = r;
    while (1) {
        do j--; while (A[j] > pivot);
        do i++; while (A[i] < pivot);
        if (i < j) {
            swap(&A[i], &A[j]);
        } else return j;
    }
}

void heapify(int A[], int i, int n)
{

    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;


    if (left <= n && (A[left] > A[i]))
        largest = left;
    if (right <= n && (A[right] > A[largest]))
        largest = right;
    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        heapify(A, largest, n);
    }

}



void heapsort(int A[], int n)
{

    for (int i = ((n)/2); i >= 0; i--)
    {
        heapify(A, i, n);
    }
    for (int i = n; i >= 1; i--)
    {
        swap(&A[i], &A[0]);
        n--;
        heapify(A, 0, n);
    }
}