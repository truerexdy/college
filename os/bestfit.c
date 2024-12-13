#include <stdio.h>
#define MAX 16

int main(){
    unsigned int blocks[MAX];
    unsigned int files[MAX];
    unsigned int nblocks;
    unsigned int nfiles;
    int allocation[MAX];
    unsigned int fragment[MAX];

    for(int i=0; i<MAX; i++){
        allocation[i] = -1;
    }

    printf("Enter the number of blocks:\n");
    scanf("%d", &nblocks);
    printf("Enter the number of files:\n");
    scanf("%d", &nfiles);

    printf("Enter the block sizes:\n");
    for(int i=0; i<nblocks; i++){
        scanf("%d", &blocks[i]);
    }

    printf("Enter the file sizes:\n");
    for(int i=0; i<nfiles; i++){
        scanf("%d", &files[i]);
    }

    for(int i=0; i<nfiles; i++){
        int lowest = 0;
        for(int j=0; j<nblocks; j++){
            if(allocation[j]==-1){
                if(blocks[lowest]>blocks[j]&&blocks[j]>=files[i]){
                    lowest = j;
                    break;
                }
            }
            else{
                continue;
            }
        }
        allocation[lowest]=i;
        fragment[lowest]=blocks[lowest]-files[i];
    }

    printf("\nFile No:\tFile Size:\tBlock No:\tBlock Size:\tFragment Size:");
    for(int i=0; i<nblocks; i++){
        if(allocation[i]!=-1){
            printf("\n\t%d\t\t%d\t\t%d\t\t%d\t\t%d", allocation[i], files[allocation[i]], i, blocks[i], fragment[i]);
        }
    }
    printf("\n");
    return 0;
}