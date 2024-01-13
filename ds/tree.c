
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

// Non-recursive inorder traversal
void inorderTraversalNonRecursive(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    struct TreeNode* stack[100]; // Stack to store nodes
    int top = -1; // Top of the stack
    
    struct TreeNode* current = root;
    
    while (current != NULL || top != -1) {
        // Traverse to the leftmost node
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        
        // Pop the top node from the stack
        current = stack[top--];
        
        // Process the current node
        printf("%d ", current->val);
        
        // Traverse to the right subtree
        current = current->right;
    }
}

// Non-recursive preorder traversal
void preorderTraversalNonRecursive(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    struct TreeNode* stack[100]; // Stack to store nodes
    int top = -1; // Top of the stack
    
    struct TreeNode* current = root;
    
    while (current != NULL || top != -1) {
        // Process the current node
        printf("%d ", current->val);
        
        // Push the right child to the stack
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        
        // Traverse to the left subtree
        current = current->left;
        
        // If left subtree is NULL, pop the top node from the stack
        if (current == NULL && top != -1) {
            current = stack[top--];
        }
    }
}

// Non-recursive postorder traversal
void postorderTraversalNonRecursive(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    struct TreeNode* stack[100]; // Stack to store nodes
    int top = -1; // Top of the stack
    
    struct TreeNode* current = root;
    struct TreeNode* lastVisited = NULL; // Last visited node
    
    while (current != NULL || top != -1) {
        // Traverse to the leftmost node
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        
        // Peek the top node from the stack
        struct TreeNode* peekNode = stack[top];
        
        // If the right subtree is NULL or already visited, process the current node
        if (peekNode->right == NULL || peekNode->right == lastVisited) {
            // Process the current node
            printf("%d ", peekNode->val);
            
            // Pop the top node from the stack
            lastVisited = stack[top--];
        } else {
            // Traverse to the right subtree
            current = peekNode->right;
        }
    }
}

int main() {
    // Create a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    // Perform non-recursive traversals
    printf("Inorder Traversal (Non-Recursive): ");
    inorderTraversalNonRecursive(root);
    printf("\n");
    
    printf("Preorder Traversal (Non-Recursive): ");
    preorderTraversalNonRecursive(root);
    printf("\n");
    
    printf("Postorder Traversal (Non-Recursive): ");
    postorderTraversalNonRecursive(root);
    printf("\n");
    
    return 0;
}

