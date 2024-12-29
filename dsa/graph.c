#include <stdio.h>
#include <stdlib.h>
#define MAX 16

int graph[MAX][MAX];
int queue[MAX], front = -1, rear = -1;
int stack[MAX], top=-1;
int visited[MAX];

void dfs(int start){
    stack[++top]=start;
    visited[start]=1;
    printf("%d ", start);
    while(top!=-1){
        start = stack[top--];
        for(int i=0;i<MAX;i++){
            if(visited[i]==0 && graph[start][i]==1){
                dfs(i);
            }
        }
    }
}

int main(){
    for(int i=0; i<MAX; i++){
        visited[i]=0;
    }
    printf("Enter the number of nodes:\n");
    int n=0;
    scanf("%d", &n);
    printf("Enter the Adjecency Matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting node:\n");
    int uin=0;
    scanf("%d", &uin);
    dfs(0);
}