/**
 * 使用广度优先求解最少转机次数
 * gcc -o exe\airline_bfs.exe airline_bfs.c
 * case:
5 7 1 5
1 2
1 3
2 3
2 4
3 4
3 5
4 5
 * result:
2
 */
#include <stdio.h>
struct node {
    int x;  //城市
    int s; //转机次数
};

int main() {
    struct node que[2501];
    int e[51][51] = {0};
    int book[51] = {0};
    int head, tail;
    int i, j, k, n, m, a, b, start, end, flag = 0, cur;
    scanf("%d %d %d %d", &n, &m, &start, &end);
    //初始化邻接矩阵
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
            if(i == j)
                e[i][j] = 0;
            else
                e[i][j] = 99999999;
    //读入城市间的航班
    for(i = 1; i <= m; ++i) {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }

    head = tail = 1;
    que[tail].x = start;    //起点城市
    que[tail].s = 0;        //转机次数为0
    ++tail;
    book[start] = 1;
    while(head < tail) {
        cur = que[head].x;
        for(i = 1; i <= n; ++i) {
            //有航班到并且该城市未到过
            if(e[cur][i] != 99999999 && book[i] == 0) {
                que[tail].x = i;
                que[tail].s = que[head].s + 1;
                ++tail;
                book[i] = 1;
            }
            if(que[tail - 1].x == end) {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
        ++head;
    }
    printf("%d", que[tail - 1].s);
    return 0;
}
