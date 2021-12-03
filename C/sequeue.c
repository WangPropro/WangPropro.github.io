/*
        最长连续递增子序列
----------------------------------------
    P52       测试用例：
输入：   15 1 9 2 5 7 3 4 6 8 0 11 15 17 10
输出：   3 4 6 8
输入：   9 1 2 3 4 5 6 7 8 9
输出：   1 2 3 4 5 6 7 8 9
输入：   9 9 8 7 6 5 4 3 2 1
输出:    9
输入：   1 233
输出：   233
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10000

typedef int ElemType;
typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElemType Data[MaxSize];
    Position Last;
};

List ReadInput()
{
    List L;
    int N;
    L = (List)malloc(sizeof(struct LNode));
    scanf("%d", &N);
    for (L->Last = 0; L->Last < N; L->Last++)
        scanf("%d", &L->Data[L->Last]);
    L->Last--;
    return L;
}

void PrintResult(List L, Position Left, Position Right)
{
    Position i;
    printf("%d", L->Data[Left]);
    for (i = Left + 1; i <= Right; i++)
        printf(" %d", L->Data[i]);
    printf("\n");
}

int main()
{
    List L;
    Position Left, Right, thisL, thisR, i;
    int maxLen, thisLen;
    L = ReadInput();
    Left = Right = thisL = thisR = 0;
    maxLen = thisLen = 1;
    for (i = 1; i <= L->Last; i++)
    {
        if (L->Data[i] > L->Data[i - 1])
        {
            thisLen++;
            thisR++;
        }
        else
        {
            if (thisLen > maxLen)
            {
                maxLen = thisLen;
                Left = thisL;
                Right = thisR;
            }
            thisLen = 1;
            thisL = thisR = i;
        }
    }
    if (thisLen > maxLen)
    {
        maxLen = thisLen;
        Left = thisL;
        Right = thisR;
    }
    PrintResult(L, Left, Right);
    return 0;
}