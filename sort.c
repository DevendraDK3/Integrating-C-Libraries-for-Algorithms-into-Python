#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void Bubble_Sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
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

void Merge_Sort_Helper(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        Merge_Sort_Helper(arr, l, m);
        Merge_Sort_Helper(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}

void Merge_Sort(int arr[], int n) {
    Merge_Sort_Helper(arr, 0, n - 1);
}

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void Quick_Sort_Helper(int arr[], int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        Quick_Sort_Helper(arr, low, pi - 1);
        Quick_Sort_Helper(arr, pi + 1, high);
    }
}

void Quick_Sort(int arr[], int n) {
    Quick_Sort_Helper(arr, 0, n - 1);
}
void Insertion_Sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//make changes here


int main() {
    int arr[100], n;

    //printf("Enter the number of elements in the array (max 100): ");
    scanf("%d", &n);

    //printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /*
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    */

    Bubble_Sort(arr, n);
    /*
    printf("\n\nBubble Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    */

    Merge_Sort(arr, n);
    /*
    printf("\n\nMerge Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    */

    Quick_Sort(arr, n);
    /*
    printf("\n\nQuick Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    */

    Insertion_Sort(arr, n);
    /*
    printf("\n\nInsertion Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    */

    return 0;
}
