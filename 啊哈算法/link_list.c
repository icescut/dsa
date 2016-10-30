/**
 * 实现链表
 * gcc -o exe\link_list.exe link_list.c
 * case:
 *9
 *2 3 5 8 9 10 18 26 32
 * result:
 *2 3 5 8 9 10 18 26 32
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
    t = head;
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    return 0;
}
