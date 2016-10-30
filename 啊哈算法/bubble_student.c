/**
 * 冒泡排序(结构)
 * gcc -o exe\bubble_student.exe bubble_student.c
 * case:
 *5
 *huhu 5
 *haha 3
 *xixi 5
 *hengheng 2
 *gaoshu 8
 * result:
 *hengheng
 *haha
 *huhu
 *xixi
 *gaoshu
 */
#include <stdio.h>

struct student {
    char name[21];
    char score;
};
void swap(int[], int, int);

#define ASIZE 100

int main(int argc, char const *argv[]) {
    struct student a[ASIZE], t;
    int i, j, n;

    scanf("%d", &n);    //输入一个数n，表示接下来有n个数输入

    //循环读入n个数
    for (i = 0; i < n; i++) {
        scanf("%s %d", a[i].name, &a[i].score);
    }

    //进行n-1趟
    for (i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {//从第一位到最后一个尚未归位的数。
            if(a[j].score > a[j + 1].score) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for(i = 0; i < n; ++i) {
        printf("%s\n", a[i].name);
    }
    return 0;
}
