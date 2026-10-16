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
    if (r == NULL) return create(x);
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
void preorder(struct Node* r) {
    if (r) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}
void postorder(struct Node* r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}
int search(struct Node* r, int key) {
    if (!r) return 0;
    if (r->data == key) return 1;
    if (key < r->data) return search(r->left, key);
    return search(r->right, key);
}
int main() {
    struct Node* root = NULL;
    int n, x, key, i;
    printf("Enter number of values: ");
    scanf("%d", &n);
    printf("Enter unique values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("Inorder: "); inorder(root);
    printf("\nPreorder: "); preorder(root);
    printf("\nPostorder: "); postorder(root);
    printf("\nEnter value to search: ");
    scanf("%d", &key);
    if (search(root, key)) printf("Value found");
    else printf("Value not found");
    return 0;
}
