#include <stdio.h>

// Selection sort O(n^2) pes i opt

void swap(int *el1, int *el2) {
    int temp = *el1;
    *el1 = *el2;
    *el2 = temp;
}

void selection_sort(int *tab, int size) {
    int i, j, min;
    for (i = 0; i < size; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (tab[j] < tab[min]) {
                min = j;
            }
        }
        swap(&tab[i], &tab[min]);
    }
}

// Bubble sort O(n^2) pes i opt

void bubble_sort(int *tab, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (tab[j] > tab[j + 1]) {
                swap(&tab[j], &tab[j + 1]);
            }			
        }

    }
}

// Sortowanie przez wstawianie O(n^2) pes i O(n) opt

void insert_sort(int *tab, int size) {
    int i, j, temp;
    
    for (i = 1; i < size; i++){
        temp = tab[i];
        j = i - 1;
        
        while(j >= 0 && tab[j] > temp) {
            tab[j + 1] = tab[j];
            --j;
        }
        tab[j + 1] = temp;
    } 
}

// Sortowanie przez scalanie

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
        }
        else {
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

void show(int *tab, int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%d, ", tab[i]);
    }
    printf("\n");
}


int main() {
    int array[] = {4, 2, -3, 6, 10, -1};
    int size = sizeof(array) / sizeof(array[0]);
    
//	int i, j, temp;
//	for (i = 0; i < 5; i++) {
//		for (j = i + 1; j < 5; j++) {
//			if (array[i] >= array[j]) {
//				temp = array[i];
//				array[i] = array[j];
//				array[j] = temp;
//			}
//		}
//	}

    show(array, size);
    // mergeSort(array, 0, size -1);
    selection_sort(array, size);
    // bubble_sort(array, size);
    // insert_sort(array, size);
    show(array, size);
    
//	show(array, size);
//	selection_sort(array, size);
//	show(array, size);
    
    return 0;
}