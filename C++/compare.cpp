#include <bits/stdc++.h>
using namespace std;
int b[100] = {0};

typedef struct BiTreeNode
{
    int data;
    struct BiTreeNode *lchild, *rchild;
} BiTreeNode, *LinkBiTreeNode;

LinkBiTreeNode CreateBiTree1()
{
    int Data;
    LinkBiTreeNode node;
    scanf("%d", &Data);
    if (Data == 0)
    {
        node = NULL;
    }
    else
    {
        node = (LinkBiTreeNode)malloc(sizeof(BiTreeNode));
        node->data = Data;
        node->lchild = CreateBiTree1();
        node->rchild = CreateBiTree1();
    }
    return node;
}

int sum = 0;
int x = 1;

void P(LinkBiTreeNode BT)
{
    if (BT)
    {
        if (BT->lchild == NULL && BT->rchild == NULL)
            b[x] += BT->data;

        P(BT->lchild);
        P(BT->rchild);
        if (BT->lchild != NULL && BT->rchild != NULL)
            x++;
    }
    return;
}

int compare(int *a, int k)
{
    int i, j, temp = a[0], l = 0;
    for (j = 1; j < k; j++)
    {
        if (temp <= a[j])
        {
            temp = a[j];
            l = j;
        }
    }
    return l;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    LinkBiTreeNode T = NULL;
    T = CreateBiTree1();
    P(T);
    int l = compare(b, x);
    cout << l << endl;
    return 0;
}