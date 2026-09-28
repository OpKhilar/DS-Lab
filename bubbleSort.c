#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void print (int arr[], int n){
    int i;

    printf ("Sorted elements are: \n");

    for(i=0;i<n;i++) {
        printf ("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort (int arr[], int n) {
    int i, j;
    
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
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

    bubbleSort(a, n);
    return 0;
}
