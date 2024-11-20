#include <stdio.h>

void TOH(int n, char src, char temp, char dest){
    if(n<1){
        return;
    }
    TOH(n-1, src, dest, temp);
    printf("%d disk is moved form %c to %c\n", n,src,dest);
    TOH(n-1, temp, src, dest);
}

int main(){
    int n = 5;
    TOH(n, 'A', 'B', 'C');
    return 0;
}