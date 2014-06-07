#include <stdio.h>
#include <stdlib.h>

#define OK      1
#define FALSE   0
#define TRUE    1
#define ERROR   0

typedef int     ElemType;
typedef int     Status;

typedef struct QueueNode
{
    ElemType data;
    struct Node *next;

}Node,*LinkQueuePtr;

typedef struct
{
    LinkQueuePtr front,rear;
}LinkQueue;

Status initQueue( LinkQueue *q )
{
    q->front = q->rear = (LinkQueuePtr)malloc(sizeof(Node));

    if( !q->front )
    {
        return ERROR;
    }

    q->front->next = NULL;

    return OK;
}

Status push( LinkQueue *q, ElemType e )
{
    Node *p;

    p = (Node *)malloc(sizeof(Node));

    if( !p )
    {
        return ERROR;
    }

    p->data = e;
    p->next = NULL;

    q->rear->next = p;
    q->rear = p;

    return OK;
}

Status pop( LinkQueue *q, ElemType *e)
{
    if( q->front == q->rear )
    {
        printf("¿Õ¶ÓÁÐ¡£");
        return ERROR;
    }

    Node *p;

    p = q->front->next;

    *e = p->data;

    q->front->next = p->next;

    if( q->rear == p )
        q->rear = q->front;

    free( p );

    return OK;
}

int main()
{
    LinkQueue q;
    ElemType c;

    initQueue( &q );

    push( &q, 23 );

    pop( &q, &c );

    printf("%d",c);

    return 0;
}
