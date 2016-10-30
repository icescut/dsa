/**
 * 快速排序
 * gcc -o exe\quick.exe quick.c swap.c print.c
 *case:
 *10
 *6 1 2 7 9 3 4 5 10 8
 *result:
 *1 2 3 4 5 6 7 8 9 10
 */
#include <stdio.h>
#define ASIZE 101
int a[101], n;
void swap(int[], int, int);
void print(int[], int);
void quicksort(int left, int right);

int main(int argc, char const *argv[]) {
    int i, j, t;
    scanf("%d", &n);
    for(i = 0;i < n; ++i) {
        scanf("%d",&a[i]);
    }
    quicksort(0, n - 1);

    print(a, n);
    return 0;
}

void quicksort(int left, int right) {
    int i, j, t, temp;
    if(left > right)
        return;

    temp = a[left]; //temp作为划分大小的基准
    i = left;
    j = right;
    while(i != j) {
        //从右往左找小于基准的数
        while(a[j] > temp && i < j)
            --j;
        //从左往右找大于或等于基准的数
        while(a[i] <= temp && i < j)
            ++i;
        //交换两边找到的数
        if(i < j) {
            swap(a, i, j);
        }
    }
    //基准归位
    a[left] = a[i];
    a[i] = temp;

    quicksort(left, i - 1);
    quicksort(i + 1, right);
}
