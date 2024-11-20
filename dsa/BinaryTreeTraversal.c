typedef struct node{
    int data;
    struct node left;
    struct node right;
} node;

// In-Order
void inOrder(node root)[
    if(!root){
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
]

// Pre-Order
void preOrder(node root){
    if(!root){
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Post-Order
void postOrder(node root){
    if(!root){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);   
}