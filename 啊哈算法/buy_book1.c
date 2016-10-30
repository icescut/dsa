/**
 * 去重及排序ISBN号（桶排序）
 * gcc -o exe\buy_book1.exe buy_book1.c
 * case :
 *10
 *20 40 32 67 40 20 89 300 400 15
 * result :
 *15 20 32 40 67 89 300 400
 */
#include <stdio.h>

#define ASIZE 1001

int main(int argc, char const *argv[]) {
    //下标代表输入的数值，数组元素表示数值的个数
    int a[ASIZE] = {0}, i, j, t, n;

    scanf("%d", &n);    //接下来输入的个数
    //循环读入
    for (i = 0; i < n; i++) {
        scanf("%d", &t);
        a[t] = 1;   //重复的也只是记为1
    }
    for (i = 0; i < ASIZE; i++) {
        for(j = 1; j <= a[i]; ++j) {
            printf("%d ", i);
        }
    }
    return 0;
}
