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

void swap (int *a, int *b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void selectionSort(int arr[], int n) {
    int i, j, min;

    for(i=0; i<n-1; i++){
        min=i;

        for(j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(min!=i) {
            swap(&arr[min], &arr[i]);
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

    selectionSort(a, n);
    return 0;
}