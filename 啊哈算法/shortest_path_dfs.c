/**
 * 使用深度优先搜索查找两个城市之间的最短路径
 * gcc -o exe\shortest_path_dfs.exe shortest_path_dfs.c
 * case:
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
 * result:
9
 */
#include <stdio.h>
#define ASIZE 101

int min = 99999999, n;
int e[ASIZE][ASIZE];
int book[ASIZE];

void dfs(int, int);

int main() {
    int i, j, m, a, b, c;
    scanf("%d %d", &n, &m);
    //初始化数组
    for(i = 1; i <= n; ++i) {
        for(j =1; j <= n; ++j) {
            if(i == j)  //自己
                e[i][j] = 0;
            else
                e[i][j] = 9999999;
        }
    }

    //读入城市间的道路
    for(i = 1; i <= m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        e[a][b] = c;
    }

    book[1] = 1;
    dfs(1, 0);
    printf("%d\n", min);
    return 0;
}

/**
 * cur: 当前所有城市
 * dis: 当前已经走过的距离
 */
void dfs(int cur, int dis) {
    int i;
    if(dis > min)
        return;
    if(cur == n) {
        if(dis < min)
            min = dis;
        return;
    }
    for(i = 1; i <= n; ++i) {   //尝试所有点
        //是否有路到下一个城市，并且下一个城市还没走过
        if(e[cur][i] != 99999999 && book[i] == 0) {
            book[i] = 1;
            dfs(i, dis + e[cur][i]);
            book[i] = 0;
        }
    }
    return;
}
