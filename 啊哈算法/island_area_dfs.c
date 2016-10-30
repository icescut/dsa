/**
 * 使用深度优先搜索解决求岛面积问题
 * gcc -o exe\island_area_dfs.exe island_area_dfs.c
 *case:
10 10 6 8
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
 *result:
38
 */
#include <stdio.h>
#define ASIZE 51

int n, m, sum;
int a[ASIZE][ASIZE];
int book[ASIZE][ASIZE];

void dfs(int, int);

int main() {
    int i, j, startx, starty;
    //有多少行，列
    scanf("%d %d %d %d", &n, &m, &startx, &starty);
    //接受行列详细数据
    for(i = 1; i <= n; ++i)
        for(j =1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    book[startx][starty] = 1;
    sum = 1;
    dfs(startx, starty);

    printf("%d\n", sum);
    return 0;
}

void dfs(int x, int y) {
    int next[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
    };
    int tx, ty, k;
    for(k = 0; k < 4; ++k) {
        tx = x + next[k][0];
        ty = y + next[k][1];
        //是否越界
        if(tx < 1 || tx > n || ty < 1 || ty > m)
            continue;
        //是陆地及没走过
        if(a[tx][ty] > 0 && book[tx][ty] == 0) {
            sum++;
            book[tx][ty] = 1;
            dfs(tx, ty);
        }
    }
    return;
}
