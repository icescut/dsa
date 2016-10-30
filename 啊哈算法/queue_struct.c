/**
 * 使用队列(结构方式)实现猜QQ号码
 * gcc -o exe\queue_struct.exe queue_struct.c
 * case:6 3 1 7 5 8 9 2 4
 * result:6 1 5 9 4 7 2 8 3
 */

#include <stdio.h>
#define ASIZE 100

struct queue {
    int data[ASIZE];
    int head;
    int tail;
};

int main(int argc, char const *argv[]) {
    struct queue q;
    int i;

    q.head = 1;
    q.tail = 1;  //遵守C规则，左闭右开
    //插入9个数
    for(i = 0; i < 9; ++i) {
        scanf("%d", &q.data[q.tail++]);
    }
    while(q.head < q.tail) {
        //打印队首，并出队
        printf("%d ", q.data[q.head++]);

        //将新队首添加到队尾，然后队首出队
        q.data[q.tail++] = q.data[q.head++];
    }
    return 0;
}
