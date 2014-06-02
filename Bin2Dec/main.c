/*
    二进制转化十进制。
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10

typedef char ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

void initStack( sqStack *s )
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));

    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void push( sqStack *s, ElemType e )
{
    if( s->top - s->base >= s->stackSize )
    {
        s->base = (ElemType *)realloc( s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType) );
        if( !s->base )
        {
            exit(0);
        }
    }

    *(s->top) = e;
    s->top++;
}

void pop( sqStack *s, ElemType *e )
{
    if( s->base == s->top )
    {
        return;
    }
    *e = *--(s->top);
}

int stackLen( sqStack s )
{
    return (s.top - s.base);    //这里用点 不用 "->"
}

int main()
{
    ElemType c;

    sqStack s;

    int len, i, sum = 0;

    initStack(&s);

    printf("请输入二进制数，输入#号键结束。\n");

    scanf("%c",&c);

    while( c != '#' )
    {
        push(&s,c);
        scanf("%c",&c);
    }

    getchar();

    len = stackLen(s);

    printf("栈的当前容量为：%d。\n",len);

    for( i=0; i<len; i++ )
    {
        pop(&s, &c);
        sum = sum + (c-48) * pow(2, i);
    }

    printf("十进制数为：%d.\n", sum);

    return 0;
}
