#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
typedef struct TNode *BiTree;
typedef struct TNode
{
    ElemType Data;
    struct TNode *Left;
    struct TNode *Right;
} tnode;
int N;
BiTree createNode()
{
    BiTree node = new TNode;
    node->Left = NULL;
    node->Right = NULL;
    return node;
}
BiTree CreaTree(int number[10000][15], int x)
{
    if (x == -1)
        return NULL;
    BiTree BT;
    BT=(BiTree)malloc(sizeof(struct TNode));
    BT = createNode();
    BT->Data = x;
    BT->Left = CreaTree(number, number[x][0]);
    BT->Right = CreaTree(number, number[x][1]);
    return BT;
}
int flag = 0;
void PreorderTraversal(BiTree BT)
{
    if (BT)
    {
        flag++;
        if (flag == N)
            cout << BT->Data;
        else
            cout << BT->Data << " ";
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void InorderTraversal(BiTree BT)
{
    if (BT)
    {
        InorderTraversal(BT->Left);
        flag++;
        if (flag == 2 * N)
            cout << BT->Data;
        else
            cout << BT->Data << " ";
        InorderTraversal(BT->Right);
    }
}
void PostorderTraversal(BiTree BT)
{
    if (BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        flag++;
        if (flag == 3 * N)
            cout << BT->Data;
        else
            cout << BT->Data << " ";
    }
}

int main()
{
    int i, a[10000][15], b[10000];
    cin >> N;
    for (i = 1; i <= N; i++)
    {
        cin >> b[i] >> a[i][0] >> a[i][1];
    }
    BiTree BT;
    BT = CreaTree(a, 1);
    PreorderTraversal(BT);
    cout << endl;
    InorderTraversal(BT);
    cout << endl;
    PostorderTraversal(BT);
    cout << endl;
    return 0;
}