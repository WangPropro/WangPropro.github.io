#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
void LevelorderTraversal(BinTree BT);

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    printf("Levelorder:");
    LevelorderTraversal(BT);
    printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */
void InorderTraversal(BinTree BT)
{
    if(BT)
    {
        InorderTraversal(BT->Left);
        printf(" %c", BT->Data);
        InorderTraversal(BT->Right);
    }
    else
        return 0;
}
void PreorderTraversal(BinTree BT)
{
    if(BT)
    {
        printf(" %c", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
    else
        return 0;
}
void PostorderTraversal(BinTree BT)
{
    if(BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %c", BT->Data);
    }
    else
        return 0;
}
void LevelorderTraversal(BinTree BT)
{
    BinTree q[100];
    BinTree p;
    int head = 0, tail = 0;
    if(!BT)
        return 0;
    else
    {
        q[tail++] = BT;
        while (head != tail)
        {
            p = q[head++];
            printf(" %c", p->Data);
            if(p->Left)
            {
                q[tail++] = p->Left;
            }
            if(p->Right)
            {
                q[tail++] = p->Right;
            }
        }
    }
    return p;
}