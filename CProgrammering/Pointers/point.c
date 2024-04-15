#include <stdio.h>

void fut(int *intpoi){
    printf("intpoi = %p\n", intpoi);
    printf("intpoi peger påå = %d\n", *intpoi);
}

int main(void) {
    int i1;

    i1 = 2024;

    printf("i1 indeholder %i\n", i1);
    printf("i1 ligger paa adresse: %p\n", &i1);
    fut(&i1);
    return(0);
}