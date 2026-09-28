#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* right;
    struct Node* left;
};

struct Node* createNode (int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int postIndex;

struct Node* buildTree(int post[], int in[], int start, int end) {
    if (start > end)
    
        return NULL;

    struct Node* root = createNode(post[postIndex--]);
    int i = start;
    while (in[i] != root->data) {
        i++;
    }
    root->right = buildTree(post, in, i + 1, end);
    root->left = buildTree(post, in, start, i - 1);
    return root;
}

void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(void) {
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int post[n], in[n];

    printf("Enter postorder: ");
    for (i = 0; i < n; i++) scanf("%d", &post[i]);
    printf("Enter inorder: ");
    for (i = 0; i < n; i++) scanf("%d", &in[i]);

    postIndex = n - 1;
    printf("Preorder: ");
    preorder(buildTree(post, in, 0, n - 1));
    return 0;
}