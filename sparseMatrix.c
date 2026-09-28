#include <stdio.h>
#define SIZE 100
int mat1[SIZE][SIZE], mat2[SIZE][3], i, j;

int count(int row, int col){
    int k=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if (mat1[i][j] != 0){
                k++;
            }
        }
    }
    return k;
}

void store(int n, int row, int col){
    int k=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(mat1[i][j]!=0){
                mat2[k][0]=i;
                mat2[k][1]=j;
                mat2[k][2]=mat1[i][j];
                k++;
            }
        }
        if(k>=n) break;
    }
}

void display(int x){
    for(i=0;i<x;i++){
        for(j=0;j<3;j++){
            printf("%d ",mat2[i][j]);
        }
        printf("\n");
    }

}

int main(){
    int row,col,c=0;
    printf("Enter no. of rows (1-%d): ",SIZE);
    scanf("%d",&row);
    printf("Enter no. of columns (1-%d): ",SIZE);
    scanf("%d",&col);
    printf("Enter the elements: \n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&mat1[i][j]);
        }
        printf("\n");
    }
    c=count(row,col);
    store(c,row,col);
    display(c);
    return 0
    ;
}