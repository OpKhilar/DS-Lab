#include <stdio.h>
#include <stdlib.h>

void print (int arr[], int n){
    int i;

    printf ("Sorted elements are: \n");

    for(i=0;i<n;i++) {
        printf ("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort (int arr[], int n) {
    int i, j, key;

    for (i=1; i<n; i++) {
        int key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    print(arr, n);
}

int main() {
    int a[100], n, i;
    
    printf ("Enter the no. of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");

    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    insertionSort(a, n);
    return 0;
}