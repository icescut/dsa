/**
 * 实现链表，并在中间插入一个数
 * gcc -o exe\link_list2.exe link_list2.c
 * case:
 *9
 *2 3 5 8 9 10 18 26 32
 *6
 * result:
 *2 3 5 6 8 9 10 18 26 32
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main(int argc, char const *argv[]) {
    //q指示当前位置
    struct node *head, *p, *q, *t;
    int i, n, a;

    scanf("%d", &n);
    head = NULL;
    for(i = 0; i < n; ++i) {
        scanf("%d", &a);

        p = (struct node *)malloc(sizeof(struct node));
        p->data = a;
        p->next = NULL;

        if(head == NULL) {
            head = p;
        } else {
            q->next = p;
        }
        q = p;
    }

    //插入一个数
    scanf("%d", &a);
    t = head;
    while(t != NULL) {
        if(t->next->data > a) {
            p = (struct node *)malloc(sizeof(struct node));
            p->data = a;
            p->next = t->next;
            t->next = p;
            break;
        }
        t = t->next;
    }

    //输出插入后的链表
    t = head;
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    return 0;
}
