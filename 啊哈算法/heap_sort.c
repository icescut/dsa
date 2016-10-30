/**
 * 堆排序，通过建立堆，删除元素后调整堆
 * gcc -o exe\heap_sort.exe heap_sort.c
 *case:
14
99 5 36 7 22 17 46 12 2 19 25 28 1 92
 *result:
1 2 5 7 12 17 19 22 25 28 36 46 92 99
 */
#include <stdio.h>
int h[101]; //用于存放堆
int n;  //堆的大小

void swap(int a, int b) {
    int t;
    t = h[a];
    h[a] = h[b];
    h[b] = t;
}

/**
 * 从i开始调整堆，使之成为最小堆
 */
void shiftdown(int i) {
    int t, flag = 0;
    //至少有左子树
    while(i * 2 <= n && flag == 0) {
        //与左儿子比较，谁小
        if(h[i] > h[i * 2]) {
            t = i * 2;
        } else {
            t = i;
        }
        //与右儿子比较，谁小
        if(i * 2 + 1 <= n && h[t] > h[i * 2 + 1]) {
            t = i * 2 + 1;
        }
        //需要调整
        if(t != i) {
            swap(t, i);
            i = t;
        } else {
            flag = 1;
        }
    }
}

//建堆
void create() {
    int i;
    for(i = n/2; i >= 1; --i) {
        shiftdown(i);
    }
}

//删除最小元素
int deletemin() {
    int t;
    t = h[1];
    h[1] = h[n--];
    shiftdown(1);
    return t;
}

int main(int argc, char const *argv[]) {
    int i, num;
    //待排序的元素的个数
    scanf("%d", &num);

    for(i = 1; i <= num; ++i) {
        scanf("%d", &h[i]);
    }
    n = num;

    create();

    for(i = 1; i <= num; ++i) {
        printf("%d ", deletemin());
    }
    return 0;
}
