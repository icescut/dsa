/**
 * 使用广度优先搜索解决炸弹人问题
 * gcc -o exe\boom_man_bfs.exe boom_man_bfs.c
 *case:
13 13 3 3
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
 * result:
Put the boom in (7, 11), kill 10 enemies
 */
#include <stdio.h>

char a[20][21];
struct note {
    int x;
    int y;
};

int getnum(int, int);

int main(int argc, char const *argv[]) {
    struct note que[401];   //假设地图不超过20*20
    int head, tail;
    int book[20][20] = {0};
    int i, j, k, sum, max = 0, mx, my, n, m, startx, starty, tx, ty;
    int next[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
    };
    //读入有多少行、列，开始位置
    scanf("%d %d %d %d", &n, &m, &startx, &starty);

    //读入n行字符
    for(i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }

    //队列初始化
    head = tail = 1;
    //插入起始位置
    que[tail].x = startx;
    que[tail].y = starty;
    ++tail;
    book[startx][starty] = 1;
    max = getnum(startx, starty);
    mx = startx;
    my = starty;
    //当队列不为空
    while(head < tail) {
        //尝试四个方向
        for(k = 0; k < 4; ++k) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];

            //是否越界
            if(tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1) {
                continue;
            }

            //是否为平地及未走过
            if(a[tx][ty] == '.' && book[tx][ty] == 0) {
                //标记为已走过，这样每个点只能入队一次
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                ++tail;

                sum = getnum(tx, ty);
                if(sum > max) {
                    max = sum;
                    mx = tx;
                    my = ty;
                }
            }
        }
        ++head;
    }
    printf("Put the boom in (%d, %d), kill %d enemies\n", mx, my, max);
    return 0;
}

/**
 * 放置在一个点可以消灭多少个敌人
 */
int getnum(int i, int j) {
    int sum = 0, x, y;
    //向上统计可以消灭的敌人
    x = i;
    y = j;
    //当不是墙时继续
    while (a[x][y] != '#') {
        if(a[x][y] == 'G')
            ++sum;
        --x;
    }
    //向下统计可以消灭的敌人
    x = i;
    y = j;
    //当不是墙时继续
    while (a[x][y] != '#') {
        if(a[x][y] == 'G')
            ++sum;
        ++x;
    }
    //向左统计可以消灭的敌人
    x = i;
    y = j;
    //当不是墙时继续
    while (a[x][y] != '#') {
        if(a[x][y] == 'G')
            ++sum;
        --y;
    }
    //向右统计可以消灭的敌人
    x = i;
    y = j;
    //当不是墙时继续
    while (a[x][y] != '#') {
        if(a[x][y] == 'G')
            ++sum;
        ++y;
    }
    return sum;
}
