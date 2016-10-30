/**
 * 使用Dijkstra算法求一个顶点到其他任一顶点的最短距离
 * gcc -o exe\dijkstra.exe dijkstra.c
 *case:
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
 */
#include <stdio.h>
int main(int argc, char const *argv[]) {
    //邻接矩阵
    int e[10][10];
    //保存结果
    int dis[10];
    //该点是否有确定值了
    int book[10] = {0};
    int i, j, n, m, t1, t2, t3, u, v, min;
    int inf = 99999999;

    //顶点数、边数
    scanf("%d %d", &n, &m);

    //初始化
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
            if(i == j)
                e[i][j] = 0;
            else
                e[i][j] = inf;
    //读入边
    for(i = 1; i <= m; ++i) {
        scanf("%d %d %d", &t1, &t2, &t3);
        e[t1][t2] = t3;
    }

    //初始化dis数组，1到各点的距离是原始路程
    for(i = 1; i <= n; ++i) {
        dis[i] = e[1][i];
    }
    book[1] = 1;
    //Dijkstra算法核心
    for(i = 1; i <= n; ++i) {
        //找出离1号点最近的点
        min = inf;
        for(j = 1; j <= n; ++j) {
            if(book[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        book[u] = 1;
        //看下经过u点可否使路变短
        for(v = 1; v <= n; ++v) {
            if(e[u][v] < inf) {
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                }
            }
        }
    }
    //输出结果
    for(i = 1; i <= n; ++i) {
        printf("%d ", dis[i]);
    }
    return 0;
}
