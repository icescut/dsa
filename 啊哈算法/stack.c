/**
 * 使用栈判断字符串是否回文
 * gcc -o exe\stack.exe stack.c
 * case:ahaha
 * result:YES
 */

#include <stdio.h>
#include <string.h>

#define ASIZE 101

int main(int argc, char const *argv[]) {
    char a[ASIZE], s[ASIZE];
    int i, len, mid, next, top;

    gets(a);    //读入一行字符串
    len = strlen(a);
    mid = len / 2 - 1;

    top = 0;    //初始化栈顶位置
    //将mid前的字符依次入栈
    for(i = 0; i <= mid; ++i) {
        s[++top] = a[i];
    }

    //计算后半段开始匹配的下标。
    if(len % 2 == 0) {
        next = mid + 1;
    } else {
        next = mid + 2;
    }
    for(i = next; i <= len - 1; ++i) {
        if(a[i] != s[top])
            break;
        --top;
    }

    if(top == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
