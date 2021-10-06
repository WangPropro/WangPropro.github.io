#include <stdio.h>
int a[51][51];
int book[51][51], n, m, sum;

void dfs(int x,int y,int color){
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int k, tx, ty;
    a[x][y] = color;
    for (k = 0; k <= 3;k++){
        tx = x + next[k][0];
        ty = y + next[k][1];
        if(tx<1||tx>n||ty<1||ty>m)
            continue;
            if(a[tx][ty]>0&&book[tx][ty]==0){
                sum++;
                book[tx][ty] = 1;
                dfs(tx, ty, color);
            }
    }
    return;
}

int main(){
    int i, j, num = 0;
    scanf("%d %d", &n, &m);
    
}