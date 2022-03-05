/*
------------ 二叉搜索树的操作集 (30 分) -------------
  https://pintia.cn/problem-sets/15/problems/927
---------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT);  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;
    BST = NULL;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:");
    PreorderTraversal(BST);
    printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL)
            printf("%d is not found\n", X);
        else
        {
            printf("%d is found\n", Tmp->Data);
            if (Tmp == MinP)
                printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp == MaxP)
                printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:");
    InorderTraversal(BST);
    printf("\n");
    return 0;
}

/* 你的代码将被嵌在这里 */
BinTree Insert(BinTree BST, ElementType X)
{
    if (BST == NULL)
    {
        BST = (BinTree)malloc(sizeof(BinTree));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else
    {
        if (X > BST->Data)
        {
            BST->Right = Insert(BST->Right, X);
        }
        else if (X < BST->Data)
        {
            BST->Left = Insert(BST->Left, X);
        }
    }
    return BST;
}

BinTree Delete(BinTree BST, ElementType X)
{
    BinTree tmp;
    if (BST == NULL)
    {
        printf("Not Found\n");
        return 0;
    }
    else
    {
        if (X < BST->Data)
            BST->Left = Delete(BST->Left, X); /* 左子树递归删除 */
        else if (X > BST->Data)
            BST->Right = Delete(BST->Right, X); /* 右子树递归删除 */
        else
        { /* 找到需要删除的结点 */
            if (BST->Left && BST->Right)
            {
                /* 被删除的结点有左右子结点 */
                tmp = FindMin(BST->Right);
                /* 在右子树中找到最小结点填充删除结点 */
                BST->Data = tmp->Data;
                BST->Right = Delete(BST->Right, BST->Data);
                /* 递归删除要删除结点的右子树中最小元素 */
            }
            else
            {
                /* 被删除结点有一个或没有子结点 */
                tmp = BST;
                if (!BST->Left)
                    BST = BST->Right;
                /* 有右孩子或者没孩子 */
                else if (!BST->Right)
                    BST = BST->Left;
                /* 有左孩子，一定要加else，不然BST可能是NULL，会段错误 */
                else
                    free(tmp);
            }
        }
    }
    return BST;
}

Position Find(BinTree BST, ElementType X)
{
    if (BST == NULL)
        return 0;
    if (BST->Data == X)
        return BST;
    if (BST->Data > X)
        return Find(BST->Left, X);
    if (BST->Data < X)
        return Find(BST->Right, X);
}

Position FindMin(BinTree BST)
{
    if (BST)
    {
        while (BST->Left)
        {
            BST = BST->Left;
        }
    }
    return BST;
}

Position FindMax(BinTree BST)
{
    if (BST)
    {
        while (BST->Right)
        {
            BST = BST->Right;
        }
    }
    return BST;
}