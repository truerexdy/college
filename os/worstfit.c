#include <stdio.h>
#include <stdlib.h>
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
    if(nblocks >= MAX){
        printf("Size too big, please choose less number of blocks\\n");
        exit(0);
    }
    printf("Enter the number of files:\n");
    scanf("%d", &nfiles);
    if(nfiles >= MAX){
        printf("Size too big, please choose less number of files\\n");
        exit(0);
    }

    if(nfiles > nblocks){
        printf("Number of files greater than number of available blocks\n");
        exit(0);
    }

    printf("Enter the block sizes:\n");
    for(int i=0; i<nblocks; i++){
        scanf("%d", &blocks[i]);
    }

    printf("Enter the file sizes:\n");
    for(int i=0; i<nfiles; i++){
        scanf("%d", &files[i]);
    }

    for(int i=0; i<nfiles; i++){
        int highest = 0;
        for(int j=0; j<nblocks; j++){
            if(allocation[j]==-1){
                if(blocks[highest]<blocks[j]){
                    highest = j;
                }
            }
            else{
                continue;
            }
        }
        if(blocks[highest]>=files[i]){
            allocation[highest]=i;
            fragment[highest]=blocks[highest]-files[i];
        }
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