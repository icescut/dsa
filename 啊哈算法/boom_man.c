/**
 * 使用枚举解决炸弹人游戏只最佳的炸弹放置点
 * gcc -o exe\boom_man.exe boom_man.c
 *case:
13 13
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.###
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
 */
#include <stdio.h>

#define ASIZE 20

int main(int argc, char const *argv[]) {
    char a[ASIZE][ASIZE+1];   //地图的行列不超过20
    int i, j, sum, max = 0, q, p, x, y, n, m;
    scanf("%d %d", &n, &m); //有多少行和列

    //读入n行字符
    for(i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }

    //枚举地图中每一个点
    for(i = 0; i < n; ++i) {
        for(j = 0; j < m; ++j) {
            //是否平地
            if(a[i][j] == '.') {
                sum = 0;    //计数可以消灭的敌人
                //使用x,y从四个方向统计可以消灭的敌人
                //向上统计
                x = i;
                y = j;
                while(a[x][y] != '#') {
                    if(a[x][y] == 'G')
                        ++sum;
                    --x;
                }
                //向下统计
                x = i;
                y = j;
                while(a[x][y] != '#') {
                    if(a[x][y] == 'G')
                        ++sum;
                    ++x;
                }
                //向左统计
                x = i;
                y = j;
                while(a[x][y] != '#') {
                    if(a[x][y] == 'G')
                        ++sum;
                    --y;
                }
                //向右统计
                x = i;
                y = j;
                while(a[x][y] != '#') {
                    if(a[x][y] == 'G')
                        ++sum;
                    ++y;
                }

                //更新最大值
                if(sum > max) {
                    max = sum;
                    p = i;
                    q = j;
                }
            }
        }
    }

    printf("Put the boom in (%d, %d), kill %d enemies\n", p, q, max);
    return 0;
}
