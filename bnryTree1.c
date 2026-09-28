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

int preIndex = 0;

struct Node* buildTree(int pre[], int in[], int start, int end) {
    if (start > end)
        return NULL;

    struct Node* root = createNode(pre[preIndex++]);
    int i = start;
    while (in[i] != root->data) {
        i++;
    }
    root->left = buildTree(pre, in, start, i - 1);
    root->right = buildTree(pre, in, i + 1, end);
    return root;
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(void) {
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int pre[n], in[n];

    printf("Enter preorder: ");
    for (i = 0; i < n; i++) scanf("%d", &pre[i]);
    printf("Enter inorder: ");
    for (i = 0; i < n; i++) scanf("%d", &in[i]);

    printf("Postorder: ");
    postorder(buildTree(pre, in, 0, n - 1));
    return 0;
}