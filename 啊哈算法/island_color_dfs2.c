/**
 * 使用深度优先搜索着色所有岛屿(floodfill)
 * gcc -o exe\island_color_dfs2.exe island_color_dfs2.c
 *case:
10 10
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
-1 -1 -1  0  0  0  0  0 -2 -2
-1  0 -1  0 -3 -3 -3  0 -2 -2
-1  0 -1  0 -3 -3 -3 -3  0 -2
-1 -1  0  0  0 -3 -3 -3  0  0
 0  0  0  0  0  0 -3 -3 -3  0
 0 -3 -3 -3  0 -3 -3 -3 -3  0
 0 -3 -3 -3 -3 -3 -3 -3 -3  0
 0  0 -3 -3 -3 -3 -3 -3  0  0
 0  0  0 -3 -3 -3 -3  0 -4 -4
 0  0  0  0  0  0  0  0 -4  0
 */
#include <stdio.h>
#define ASIZE 51

int n, m, sum;
int a[ASIZE][ASIZE];
int book[ASIZE][ASIZE];

void dfs(int, int, int);

int main() {
    int i, j, num = 0;
    //有多少行，列
    scanf("%d %d", &n, &m);
    //接受行列详细数据
    for(i = 1; i <= n; ++i)
        for(j =1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    //着色所有陆地及未着色
    for(i = 1; i <= n; ++i) {
        for(j =1; j <= m; ++j) {
            if(a[i][j] > 0) {
                num--;
                book[i][j] = 1;
                dfs(i, j, num);
            }
        }
    }

    //输出着色后的地图
    for(i = 1; i <= n; ++i) {
        for(j =1; j <= m; ++j) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void dfs(int x, int y, int color) {
    int next[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
    };
    int tx, ty, k;
    a[x][y] = color;
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
            dfs(tx, ty, color);
        }
    }
    return;
}
