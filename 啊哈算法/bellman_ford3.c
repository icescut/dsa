/**
 * 使用Bellman-Ford算法求最短路程，使用队列优化
 * gcc -o exe\bellman_ford3.exe bellman_ford3.c
 *case:
5 7
1 2 2
1 5 10
2 3 3
2 5 7
3 4 4
4 5 5
5 3 6
 *result:
0 2 5 9 9
 */
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int dis[6] = {0}, book[6] = {0}, i, k, n, m, u[8], v[8], w[8];
    int first[6], next[8];
    int que[101] = {0}, head = 1, tail = 1;
    int inf = 99999999;
    //读入顶点数和边数
    scanf("%d %d", &n, &m);

    //初始化dis/first数组
    for(i = 1; i <= n; ++i) {
        dis[i] = inf;
        first[i] = -1;
    }
    dis[1] = 0;

    //读入边
    for(i = 1; i <= m; ++i) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        //建立邻接表
        next[i] = first[u[i]];
        first[u[i]] = i;
    }

    //1号顶点入队
    que[tail++] = 1;
    book[1] = 1;

    while(head < tail) {
        k = first[que[head]];   //当前要处理的顶点对应的边
        while(k != -1) {    //处理当前顶点的所有边
            if(dis[v[k]] > dis[u[k]] + w[k]) {
                dis[v[k]] = dis[u[k]] + w[k];
                if(book[v[k]] == 0) {
                    que[tail++] = v[k];
                    book[v[k]] = 1;
                }
            }
            k = next[k];
        }
        //出队
        book[que[head]] = 0;
        head++;
    }

    //输出结果
    for(i = 1; i <= n; ++i) {
        printf("%d ", dis[i]);
    }
    return 0;
}
