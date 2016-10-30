/**
 * 使用广度优先搜索遍历图
 * gcc -o exe\traverse_graph_dfs.exe traverse_graph_dfs.c
 * case:
5 5
1 2
1 3
1 5
2 4
3 5
 * result:
1 2 3 5 4
 */
#include <stdio.h>
#define ASIZE 101

int main() {
    int que[10001];
    //邻接矩阵
    int e[ASIZE][ASIZE] = {0};
    int book[ASIZE] = {0};
    int head, tail;
    int i, j, n, m, a, b, cur;
    //邻接矩阵的行数和读入的边
    scanf("%d %d", &n, &m);
    //初始化邻接矩阵
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
            if(i == j)
                e[i][j] = 0;
            else
                e[i][j] = 99999999;
    //读入边
    for(i = 1; i <= m; ++i) {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }

    head = tail = 1;
    que[tail++] = 1;
    book[1] = 1;
    while(head < tail) {
        cur = que[head];
        for(i = 1; i <= n; ++i) {
            if(e[cur][i] == 1 && book[i] == 0) {
                que[tail++] = i;
                book[i] = 1;
            }
            if(tail > n)
                break;
        }
        ++head;
    }
    for(i = 1; i < tail; ++i) {
        printf("%d ", que[i]);
    }
    return 0;
}
