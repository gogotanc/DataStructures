/*
    正常的表达式 —> 逆波兰表达式
    a+b —> a b +
    a+(b-c) —> a b c – +
    a+(b-c)*d —> a b c – d * +
    a+d*(b-c)—> a d b c – * +
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
#define MAXBUFFER       10

typedef double ElemType;

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
    sqStack s;
    ElemType a,b;
    char c;
    char str[MAXBUFFER];
    int i = 0;
    double d;

    initStack( &s );

    scanf("%c",&c);

    while( c != '#' )
    {
        while( isdigit(c) || c == '.' )
        {
            str[i++] = c;
            str[i] = '\0';

            scanf("%c",&c);

            if( c == ' ' )
            {
                d = atof(str);
                i = 0;
                push(&s,d);
                break;
            }
        }

        switch( c )
        {
            case '+':
                pop(&s,&a);
                pop(&s,&b);
                push(&s, b+a);
                break;
            case '-':
                pop(&s,&a);
                pop(&s,&b);
                push(&s, b-a);
                break;
            case '*':
                pop(&s,&a);
                pop(&s,&b);
                push(&s, a*b);
                break;
            case '/':
                pop(&s,&a);
                pop(&s,&b);
                if( a == 0 )
                {
                    printf("\n除数不能为零。\n");
                    return -1;
                }
                push(&s, b/a);
                //printf("%c",b/a);
                //printf("%d",b/a);
                //printf("%s",b/a);
                break;
        }
        scanf("%c",&c);
    }

    pop(&s,&b);

    printf("%f",b);

    return 0;
}
