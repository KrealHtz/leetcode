#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// 前序遍历
void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val); // 先访问根节点
    preorderTraversal(root->left); // 再遍历左子树
    preorderTraversal(root->right); // 最后遍历右子树
}

// 中序遍历
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left); // 先遍历左子树
    printf("%d ", root->val); // 再访问根节点
    inorderTraversal(root->right); // 最后遍历右子树
}

// 后序遍历
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left); // 先遍历左子树
    postorderTraversal(root->right); // 再遍历右子树
    printf("%d ", root->val); // 最后访问根节点
}

int main() {
    // Create a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    postorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    preorderTraversal(root);
    printf("\n");
    // Print the values of the binary tree
    printf("Binary Tree: %d\n", root->val);
    printf("Left Child: %d\n", root->left->val);
    printf("Right Child: %d\n", root->right->val);
    printf("Left Child of Left Child: %d\n", root->left->left->val);
    printf("Right Child of Left Child: %d\n", root->left->right->val);

    return 0;
}
