/**
 * 使用深度优先搜索解决炸弹人问题
 * gcc -o exe\boom_man_dfs.exe boom_man_dfs.c
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
int book[20][20], max, mx, my, n, m;
int getnum(int i, int j);
void dfs(int x, int y);

int main(int argc, char const *argv[]) {
    int i, startx, starty;
    //读入有多少行、列，开始位置
    scanf("%d %d %d %d", &n, &m, &startx, &starty);
    //读入n行字符
    for(i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    book[startx][starty] = 1;
    max = getnum(startx, starty);
    mx = startx;
    my = starty;
    dfs(startx, starty);

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

//尝试从一个点可以走多少种可能，并进入下一步尝试
void dfs(int x, int y) {
    //方向
    int next[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
    };
    int k, sum, tx, ty;
    sum = getnum(x, y);

    if(max < sum) {
        max = sum;
        mx = x;
        my = y;
    }
    //尝试四个方向
    for(k = 0; k < 4; ++k) {
        tx = x + next[k][0];
        ty = y + next[k][1];

        //是否越界，这里应该就是结束条件了
        if(tx < 0 || tx > n -1 || ty < 0 || ty > m - 1)
            continue;
        //是否空地及没有走过
        if(a[tx][ty] == '.' && book[tx][ty] == 0) {
            book[tx][ty] = 1;
            dfs(tx, ty);
            //不需要恢复状态，走过的点就走过了，不需要重复走
        }
    }
    return;
}
