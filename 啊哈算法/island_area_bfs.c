/**
 * 使用广度优先搜索解决求岛面积问题
 * gcc -o exe\island_area_bfs.exe island_area_bfs.c
 *case:
10 10 6 8
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
 *result:
38
 */
 #include <stdio.h>
 struct node {
     int x;
     int y;
 };

 int main() {
     struct node que[2501];  //地图大小不超过50*50
     int a[51][51] = {0};
     int book[51][51] = {0};
     int next[4][2] = {
     {0, 1},
     {1, 0},
     {0, -1},
     {-1, 0}
     };
     int head, tail;
     int i, j, k, n, m, startx, starty, tx, ty, sum;
     //地图的行数，列数及着陆点
     scanf("%d %d %d %d", &n, &m, &startx, &starty);
     //输入地图的详细
     for(i = 1; i <= n; ++i)
         for(j = 1; j <= m; ++j)
             scanf("%d", &a[i][j]);

     //初始化着陆点
     head = tail = 1;
     que[tail].x = startx;
     que[tail].y = starty;
     ++tail;
     book[startx][starty] = 1;
     sum = 1;
     while(head < tail) {
         //枚举四个方向
         for(k = 0; k < 4; ++k) {
             tx = que[head].x + next[k][0];
             ty = que[head].y + next[k][1];
             //是否越界
             if(tx < 1 || tx > n || ty < 1 || ty > m)
                 continue;
              //没走过及是陆地
             if(a[tx][ty] > 0 && book[tx][ty] == 0) {
                 ++sum;
                 book[tx][ty] = 1;
                 que[tail].x = tx;
                 que[tail].y = ty;
                 tail++;
             }
         }
         ++head;
     }
     printf("%d\n", sum);
     return 0;
 }
