#include <stdio.h>
#include <stdlib.h>
#define MAX 16

void linprob(int a[], int value){
    int hash = value%MAX;
    if(a[hash]!=-1){
        printf("\nCollision Occured at %d for %d\n\n", hash, value);
        int flag = 0;
        for(int i=hash+1; i!=hash; i=(i+1)%MAX){
            if(a[i]!=-1){
                flag = 1;
                a[i]=value;
                printf("\nCollision resolved at %d for %d\n\n", hash, value);
                break;
            }
        }
        if(flag == 0){
            printf("\nHash Table Full\n\n");
        }
    }
    else{
        a[hash]=value;
    }
}

void display(int a[], int fil){
    if(fil){
        for(int i=0; i<MAX; i++){
            if(a[i]!=-1){
                printf("%d ", a[i]);
            }
        }
    }
    else{
        for(int i=0; i<MAX; i++){
            printf("%d ", a[i]);
        }
    }
}

int main(){
    int ht[MAX];
    for(int i=0; i<MAX; i++){
        ht[i]=-1;
    }
    while(1){
        printf("\n1. Insert\n2. Display Filtered\n3. Display All\n4. Exit\n");
        int uin=0;
        scanf("%d", &uin);
        switch (uin){
            case 1:
            printf("Enter the value to hash:");
            scanf("%d", &uin);
            linprob(ht, uin);
            break;
            case 2:
            display(ht, 1);
            break;
            case 3:
            display(ht, 0);
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nEnter a valid option\n\n");
            break;
        }
    }
    return 0;
}