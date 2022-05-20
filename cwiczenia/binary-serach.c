#include <stdio.h>

int linearSearch(int *array, int size, int toFind) {
    for (int i = 0; i < size; i++) {
        if (array[i] == toFind)
            return i;
    }
    return -1;
}

int binarySearch(int *array, int left, int right, int searchValue) {
    if (right >= left) {
        int mid = (left + right) / 2;
        if (array[mid] == searchValue) {
            return mid;
        }
        if (array[mid] > searchValue) { 
            return binarySearch(array, left, mid - 1, searchValue);
        }
        return binarySearch(array, mid + 1, right, searchValue);
    }
    return -1;
}

int main () {
    // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arr[] = {23, 1, 3, 5, 22};
    int last = sizeof(arr) / sizeof(arr[0]);
    int index = binarySearch(arr, 0, last - 1, 5);
    int index2 = linearSearch(arr, last, 5);
    printf("%d\n", index);
    printf("%d\n", index2);
    return 0;
}