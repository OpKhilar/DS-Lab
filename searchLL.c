#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void input(int n, struct Node** head){
    int data;
    printf("Enter the elements: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        insert(head, data);
    }
}

void print(struct Node* head) {
    struct Node* temp = head;
    printf("The Linked List is:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(struct Node* head,int n){
    if (head == NULL) {
        printf("Null Linked List\n");
        return;
    }
    struct Node *temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == n) {
            printf("\nElement was found at position: %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found\n");
}

int main(){
    struct Node* head = NULL;
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    input(n,&head);
    print(head);
    printf("\nEnter the element to be searched:- ");
    scanf("%d",&n);
    search(head,n);
}