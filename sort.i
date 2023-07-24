%module sort

%{
#include "sort.h"
%}

%include "sort.h"

%inline %{
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
%}
