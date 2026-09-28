#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev=NULL;
    struct Node* next=NULL;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, int data){
    Node* newNode = createNode(data);
    if(*head==NULL){
        *head = newNode;
        return;
    }
    else{
        newNode->next=*head;
        (*head)->prev=newNode;
        *head=newNode;
    }
}

void insertAtEnd(Node **head, int data){
    Node* newNode = createNode(data);
    if(*head==NULL){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev=temp;
}

void insertAtPosition(Node** head, int data, int position)
{
    int i;
	if (position < 1) {
        printf("Position should be >= 1.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf(
            "Position greater than the number of nodes.\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteAtBeginning(Node** head){
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteAtEnd(Node** head){
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    Node* temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPosition(Node** head, int position)
{
    int i;
	if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }
    Node* temp = *head;
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    for (i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position is greater than the number of "
               "nodes.\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}
