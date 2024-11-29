
#include <iostream>
using std::cin, std::cout;
typedef struct node{
    int data;
    struct node* next;
}node;

node* createNewNode(int value){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
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

void display(node* head){
    if(!head){
        cout << "empty list\n";
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

node* sortList(node* head){
    if(!head){
        cout << "Empty list";
        return nullptr;
    }
    else{
        node* sortedHead = nullptr;
        node* curr = head;
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
    node* head = NULL;

    int uin = 0;
    while(1){
        cout << "Choose an option:\n1.Insert to List\n2.Display\n3.Sort\n4.Show Sorted\n5.Exit\n";
        cin >> uin;
        switch (uin){
        case 1:
            cout << "Enter the new node value:\n";
            int temp;
            cin >> temp;
            head = insertAtEnd(head, temp);
            break;
        case 2:
            display(head);
            break;
        case 3:
            cout << "Unsorted\n";
            display(head);
            head = sortList(head);
            cout << "Sorted\n";
            display(head);
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}