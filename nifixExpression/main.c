#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
#define MAXBUFFER       10

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
    return (int)(s.top - s.base);    //这里用点 不用 "->"
}

//遇见是符号输入时的操作函数。
void symbolFunc( sqStack *s, char input )
{
    ElemType out;
    //char buf[10];
    //int index = 0;
    //int result = 0;
    //sqStack *s = myStack;

    switch( input )
        {
            case '+' :
                while( s->base!=s->top && out!='(' )
                {
                    pop(s,&out);
                    if( out=='+' || out=='-' )
                        printf("%c ",out);
                    if( out=='*' || out=='/' )
                        printf("%c ",out);
                    if( out=='(' )
                    {
                        push(s,out);
                        break;
                    }
                }
                push( s, input );
                break;

            case '-' :
                while( s->base!=s->top && out!='(' )
                {
                    pop(s,&out);
                    if( out=='+' || out=='-' )
                        printf("%c ",out);
                    if( out=='*' || out=='/' )
                        printf("%c ",out);
                    if( out=='(' )
                    {
                        push(s,out);
                        break;
                    }
                }
                push( s, input );
                break;

            case '*' :
                while( s->base!=s->top && out!='(' )
                {
                    pop(s,&out);
                    if( out=='*' || out=='/' )
                        printf("%c ",out);
                    if( out=='+' || out=='-' || out=='(')
                    {
                        push(s,out);
                        break;
                    }
                }
                push( s, input );
                break;

            case '/' :
                while( s->base!=s->top && out!='(' )
                {
                    pop(s,&out);
                    if( out=='*' || out=='/' )
                        printf("%c ",out);
                    if( out=='+' || out=='-' || out=='(')
                    {
                        push(s,out);
                        break;
                    }
                }
                push( s, input );
                break;

            case '(' :
                push( s, input );
                break;

            case ')' :
                while( s->base!=s->top && out != '(' )
                {
                    pop( s, &out );
                    if( out != '(' )
                        printf("%c ",out);
                }
                break;
        }
}

int main()
{
    sqStack stack;
    ElemType input,out;
    //char str[MAXBUFFER];
    //int i = 0;

    initStack( &stack );

    scanf("%c",&input);

    while( input != '#' )
    {
        while( isdigit(input) || input == '.' )
        {
            printf("%c",input);

            scanf("%c",&input);

            if( input == ' ' )
            {
                printf("%c",input);
                break;
            }
        }

        symbolFunc( &stack,input );

        scanf("%c",&input);
    }

    while( stack.base != stack.top )
    {
        pop( &stack, &out );
        printf("%c ",out);
    }

    return 0;
}
