/**
 * 桶排序
 * gcc -o exe\bucket.exe bucket.c
 * case : 5 3 5 2 8
 * result : 2 3 5 5 8
 */
#include <stdio.h>

#define ASIZE 11

int main(int argc, char const *argv[]) {
    //下标代表输入的数值，数组元素表示数值的个数
    int a[ASIZE] = {0}, i, j, t;

    //循环读入五个数
    for (i = 0; i < 5; i++) {
        scanf("%d", &t);
        a[t]++;
    }
    for (i = 0; i < ASIZE; i++) {
        for(j = 1; j <= a[i]; ++j) {
            printf("%d ", i);
        }
    }
    return 0;
}
