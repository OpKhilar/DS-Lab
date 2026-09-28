#include <stdio.h>
#include <stdlib.h>

// Step 1: Define the structure of a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the singly linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;    // Tracks the previous node
    struct Node* curr = head;    // Tracks the current node
    struct Node* next = NULL;    // Tracks the next node

    while (curr != NULL) {
        next = curr->next;  // 1. Save the next node
        curr->next = prev;  // 2. Reverse the current node's pointer
        prev = curr;        // 3. Move 'prev' one step forward
        curr = next;        // 4. Move 'curr' one step forward
    }
    
    // 'prev' now points to the new head of the reversed list
    return prev;
}

// Helper function to insert a new node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Helper function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Create a linked list: 40 -> 30 -> 20 -> 10 -> NULL
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    printf("Original Linked List:\n");
    printList(head);

    // Reverse the list
    head = reverseList(head);

    printf("\nReversed Linked List:\n");
    printList(head);

    return 0;
}