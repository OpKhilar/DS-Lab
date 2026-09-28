#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* concat(struct Node* head1, struct Node* head2){
    if (*head2 == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head2;
    while (temp->next != NULL) {
        temp = temp->next;
    }

}