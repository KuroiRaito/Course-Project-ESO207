#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* node, int val) {
    if (node == NULL) return createNode(val);

    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);

    return node;
}

struct TreeNode* search(struct TreeNode* node, int val) {
    if (node == NULL || node->val == val)
        return node;

    if (val < node->val)
        return search(node->left, val);

    return search(node->right, val);
}

struct TreeNode* delete(struct TreeNode* node, int val) {
    if (node == NULL) return node;

    if (val < node->val)
        node->left = delete(node->left, val);
    else if (val > node->val)
        node->right = delete(node->right, val);

    else {
        if (node->left == NULL) {
            struct TreeNode* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            struct TreeNode* temp = node->left;
            free(node);
            return temp;
        }

        struct TreeNode* temp = node->right;
        while (temp->left != NULL)
            temp = temp->left;

        node->val = temp->val;
        node->right = delete(node->right, temp->val);
    }
    return node;
}

void inOrderTraversal(struct TreeNode* node) {
    if (node == NULL) return;

    inOrderTraversal(node->left);
    printf("%d ", node->val);
    inOrderTraversal(node->right);
}

void printMinAndDelete(struct TreeNode** root) {
    struct TreeNode* current = *root;
    struct TreeNode* parent = NULL;

    if (current == NULL) return;

    while (current->left != NULL) {
        parent = current;
        current = current->left;
    }

    printf("Minimum value in tree: %d\n", current->val);

    if (parent == NULL)
        *root = current->right;
    else
        parent->left = current->right;

    free(current);
}

int main() {
    struct TreeNode* root = NULL;
    int i, val;

    printf("Inserting 5000 random numbers into the tree...\n");

    for (i = 0; i < 5000; i++) {
        val = rand() % 10000;
        root = insert(root, val);
    }

    printf("In-order traversal of the tree:\n");
    inOrderTraversal(root);
    printf("\n");

    printf("Finding, printing, and deleting the minimum item 1000 times...\n");

    for (i = 0; i < 1000; i++) {
        printMinAndDelete(&root);
    }

    return 0;
}
