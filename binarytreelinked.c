#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

// Inorder traversal
void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
}

// Preorder traversal
void preorder(Node *root) {
    if (root == NULL) return;
    printf("%d -> ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d -> ", root->data);
}

// Create a new Node
Node* createNode(int value) {  // Specify 'int' type for the 'value' parameter
    Node *newNode = (Node *)malloc(sizeof(Node));  // Cast malloc's return for clarity
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert on the left of the node
Node* insertLeft(Node *root, int value) {
    root->left = createNode(value);
    return root->left;
}

// Insert on the right of the node
Node* insertRight(Node *root, int value) {
    root->right = createNode(value);
    return root->right;
}

int main() {
    Node* root = createNode(50);
    insertLeft(root, 20);
    insertRight(root, 30);
    insertLeft(root->left, 40);
    insertRight(root->left, 10);

    printf("Inorder traversal \n");
    inorder(root);
    printf("\nPreorder traversal \n");
    preorder(root);
    printf("\nPostorder traversal \n");
    postorder(root);

    return 0;
}
