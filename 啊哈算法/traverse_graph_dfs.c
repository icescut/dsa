/**
 * 使用深度优先搜索遍历图
 * gcc -o exe\traverse_graph_dfs.exe traverse_graph_dfs.c
 * case:
5 5
1 2
1 3
1 5
2 4
3 5
 * result:
1 2 4 3 5
 */
#include <stdio.h>
#define ASIZE 101

int sum, n;
int e[ASIZE][ASIZE];
int book[ASIZE];

void dfs(int);

int main() {
    int i, j, m, a, b;
    //有多少行，列
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

    //读入有连接的两个顶点
    for(i = 1; i <= m; ++i) {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }

    book[1] = 1;
    dfs(1);
    return 0;
}

void dfs(int cur) {
    int i;
    //打印当前点
    printf("%d ", cur);
    ++sum;
    if(sum == n) {
        return;
    }
    for(i = 1; i <= n; ++i) {   //尝试所有点
        //与当前点相邻并且未遍历过
        if(e[cur][i] == 1 && book[i] == 0) {
            book[i] = 1;
            dfs(i);
        }
    }
    return;
}
