/**
 * 使用深度优先搜索解决水管工问题
 * gcc -o exe\plumber_dfs.exe plumber_dfs.c
 * case:
5 4
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4
 * result:
(1,1) (1,2) (2,2) (3,2) (3,3) (3,4) (4,4) (5,4)
 */
#include <stdio.h>
#define ASIZE 51

struct note {
    int x;
    int y;
} s[100];
int n, m, flag = 0, top = 0;
int a[ASIZE][ASIZE];
int book[ASIZE][ASIZE];

void dfs(int, int, int);

int main() {
    int i, j, num;
    //有多少行，列
    scanf("%d %d", &n, &m);
    //接受行列详细数据
    for(i = 1; i <= n; ++i)
        for(j =1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    dfs(1, 1, 1);

    if(flag == 0)
        printf("impossible\n");
    return 0;
}

void dfs(int x, int y, int front) {
    int i;
    //判断是否到达终点，终点的下一点一定是(n, m+1)，这样方向才正确
    if(x == n && y == m + 1) {
        flag = 1;
        for(i = 1; i <= top; ++i) {
            printf("(%d,%d) ", s[i].x, s[i].y);
        }
        return;
    }
    //是否越界或已经用过
    if(x < 1 || x > n || y < 1 || y > m || book[x][y] == 1)
        return;
    book[x][y] = 1;
    //当前点入栈
    ++top;
    s[top].x =x;
    s[top].y =y;
    //直管
    if(a[x][y] >= 5 && a[x][y] <= 6) {
        switch (front) {
            case 1: //进水口在左边
                dfs(x, y + 1, 1);
                break;
            case 2: //进水口在上边
                dfs(x + 1, y, 2);
                break;
            case 3: //进水口在右边
                dfs(x, y - 1, 3);
                break;
            case 4: //进水口在下边
                dfs(x - 1, y, 4);
                break;
        }
    }
    //弯管
    if(a[x][y] >= 1 && a[x][y] <= 4) {
        switch (front) {
            case 1: //进水口在左边
                dfs(x + 1, y, 2);
                dfs(x - 1, y, 4);
                break;
            case 2: //进水口在上边
                dfs(x, y + 1, 1);
                dfs(x, y - 1, 3);
                break;
            case 3: //进水口在右边
                dfs(x + 1, y, 2);
                dfs(x - 1, y, 4);
                break;
            case 4: //进水口在下边
                dfs(x, y + 1, 1);
                dfs(x, y - 1, 3);
                break;
        }
    }
    //回溯
    book[x][y] = 0;
    --top;
    return;
}
