#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int elemtype;
typedef struct lnode{
    elemtype data;
    struct londe *next;
} lnode;
lnode *l;
lnode * creat_l();
void out_l(lnode *l);
void insert_l(lnode *l, int i, elemtype e);
elemtype delete_l(lnode *l, int i);
int locat_l(lnode *l, elemtype e);
main(){
    int i, k, loc;
    elemtype e, x;
    char ch;
    do{
        printf("\n\n\n");
        printf("\n\n  ");
    }
} 