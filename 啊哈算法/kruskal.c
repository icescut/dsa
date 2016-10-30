/**
 * 最小生成树
 * gcc -o exe\kruskal.exe kruskal.c
 *case:
6 9
2 4 11
3 5 13
4 6 3
5 6 4
2 3 6
4 5 7
1 2 1
3 4 9
1 3 2
 *result:
19
 */
#include <stdio.h>

//边的关系：开始点，结束点，权重
struct edge {
    int u;
    int v;
    int w;
};

struct edge e[10];
int n, m;
int f[7] = {0}, sum = 0, count = 0;

void quicksort(int left, int right) {
    int i, j;
    struct edge t;
    if(left > right) {
        return;
    }
    i = left;
    j = right;
    while(i != j) {
        while(e[j].w >= e[left].w && i < j) {
            --j;
        }
        while(e[i].w <= e[left].w && i < j) {
            ++i;
        }
        if(i < j) {
            t = e[i];
            e[i] = e[j];
            e[j] = t;
        }
    }
    t = e[left];
    e[left] = e[i];
    e[i] = t;

    quicksort(left, i - 1);
    quicksort(i + 1, right);
    return;
}

//找最高领导者
int getf(int v) {
    //如果自己领导自己，返回
    if(f[v] == v) {
        return v;
    } else {
        //找自己的领导
        f[v] = getf(f[v]);
        return f[v];
    }
}

//合并两个团伙，设置为同一个最高领导
int merge(int v, int u) {
    int t1, t2;
    t1 = getf(v);
    t2 = getf(u);
    if(t1 != t2) {
        f[t2] = t1;
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    int i;

    scanf("%d %d", &n, &m);

    for(i = 1; i <= m; ++i) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }
    quicksort(1, m);
    for(i = 1; i <= n; ++i) {
        f[i] = i;
    }

    //Kruskal算法核心
    for(i = 1; i <= m; ++i) {
        if(merge(e[i].u, e[i].v)) {   //如果尚未连通，选用这条边
            count++;
            sum += e[i].w;
        }
        if(count == n - 1) {
            break;
        }
    }

    printf("%d", sum);
    return 0;
}
