/**
 * 并查集，判断有多少个团伙
 * gcc -o exe\bcj.exe bcj.c
 *case:
10 9
1 2
3 4
5 2
4 6
2 6
8 7
9 7
1 6
2 4
 *result:
3
 */
#include <stdio.h>

int f[1000] = {0}, n, m, k, sum = 0;

void init() {
    int i;
    for(i = 1; i <= n; ++i) {
        f[i] = i;
    }
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
void merge(int v, int u) {
    int t1, t2;
    t1 = getf(v);
    t2 = getf(u);
    if(t1 != t2) {
        f[t2] = t1;
    }
}

int main(int argc, char const *argv[]) {
    int i, x, y;
    scanf("%d %d", &n, &m);

    init();
    for(i = 1; i <= m; ++i) {
        scanf("%d %d", &x, &y);
        merge(x, y);
    }
    for(i = 1; i <= n; ++i) {
        if(f[i] == i)
            sum++;
    }
    printf("%d", sum);
    return 0;
}
