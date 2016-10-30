/**
 * 使用队列实现猜QQ号码
 * gcc -o exe\queue.exe queue.c
 * result:6 1 5 9 4 7 2 8 3
 */

#include <stdio.h>

#define ASIZE 102

int main(int argc, char const *argv[]) {
    int q[ASIZE] = {0, 6, 3, 1, 7, 5, 8, 9, 2, 4}, head, tail, i;

    head = 1;
    tail = 10;  //遵守C规则，左闭右开
    while(head < tail) {
        //打印队首，并出队
        printf("%d ", q[head]);
        ++head;

        //将新队首添加到队尾，然后队首出队
        q[tail++] = q[head++];
    }
    return 0;
}
