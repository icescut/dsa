/**
 * 求图的割边
 * gcc -o exe\gebian.exe gebian.c
 *case:
6 6
1 4
1 3
4 2
3 2
2 5
5 6
 *result:
5-6
2-5
 */
#include <stdio.h>

#define min(a, b) ((a < b) ? (a) : (b))

int n, m, e[9][9], root;
int num[9], low[9], flag[9], idx;

void dfs(int cur, int father) {
    int i, j;
    ++idx;
    num[cur] = idx;
    low[cur] = idx;
    for(i = 1; i <= n; ++i) {
        if(e[cur][i] == 1) {
            if(num[i] == 0) {
                dfs(i, cur);
                low[cur] = min(low[cur], low[i]);
                if(low[i] > num[cur]) {
                    printf("%d-%d\n", cur, i);
                }
            } else if(father != i){
                low[cur] = min(low[cur], num[i]);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int i, j, x, y;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= n; ++j) {
            e[i][j] = 0;
        }
    }

    for(i = 1; i <= m; ++i) {
        scanf("%d %d", &x, &y);
        e[x][y] = 1;
        e[y][x] = 1;
    }

    root = 1;
    dfs(1, root);

    return 0;
}
