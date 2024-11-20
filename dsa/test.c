#include <stdio.h>
#include <stdlib.h>

int test(int* a){
    printf("%p\n", a);
    return 0;
}

int main(){
    int* a = (int*)malloc(sizeof(int));
    printf("%p\n", a);
    test(a);
}