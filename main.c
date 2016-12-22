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
void partition_hoare(int A[],int p, int r);
void selectionsort(int A[],int n);


int main() {
    char finish;
    do{
        int  bubbleArray[100000],heapsortArray[100000],qsHoareArray[100000],qsLomutoArray[100000],selectionsortArray[100000];
        int n = 100000;
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
        quicksort_lomuto(qsLomutoArray,0,n-1);
        qsLomutoRandomTimer = clock() - qsLomutoRandomTimer;
        double rndLomutoTimeTaken = ((double)qsLomutoRandomTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to quicksort lomuto random array: %lf ", rndLomutoTimeTaken);
        ///////////////Quicksort lomuto dla posortowanej tablicy/*
      /*  qsLomutoOrderedTimer = clock();
        quicksort_lomuto(qsLomutoArray,0,n-1);
        qsLomutoOrderedTimer = clock() - qsLomutoOrderedTimer;
        double ordLomutoTimeTaken = ((double)qsLomutoOrderedTimer)/CLOCKS_PER_SEC;
    */   // printf("\nTime taken to quicksort lomuto ordered array: %lf ", ordLomutoTimeTaken);
        ///////////////Quicksort lomuto dla odwróconej tablicy
      // printf("\nTime taken to quicksort lomuto reversed array: %lf ", revLomutoTimeTaken);
        //////////////////////////////Selectionsort dla wylosowanej tablicy
        clock_t selectionRandomTimer, selectionOrderedTimer, selectionReversedTimer;
        selectionRandomTimer = clock();
        selectionsort(selectionsortArray,n);
        selectionRandomTimer = clock() - selectionRandomTimer;
        double rndSelectionTimer = ((double)selectionRandomTimer)/CLOCKS_PER_SEC;
        printf("\nTime taken to selectionsort random array: %lf ", rndSelectionTimer);




        printf("\n\nDo you wish to repeat Y/N?\n\n");
        finish = getch();
    }while (finish =='Y' || finish == 'y');

    return 0;
}
void bubblesort(int A[], int n){
    int i,j,temp;
    for ( i =0; i<n-1; i++){
        for (j=0; j<n-1-i;j++)
        {
            if (A[j] > A[j+1])
            {
                temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
            }
        }
    }
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

void quicksort_lomuto(int A[], int p, int r){
    if (p<r){
        int q = partition_lomuto(A, p, r);
        quicksort_lomuto(A, p, q-1);
        quicksort_lomuto(A, q+1, r);
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
void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void selectionsort(int A[], int n){
    int i,j;
    for(i=0;i<n; i++){
        for(j=0;j<n-1;j++){
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
            }
        }
    }
}