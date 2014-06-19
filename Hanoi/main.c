/*
    汉诺塔：汉诺塔（又称河内塔）问题是源于印度一个古老传说的益智玩具。
    大梵天创造世界的时候做了三根金刚石柱子，
    在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。
    大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。
    并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘。


    核心步骤：
    1.先将63个盘子从X移动到Y上
    2.再将第64个从X移动到Z上
    3.将Y上的63个盘子移动到Z上

    上面的步骤及其重要！！！！！！！！！！！
*/

#include <stdio.h>
#include <stdlib.h>

int count = 1;

//迭代实现汉诺塔的移动
void hanoi( int n, char x, char y, char z)
{
    if( 1 == n )
    {
        printf("step NO.%d move %c to %c \n", count++, x, z);
    }
    else
    {
        hanoi( n-1, x, z, y );
        printf("step NO.%d move %c to %c \n", count++, x, z);
        hanoi( n-1, y, x, z );
    }
}

int main()
{
    int n;
    char a = 'X', b = 'Y', c = 'Z';

    printf("请输入汉诺塔的层数：");
    scanf("%d", &n);

    hanoi( n, a, b, c );

    return 0;
}
