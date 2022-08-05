#include <stdio.h>
#include <stdlib.h>

#define N 100000

void selectionSort(int arr[], int n);
void swap(int * x, int * y);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void bubbleSort(int arr[], int n);

int main(void) {

    int numbers[N];
    int i = 0, choice, j;
    FILE * file;
    FILE * file1;
    file1 = fopen("sortedNumbers.txt", "a");

    if (file = fopen("random10000.txt", "r")) {
        while (fscanf(file, "%d", & numbers[i]) != EOF) {
            i++;
        }
        fclose(file);

        numbers[i] = '\0';

    } else {
        printf("File error");
        return 1;
    }

    printf("1-Bubble Sort\n2-Selection Sort\n3-Merge Sort\nYour Choice: ");

    scanf("%d", & choice);

    if (choice == 1) {
        bubbleSort(numbers, i);
    } else if (choice == 2) {
        selectionSort(numbers, i);
    } else if (choice == 3) {
        mergeSort(numbers, 0, i - 1);
    } else {
        printf("Wrong choice");
    }

    for (j = 0; j < i; j++) {
        fprintf(file1, "%3d", numbers[j]);
        fprintf(file1, "\n");
    }

    fclose(file1);

    return 0;

}
void swap(int * x, int * y) {
    int temp = * x;
    * x = * y;
    * y = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min;

    for (i = 0; i < n - 1; i++) {

        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) {
                min = j;
            }

        swap( & arr[min], & arr[i]);
    }
}
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                swap( & arr[j], & arr[j + 1]);
            }

}
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
