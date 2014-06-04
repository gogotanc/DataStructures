#include <stdio.h>
#include <stdlib.h>

#define OK      1
#define FALSE   0
#define TRUE    1
#define ERROR   0

typedef int ElemType;
typedef int status;

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct
{
    LinkStackPtr top;
    int counter;
}LinkStack;

void initLinkStack( LinkStack **s )
{
    (*s) = (LinkStack *)malloc(sizeof(LinkStack));

    (*s)->counter = 0;
    (*s)->top = NULL;

    return;
}

status push( LinkStack *s, ElemType e )
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));

    p->data = e;
    p->next = s->top;
    s->top = p;
    s->counter++;

    return OK;
}

status pop( LinkStack *s, ElemType *e )
{
    if( s->top == NULL )
    {
        return ERROR;
    }

    LinkStackPtr p = s->top;

    *e = p->data;

    s->top = p->next;
    s->counter--;

    free(p);

    return OK;
}

int main()
{
    LinkStack *s = NULL;

    ElemType e;

    initLinkStack( &s );

    push( s, 23 );

    pop( s, &e );

    printf("%d", e);

    return 0;
}
