/**
 * 冒泡排序
 * gcc -o exe\bubble.exe bubble.c swap.c print.c
 * case:
 *10
 *8 100 50 22 15 6 1 1000 999 0
 * result:
 *0 1 6 8 15 22 50 100 999 1000
 */
#include <stdio.h>

void swap(int[], int, int);
void print(int[], int);

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
    print(a, n);
    return 0;
}
