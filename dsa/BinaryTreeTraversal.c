#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

// Function prototypes
node* createNode(int value);
node* insert(node* root, int value);
void inOrder(node* root);
void preOrder(node* root);
void postOrder(node* root);
node* search(node* root, int value);
void freeTree(node* root);

// Create a new node
node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into the binary tree
node* insert(node* root, int value) {
    // If the tree is empty, create a new root
    if (root == NULL) {
        return createNode(value);
    }
    
    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    // Return the unchanged node pointer
    return root;
}

// In-Order Traversal
void inOrder(node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Pre-Order Traversal
void preOrder(node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Post-Order Traversal
void postOrder(node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// Search for a value in the tree
node* search(node* root, int value) {
    // Base Cases: root is null or value is present at root
    if (root == NULL || root->data == value) {
        return root;
    }
    
    // Value is greater than root's value
    if (value > root->data) {
        return search(root->right, value);
    }
    
    // Value is smaller than root's value
    return search(root->left, value);
}

// Free the entire tree to prevent memory leaks
void freeTree(node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    node* root = NULL;
    int choice, value;
    
    while (1) {
        // Display menu
        printf("\n--- Binary Tree Operations ---\n");
        printf("1. Insert a node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Search a value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        // Get user choice
        scanf("%d", &choice);
        
        // Process user choice
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted successfully.\n", value);
                break;
            
            case 2:
                printf("Preorder Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            
            case 3:
                printf("Postorder Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            
            case 4:
                printf("Inorder Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                node* result = search(root, value);
                if (result != NULL) {
                    printf("Value %d found in the tree.\n", value);
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            
            case 6:
                // Free the tree before exiting
                freeTree(root);
                printf("Exiting the program.\n");
                return 0;
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}