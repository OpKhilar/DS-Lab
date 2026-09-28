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

void preorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

void inorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Function to find the minimum value node (used for deletion)
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        printf("Value %d not found in the tree.\n", value);
        return root;
    }

    // Traverse to locate the node
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node found: Handle the 3 deletion cases
        
        // Case 1 & 2: No child or only one child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        // Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(void) {
    struct Node* root = NULL;
    int choice;
    int value;

    do {
        printf("\n--- Binary Search Tree ---\n");
        printf("1. Insert\n");
        printf("2. Insert multiple elements\n");
        printf("3. Preorder traversal\n");
        printf("4. Inorder traversal\n");
        printf("5. Postorder traversal\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
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
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}
