/**
 * 使用火柴棍摆出等式a+b=c，给定火柴棍的个数，能摆出多少种等式
 * gcc -o exe\matchstick.exe matchstick.c
 *case:
18
 *result:
 0+4=4
 0+11=11
 1+10=11
 2+2=4
 2+7=9
 4+0=4
 7+2=9
 10+1=11
 11+0=11
 totally 9 solutions
 */
#include <stdio.h>

int fun(int);

int main(int argc, char const *argv[]) {
    int a, b, c, m, i, sum = 0;
    scanf("%d", &m);    //火柴棍的个数

    //枚举a和b
    for(a = 0; a <= 1111; ++a) {
        for(b = 0; b <= 1111; ++b) {
            c = a + b;
            if(fun(a) + fun(b) + fun(c) == m - 4) {
                printf("%d+%d=%d\n", a, b, c);
                ++sum;
            }
        }
    }

    printf("totally %d solutions\n", sum);
    return 0;
}
/**
 * 摆x需要多少根火柴
 */
int fun(int x) {
    int num = 0;
    int f[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; //0~9需要多少根火柴来摆

    while(x / 10 != 0) {  //判断是否不止一位
        num += f[x % 10];   //得到最低位
        x /= 10;    //去掉最低位
    }
    num += f[x]; //得到最低位
    return num;
}
