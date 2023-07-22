#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    int rank;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int val, int rank) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->rank = rank;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int rankOf(Node* node) {
    if (node == NULL)
        return 0;
    return node->rank;
}

void updateRank(Node* node) {
    node->rank = rankOf(node->left) + 1;
}

Node* rightRotate(Node* x) {
    Node* y = x->left;
    Node* z = y->right;
    y->right = x;
    x->left = z;
    updateRank(x);
    updateRank(y);
    return y;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* z = y->left;
    y->left = x;
    x->right = z;
    updateRank(x);
    updateRank(y);
    return y;
}

Node* balanceNode(Node* node) {
    if (rankOf(node->left) - rankOf(node->right) > 1) {
        if (rankOf(node->left->left) >= rankOf(node->left->right))
            node = rightRotate(node);
        else {
            node->left = leftRotate(node->left);
            node = rightRotate(node);
        }
    }
    else if (rankOf(node->right) - rankOf(node->left) > 1) {
        if (rankOf(node->right->right) >= rankOf(node->right->left))
            node = leftRotate(node);
        else {
            node->right = rightRotate(node->right);
            node = leftRotate(node);
        }
    }
    return node;
}

Node* insert(Node* root, int val) {
    if (root == NULL)
        return createNode(val, 1);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    updateRank(root);
    return balanceNode(root);
}

Node* findMinNode(Node* node) {
    if (node->left == NULL)
        return node;
    return findMinNode(node->left);
}

Node* deleteMinNode(Node* node) {
    if (node->left == NULL)
        return node->right;
    node->left = deleteMinNode(node->left);
    updateRank(node);
    return balanceNode(node);
}

Node* delete(Node* root, int val) {
    if (root == NULL)
        return NULL;
    if (val < root->val)
        root->left = delete(root->left, val);
    else if (val > root->val)
        root->right = delete(root->right, val);
    else {
        Node* leftChild = root->left;
        Node* rightChild = root->right;
        free(root);
        if (rightChild == NULL)
            return leftChild;
        Node* minNode = findMinNode(rightChild);
        minNode->right = deleteMinNode(rightChild);
        minNode->left = leftChild;
        updateRank(minNode);
        return balanceNode(minNode);
        }
    updateRank(root);
    return balanceNode(root);
}

Node* search(Node* root, int val) {
    if (root == NULL || root->val == val)
        return root;
    if (val < root->val)
        return search(root->left, val);
    else
        return search(root->right, val);
}

void insertRandomNumbers(Node** root) {
    for (int i = 0; i < 500; i++) {
        int num = rand() % 1000;
        *root = insert(*root, num);
    }
}

void findAndDeleteMin(Node** root) {
    for (int i = 0; i < 100; i++) {
        Node* minNode = findMinNode(*root);
        printf("Minimum item: %d\n", minNode->val);
        *root = delete(*root, minNode->val);
    }
}

Node* join(Node* T1, Node* T2) {
    if (T1 == NULL)
        return T2;
    if (T2 == NULL)
        return T1;
    if (T1->rank > T2->rank) {
        T1->right = join(T1->right, T2);
        updateRank(T1);
        return balanceNode(T1);
    }
    else {
        T2->left = join(T1, T2->left);
        updateRank(T2);
        return balanceNode(T2);
    }
}

void split(Node* T, int val, Node** T1, Node** T2) {
    if (T == NULL) {
        *T1 = NULL;
        *T2 = NULL;
        return;
    }
    if (val < T->val) {
        split(T->left, val, T1, &(T->left));
        *T2 = T;
    }
    else {
        split(T->right, val, &(T->right), T2);
        *T1 = T;
    }
    updateRank(T);
}

void inOrderTraversal(Node* node) {
    if (node == NULL) return;
    inOrderTraversal(node->left);
    printf("%d ", node->val);
    inOrderTraversal(node->right);
}

int main() {
    Node* root = NULL;
    Node** T1 = NULL;
    Node** T2 = NULL;
    insertRandomNumbers(&root);
    inOrderTraversal(root);
    split(root,386,&T1,&T2);
    printf("\n");
    inOrderTraversal(T1);
    printf("\n");
    inOrderTraversal(T2);
    printf("\n");
    join(T1,T2);
    inOrderTraversal(T1);
    return 0;
}