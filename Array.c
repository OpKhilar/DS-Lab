#include <stdio.h>
int i, arr[10], ch, ele, pos;
void traverse(void);
void insert(void);
void delete(void);

void traverse(void){
    printf("The elements are:- \n");
    for(i=0;i<10;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insert(void){
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&ele);
    printf("Enter the position: ");
    scanf("%d",&pos);
    arr[pos-1]=ele;
    printf("Element %d inseted at position %d",ele,pos);
}
void delete(){
    printf("\nEnter the position form which element will be deleted: ");
    scanf("%d",&pos);
    arr[pos-1]=0;
    printf("Element deleted from position %d",pos);
}
int main(){
    printf("Enter the elemnets:- ");
    for(i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    do{
        printf(" MAIN MENU \n");
        printf("------------\n");
        printf("1.Traverse\n");
        printf("2.Insert\n");
        printf("3.Delete\n");
        printf("4.Exit\n");

        printf("Enter your choice:-");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                traverse();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4:
                break;
            default: printf("Wrong Choice! Enter your choice between 1-4");
                break;
        }
    }while(ch!=4);
    return 0;
}

