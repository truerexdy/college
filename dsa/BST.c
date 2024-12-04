#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
}node;

node* create(int value){
    node* temp = (node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

node* insert(node* root, node* newnode){
    if(!root){
        return newnode;
    }
    if(newnode->data == root->data){
        printf("\nelement already exists\n");
        return root;
    }
    else if(newnode->data < root->data){
        root->lchild = insert(root->lchild, newnode);
        return root;
    }
    else{
        root->rchild = insert(root->rchild, newnode);
        return root;
    }
}

void preorder(node* root){
    if(!root){
        return;
    }
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(node* root){
    if(!root){
        return;
    }
    preorder(root->lchild);
    printf("%d ", root->data);
    preorder(root->rchild);
}

void postorder(node* root){
    if(!root){
        return;
    }
    preorder(root->lchild);
    preorder(root->rchild);
    printf("%d ", root->data);
}

int search(node* root, int key){
    if(!root){
        return 0;
    }
    if(root->data == key){
        return 1;
    }
    else if(key < root->data){
        return search(root->lchild, key);
    }
    else{
        return search(root->rchild, key);
    }
}

int main(){
    node* root = NULL;
    int uin=0;
    while(1){
        printf("\n1.Insert\n2.Pre-Order\n3.In-Order\n4.Post-Order\n5.Search\n6.Exit\n");
        printf("Choose an option:\n");
        scanf("%d", &uin);
        switch(uin){
            case 1:
            printf("Enter the value:\n");
            int inp;
            scanf("%d", &inp);
            root = insert(root, create(inp));
            break;
            case 2:
            preorder(root);
            break;
            case 3:
            inorder(root);
            break;
            case 4:
            postorder(root);
            break;
            case 5:
            printf("Enter the key to search:\n");
            scanf("%d", &inp);
            if(search(root, inp)){
                printf("Key found in the Tree\n");
            }
            else{
                printf("Key not found in the Tree\n");
            }
            break;
            case 6:
            exit(0);
            break;
        }
    }
    return 0;
}