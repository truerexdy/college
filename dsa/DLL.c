#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char ssn[12];
    char name[64];
    char dept[63];
    char desig[128];
    unsigned long int sal;
    unsigned long int phno;
    struct node* next;
    struct node* prev;
} node;

node* create(){
    node* temp = (node*)malloc(sizeof(node));
    printf("\nEnter the SNN:\n");
    scanf("%s", temp->ssn);
    printf("\nEnter the Name:\n");
    scanf("%s", temp->name);
    printf("\nEnter the Dept:\n");
    scanf("%s", temp->dept);
    printf("\nEnter the Designation:\n");
    scanf("%s", temp->desig);
    printf("\nEnter the Salary:\n");
    scanf("%ld", &temp->sal);
    printf("\nEnter the PhNo:\n");
    scanf("%ld", &temp->phno);
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

node* insertAtEnd(node* head){
    if(!head){
        head = create();
        return head;
    }
    else{
        node* curr = head;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = create();
        curr->next->prev = curr;
        return head;
    }
}

node* insertAtStart(node* head){
    if(!head){
        head = create();
        return head;
    }
    else{
        node* temp = head;
        head = create();
        head->next=temp;
        temp->prev=head;
        return head;
    }
}

node* deleteAtEnd(node* head){
    if(!head){
        printf("\nEmpty List\n");
        return NULL;
    }
    else{
        node* curr = head;
        while(curr->next){
            curr=curr->next;
        }
        node* temp;
        if(curr->prev){
            temp = curr->prev;
        }
        else{
            temp = NULL;
        }
        free(curr);
        if(temp){
            temp->next = NULL;
        }
        else{
            head = NULL;
        }
        return head;
    }
}

node* deleteAtStart(node* head){
    if(!head){
        printf("\nEmpty List\n");
        return NULL;
    }
    else{
        node* temp = head;
        head = head->next;
        free(temp);
        if(head){
            head->prev = NULL;
        }
        return head;
    }
}

void display(node* head){
    if(!head){
        printf("\nEmpty List\n");
    }
    else{
        int i=0;
        while(head){
            printf("%d\t%s\t%s\t%s\t%s\t%ld\t%ld\n", i, head->ssn, head->name, head->dept, head->desig, head->sal, head->phno);
            head = head->next;
        }
    }
}


node* doubleQueue(node* head){
    while(1){
        printf("\n1.Enque Front\n");
        printf("2.Deque Front\n");
        printf("3.Enque Rear\n");
        printf("4.Deque Rear\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter your choise:\n");
        int uin=0;
        scanf("%d", &uin);
        switch (uin){
            case 1:
            head = insertAtStart(head);
            break;
            case 2:
            head = deleteAtStart(head);
            break;
            case 3:
            head = insertAtEnd(head);
            break;
            case 4:
            head = deleteAtEnd(head);
            break;
            case 5:
            display(head);
            break;
            case 6:
            exit(0);
        }
    }
    return head;
}

int main(){
    node* head = NULL;
    while(1){
        printf("\n1.Insert at Start\n");
        printf("2.Delete at Start\n");
        printf("3.Insert at End\n");
        printf("4.Delete at End\n");
        printf("5.Double Ended Queue\n");
        printf("6.Display\n");
        printf("7.Exit\n");
        printf("Enter your choise:\n");
        int uin=0;
        scanf("%d", &uin);
        switch (uin){
            case 1:
            head = insertAtStart(head);
            break;
            case 2:
            head = deleteAtStart(head);
            break;
            case 3:
            head = insertAtEnd(head);
            break;
            case 4:
            head = deleteAtEnd(head);
            break;
            case 5:
            head = doubleQueue(head);
            break;
            case 6:
            display(head);
            break;
            case 7:
            exit(0);
        }
    }
    return 0;
}