/*
    二进制转化八进制。
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
    sqStack bin, oct;

    int i = 0, len, sum = 0;
    short flag = 0;

    initStack(&bin);
    initStack(&oct);

    printf("请输入二进制数，输入#号键结束。\n");

    scanf("%c",&c);
    while( c != '#' )
    {
        push(&bin,c);
        scanf("%c",&c);
    }

    len = stackLen(bin);


    for( i=1; i<=len; i++ )
    {
        pop(&bin, &c);
        sum = sum + (c-48) * pow( 2, (i-1)%3 );
        flag = 0;
        if( i%3 == 0 )
        {
            push(&oct, sum);
            sum = 0;
            flag = 1;
        }
    }
    if( !flag )
    {
        push(&oct, sum);
    }

    len = stackLen(oct);

    for( i=0; i<len; i++ )
    {
        pop(&oct, &c);
        printf("%d",c);
    }

    return 0;
}
