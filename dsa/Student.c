#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    char usn[12];
    char name[64];
    char prog[256];
    int sem;
    unsigned int phno;
    struct student* next;
}student;

student* create(){
    student* temp = (student*)malloc(sizeof(student));
    if(!temp){
        printf("Bad Malloc");
        return NULL;
    }
    printf("Enter Name:\n");
    scanf("%s", temp->name);
    printf("Enter USN:\n");
    scanf("%s", temp->usn);
    printf("Enter Programme:\n");
    scanf("%s", temp->prog);
    printf("Enter Sem:\n");
    scanf("%d", &temp->sem);
    printf("Enter PhNo:\n");
    scanf("%d", &temp->phno);
    return temp;
}

student* insertAtStart(student* head){
    student* temp = create();
    if(!head){
        head=temp;
        return head;
    }
    temp->next=head;
    head=temp;
    return head;
}

student* deleteAtStart(student* head){
    if(!head){
        printf("EmptyList");
        return NULL;
    }
    student* temp = head;
    head = head->next;
    free(temp);
    return head;
}

student* insertAtEnd(student* head){
    student* temp = create();
    temp->next=NULL;
    if(!head){
        head=temp;
        return head;
    }
    student* current = head;
    while(current->next){
        current=current->next;
    }
    current->next=temp;
    return head;
}

student* deleteAtEnd(student* head){
    if(!head){
        printf("EmptyList");
        return NULL;
    }
    student* current = head;
    while(current->next){
        current=current->next;
    }
    student* temp = current->next;
    current->next = NULL;
    free(current->next);
    return head;
}

int display(student* head){
    int count = 0;
    student* current = head;
    while(current){
        printf("Name: %s\n", current->name);
        printf("USN: %s\n", current->usn);
        printf("Prog: %s\n", current->prog);
        printf("Sem: %d\n", current->sem);
        printf("PhNO: %d\n", current->phno);
        current=current->next;
        count++;
    }
    printf("Number of Nodes is: %d\n", count);
    return count;
}

int main(){
    printf("Enter the number of students: ");
    int n;
    scanf("%d", &n);
    student* head = NULL;
    for(int i=0; i<n; i++){
        insertAtStart(head);
    }
    int uin;
    do{
        printf("Enter a choise: \n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d", &uin);
        switch (uin)
        {
        case 1:
            insertAtEnd(head);
            break;
        case 2:
            deleteAtEnd(head);
            break;
        case 3:
            display(head);
            break;
        default:
            break;
        }
    }while(uin!=4);
    return 0;
}