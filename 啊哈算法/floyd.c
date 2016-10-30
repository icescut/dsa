/**
 * 使用floyd算法求任意点间最短距离
 * gcc -o exe\floyd.exe floyd.c
 *case:
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
 *result:
 0         2         5         4
 9         0         3         4
 6         8         0         1
 5         7        10         0
 */
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int e[10][10], k, i, j, m, n, t1, t2, t3;
    int inf = 999999999;
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

    //依次增加顶点
    for(k = 1; k <= n; ++k) {
        //遍历所有边
        for(i = 1; i <= n; ++i) {
            for(j = 1; j <= n; ++j) {
                if(e[i][k] < inf && e[k][j] < inf && e[i][j] > e[i][k] + e[k][j])
                    e[i][j] = e[i][k] + e[k][j];
            }
        }
    }

    //输出结果
    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= n; ++j) {
            printf("%10d", e[i][j]);
        }
        printf("\n");
    }
    return 0;
}
