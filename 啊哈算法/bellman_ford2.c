/**
 * 使用Bellman-Ford算法求最短路程，通过检测无法松驰以提前跳出循环
 * gcc -o exe\bellman_ford2.exe bellman_ford2.c
 *case:
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
 *result:
0 -3 -1 2 4
 */
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int dis[10],bak[10], i, k, n, m, u[10], v[10], w[10], check, flag;
    int inf = 99999999;
    //读入顶点数和边数
    scanf("%d %d", &n, &m);
    //读入边
    for(i = 1; i <= m; ++i) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    //初始化dis数组
    for(i = 1; i <= n; ++i) {
        dis[i] = inf;
    }
    dis[1] = 0;

    //Bellman-Ford算法核心
    for(k = 1; k <= n-1; ++k) {
        //备份至bak
        for(i = 1; i <= n; ++i) {
            bak[i] = dis[i];
        }
        for(i = 1; i <= m; ++i) {
            if(dis[v[i]] > dis[u[i]] + w[i]) {
                dis[v[i]] = dis[u[i]] + w[i];
            }
        }
        check = 0;
        for(i = 1; i <= n; ++i) {
            if(bak[i] != dis[i]) {
                check = 1;
                break;
            }
        }
        if(check == 0)
            break;
    }
    //检测负权回路
    flag = 0;
    for(i = 1; i <= m; ++i) {
        if(dis[v[i]] > dis[u[i]] + w[i]) {
            flag = 1;
        }
    }
    //输出结果
    if(flag == 1) {
        printf("有负权回路\n");
    } else {
        for(i = 1; i <= n; ++i) {
            printf("%d ", dis[i]);
        }
    }
    return 0;
}
