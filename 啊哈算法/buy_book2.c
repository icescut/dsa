/**
 * 冒泡排序
 * gcc -o exe\buy_book2.exe buy_book2.c swap.c
 * case:
 *10
 *20 40 32 67 40 20 89 300 400 15
 * result :
 *15 20 32 40 67 89 300 400
 */
#include <stdio.h>

void swap(int[], int, int);

#define ASIZE 100

int main(int argc, char const *argv[]) {
    int a[ASIZE] = {0}, i, j, t, n;

    scanf("%d", &n);    //输入一个数n，表示接下来有n个数输入

    //循环读入n个数
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    //进行n-1趟
    for (i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {//从第一位到最后一个尚未归位的数。
            if(a[j] > a[j + 1]) {
                swap(a, j, j + 1);
            }
        }
    }
    printf("%d ", a[0]);
    for(i = 1; i < n; ++i) {
        if(a[i] != a[i - 1]) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}
