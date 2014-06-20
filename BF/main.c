/*
    BF算法

    事实上，BF算法并不是“BoyFriend”算法的意思，他有一个很黄很暴力的原名：Brute Force

    BF算法属于朴素的模式匹配算法，它的核心思想是：

    有两个字符串S和T，长度为N和M。首先S[1]和T[1]比较，
    若相等，则再比较S[2]和T[2]，一直到T[M]为止；
    若S[1]和T[1]不等，则T向右移动一个字符的位置，再依次进行比较。

    该算法最坏情况下要进行M*(N-M+1)次比较，时间复杂度为O(M*N)。
    在这里S是主串，T是子串，这种子串的定位操作通常称作串的模式匹配。

    我用顺序存储结构实现BF算法。
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE     20

typedef struct
{
    char data[MAXSIZE];
    int lenght;
}myString;

void initString( myString **str )
{
    (*str) = (myString *)malloc(sizeof(myString));

    if( !(*str) )
    {
        printf("出错，请重试。");
        exit(0);
    }

    (*str)->lenght = 0;
}

int compareString( myString fat, myString son )
{
    int i,j,k;

    for( i=0; i<fat.lenght; i++)
    {
        for( j=0,k=i; ; j++,k++ )
        {
            if( fat.data[k] != son.data[j] )
                break;
            if( j == son.lenght-1 )
                return 1;
        }
    }
    return 0;
}

int main()
{
    myString *fat, *son;
    char in;
    int result = 0;

    initString( &fat );
    initString( &son );

    printf("请输入父串(以#号结束)：");

    scanf("%c", &in);
    while( '#'!=in && fat->lenght < MAXSIZE)
    {
        fat->data[fat->lenght++] = in;
        scanf("%c", &in);
    }

    printf("请输入子串(以#号结束)：");

    scanf("%c", &in);
    scanf("%c", &in);
    while( '#'!=in && son->lenght < MAXSIZE )
    {
        son->data[son->lenght++] = in;
        scanf("%c", &in);
    }

    result = compareString( *fat, *son );

    if( result )
        printf("父串包含子串。");
    else
        printf("不包含。");


    return 0;
}
