#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
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
    printf("Enter the elements: ");
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

struct Node* largest(struct Node* head){
    if (head == NULL) return NULL;
    struct Node *temp = head->next;
    struct Node *current = head;
    while (temp != NULL) {
        if (current->data < temp->data) {
            current = temp;
        }
        temp = temp->next;
    }
    return current;
}

struct Node* smallest(struct Node* head){
    if (head == NULL) return NULL;
    struct Node *temp = head->next;
    struct Node *current = head;
    while (temp != NULL) {
        if (current->data > temp->data) {
            current = temp;
        }
        temp = temp->next;
    }
    return current;
}

int sum(struct Node* head){
    struct Node *temp; int sum=0;
    temp = head;
    while(temp!=NULL){
         sum+=temp->data;
         temp=temp->next;
    }
    return sum;
}

int average(struct Node* head){
    if (head == NULL) return 0;
    struct Node *temp = head;
    int s = sum(head);
    int k = 0;
    while (temp != NULL) {
        k++;
        temp = temp->next;
    }
    if (k == 0) return 0;
    return s / k;
}

int main(){
    struct Node* head=NULL;
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    input(n,&head);
    print(head);
    struct Node* max = largest(head);
    struct Node* min = smallest(head);
    int s = sum(head);
    int av = average(head);
    printf("Largest element is: %d\n",max->data);
    printf("Smallest element is: %d\n",min->data);
    printf("Sum of the elements= %d\n",s);
    printf("Average of the elements= %d\n",av);
}