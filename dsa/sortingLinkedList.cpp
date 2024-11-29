#include <iostream>

using std::cin, std::cout;

typedef struct node{
    int data;
    struct node* next;
}node;

node* insertToSortedHead(node* sortedHead, node* newNode){
    if (!sortedHead || sortedHead->data >= newNode->data) {
        newNode->next = sortedHead;
        return newNode;
    }
    node* curr = sortedHead;
    while (curr->next && curr->next->data < newNode->data) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return sortedHead;
}


node* createNewNode(int value){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void display(node* head){
    if(!head){
        cout << "empty\n";
        return;
    }
    else{
        while(head){
            cout << head->data << " ";
            head = head->next;
        }
        cout << "\n";
        return;
    }
}

node* insertAtEnd(node* head, int value){
    if(!head){
        head = createNewNode(value);
        return head;
    }
    else{
        node* curr = head;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = createNewNode(value);
        return head;
    }
}

node* sortList(node* unsortedHead, node* sortedHead){
    if(!unsortedHead){
        cout << "Empty list";
        return nullptr;
    }
    else{
        node* curr = unsortedHead;
        while(curr){
            node* nextNode = curr->next;
            curr->next = nullptr;
            sortedHead = insertToSortedHead(sortedHead, curr);
            curr = nextNode;
        }
        return sortedHead;
    }
}

int main(){
    node* unsortedHead = NULL;
    node* sortedHead = NULL;

    unsortedHead = insertAtEnd(unsortedHead, 9);
    unsortedHead = insertAtEnd(unsortedHead, 2);
    unsortedHead = insertAtEnd(unsortedHead, 7);
    unsortedHead = insertAtEnd(unsortedHead, 13);
    unsortedHead = insertAtEnd(unsortedHead, 0);
    unsortedHead = insertAtEnd(unsortedHead, 69);
    display(unsortedHead);
    sortedHead = sortList(unsortedHead, sortedHead);
    display(sortedHead);
    return 0;
}