/**
 * 小猫钓鱼纸牌游戏
 * gcc -o exe\cat_fish.exe cat_fish.c
 * case:
 *2 4 1 2 5 6
 *3 1 3 5 6 4
 * result:YES
 */

#include <stdio.h>
#define QSIZE 1000
#define SSIZE 10
//保存手上的牌
struct queue{
    int data[QSIZE];
    int head;
    int tail;
};

//保存桌上的牌
struct stack {
    int data[SSIZE];
    int top;
};

int main(int argc, char const *argv[]) {
    //1~tail-1
    struct queue q1, q2;
    //1~top
    struct stack s;
    int book[SSIZE] = {0}, i, t;

    q1.head = 1;
    q1.tail = 1;
    q2.head = 1;
    q2.tail = 1;
    s.top = 0;

    //往q1手上插入6张牌
    for(i = 0; i < 6; ++i) {
        scanf("%d", &q1.data[q1.tail++]);
    }
    //往q2手上插入6张牌
    for(i = 0; i < 6; ++i) {
        scanf("%d", &q2.data[q2.tail++]);
    }

    //两人手上的牌都不为空时
    while(q1.head < q1.tail && q2.head < q2.tail) {
        t = q1.data[q1.head];   //q1出一张牌
        if(book[t] == 0) {  //桌子上没有相同的牌
            q1.head++;  //打出
            s.top++;
            s.data[s.top] = t;  //放到桌上
            book[t] = 1;    //标记桌上有这张牌
        } else {    //桌上有这张牌，收牌
            q1.head++;
            q1.data[q1.tail++] = t;
            while(s.data[s.top] != t) {
                book[s.data[s.top]] = 0;    //取消标记
                q1.data[q1.tail++] = s.data[s.top--];   //收牌
            }
        }

        t = q2.data[q2.head];   //q2出一张牌
        if(book[t] == 0) {  //桌子上没有相同的牌
            q2.head++;  //打出
            s.top++;
            s.data[s.top] = t;  //放到桌上
            book[t] = 1;    //标记桌上有这张牌
        } else {    //桌上有这张牌，收牌
            q2.head++;
            q2.data[q2.tail++] = t;
            while(s.data[s.top] != t) {
                book[s.data[s.top]] = 0;    //取消标记
                q2.data[q2.tail++] = s.data[s.top--];   //收牌
            }
        }
    }
    if(q2.head == q2.tail) {
        printf("q1 win\n");
        //输出手上的牌
        printf("The cards in q1 is:");
        for(i = q1.head; i < q1.tail; ++i) {
            printf(" %d", q1.data[i]);
        }
        if(s.top != 0) {
            printf("\nThe cards in table:");
            for(i = 1; i <= s.top; ++i) {
                printf(" %d", s.data[i]);
            }
        } else {
            printf("\nNO cards in table");
        }
    } else {
        printf("q2 win\n");
        //输出手上的牌
        printf("The cards in q1 is:");
        for(i = q2.head; i < q2.tail; ++i) {
            printf(" %d", q2.data[i]);
        }
        if(s.top != 0) {
            printf("\nThe cards in table:");
            for(i = 1; i <= s.top; ++i) {
                printf(" %d", s.data[i]);
            }
        } else {
            printf("\nNO cards in table");
        }
    }

    return 0;
}
