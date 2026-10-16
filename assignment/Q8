#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* create(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}
struct Node* insert(struct Node* r, int x) {
    if (!r) return create(x);
    if (x < r->data) r->left = insert(r->left, x);
    else if (x > r->data) r->right = insert(r->right, x);
    return r;
}
void inorder(struct Node* r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}
struct Node* minNode(struct Node* r) {
    while (r->left) r = r->left;
    return r;
}
struct Node* deleteNode(struct Node* r, int key) {
    if (!r) return NULL;
    if (key < r->data)
        r->left = deleteNode(r->left, key);
    else if (key > r->data)
        r->right = deleteNode(r->right, key);
    else {
        if (!r->left && !r->right) {
            free(r);
            return NULL;
        }
        if (!r->left) {
            struct Node* t = r->right;
            free(r);
            return t;
        }
        if (!r->right) {
            struct Node* t = r->left;
            free(r);
            return t;
        }
        struct Node* t = minNode(r->right);
        r->data = t->data;
        r->right = deleteNode(r->right, t->data);
    }
    return r;
}
int main() {
    struct Node* root = NULL;
    int n, x, key, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("Inorder before deletion: ");
    inorder(root);
    printf("\nEnter value to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);
    printf("Inorder after deletion: ");
    inorder(root);
    return 0;
}
