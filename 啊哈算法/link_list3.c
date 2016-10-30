/**
 *使用数组而不是结构来实现链表
 * gcc -o exe\link_list3.exe link_list3.c
 * case:
 *9
 *2 3 5 8 9 10 18 26 32
 *6
 * result:
 *2 3 5 6 8 9 10 18 26 32
 */
#include <stdio.h>

#define ASIZE 101

int main(int argc, char const *argv[]) {
    int data[ASIZE], right[ASIZE];
    int i, n, t, len;

    //读入的数的个数
    scanf("%d", &n);

    for(i = 1; i <= n; ++i) {
        scanf("%d", &data[i]);
    }
    len = n;
    for(i = 1; i <= n; ++i) {
        if(i != n)
            right[i] = i + 1;
        else
            right[i] = 0;   //0代表到达末尾
    }
    //插入一个数
    len++;
    scanf("%d", &data[len]);
    t = 1;
    while(t != 0) {
        if(data[right[t]] > data[len]) {
            right[len] = right[t];
            right[t] = len;
            break;
        }

        t = right[t];
    }

    //输出链表
    t = 1;
    while(t != 0) {
        printf("%d ", data[t]);
        t = right[t];
    }
    return 0;
}
