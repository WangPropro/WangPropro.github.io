/*
        求链式线性表的倒数第 K项 (20 分)
-------------------------------------------------
  https://pintia.cn/problem-sets/15/problems/826
-------------------------------------------------
    Input:  4 1 2 3 4 5 6 7 8 9 0 -1
    Output:  7
*/
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct Node *PtrToNode;
struct Node
{
    Elemtype Data;
    PtrToNode Next;
};
typedef PtrToNode List;

Elemtype Find(List L, int m)
{
    List p1, p2;
    int cnt = 0;
    p1 = p2 = L;
    while (p1 && (++cnt <= m))
        p1 = p1->Next;
    if (cnt <= m)
    {
        printf("NULL\n");
        return 0;
    }
    while (p1)
    {
        p1 = p1->Next;
        p2 = p2->Next;
    }
    return p2->Data;
}

int main()
{
    int k;
    scanf("%d", &k);
    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    int tmp;
    while (scanf("%d", &tmp) && tmp >= 0)
    {
        List L = (List)malloc(sizeof(struct Node));
        L->Next = NULL;
        L->Data = tmp;
        L = L->Next;
        head->Next = L;
    }
    Find(head, k);
    return 0;
}