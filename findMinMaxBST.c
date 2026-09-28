#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left;
    struct Node* right;
    int data;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node** position = head;

    while (*position != NULL) {
        if ((*position)->data < data) {
            position = &(*position)->right;
        }
        else {                 
            position = &(*position)->left;
        }
    }

    *position = newNode;
}

void input(struct Node** head){
    int n, i,data;
    printf("Enter the no. of elements:-");
    scanf ("%d",&n);
    
    for(i=0;i<n;i++){
        printf("Enter element:- ");
        scanf("%d", &data);
        insert(head,data);
    }
}

struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* findMax(struct Node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

int main(void) {
    struct Node* root = NULL;
    struct Node* result;
    int choice;
    int value;

    do {
        printf("\n--- BST Min/Max Menu ---\n");
        printf("1. Insert\n");
        printf("2. Insert multiple elements\n");
        printf("3. Find minimum\n");
        printf("4. Find maximum\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                break;

            case 2:
                input(&root);
                break;

            case 3:
                result = findMin(root);
                if (result == NULL) {
                    printf("The tree is empty.\n");
                } else {
                    printf("Minimum value: %d\n", result->data);
                }
                break;

            case 4:
                result = findMax(root);
                if (result == NULL) {
                    printf("The tree is empty.\n");
                } else {
                    printf("Maximum value: %d\n", result->data);
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}