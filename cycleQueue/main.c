/*
    队列的顺序存储结构:

    循环队列它的容量是固定的，
    并且它的队头和队尾指针都可以随着元素入出队列而发生改变，
    这样循环队列逻辑上就好像是一个环形存储空间。
    但要注意的是，在实际的内存当中，
    不可能有真正的环形存储区，我们只是用顺序表模拟出来的逻辑上的循环。
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE     100

typedef int     ElemType;

typedef struct
{
    ElemType *base;

    int front;
    int rear;
}cycleQueue;

void initQueue( cycleQueue *q )
{
    q->base = (ElemType *)malloc( MAXSIZE * sizeof(ElemType) );

    q->front = q->rear = 0;
}

void push( cycleQueue *q, ElemType e )
{
    if( (q->rear+1)%MAXSIZE == q->front )
    {
        printf("queue is full.");
        return;
    }

    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
}

void pop( cycleQueue *q, ElemType *e )
{
    if( q->front == q->rear )
    {
        printf("queue is empty.");
        return;
    }

    *e = q->base[q->front];
    q->front = (q->front + 1) % MAXSIZE;
}


int main()
{
    cycleQueue q;
    ElemType e;

    initQueue( &q );

    push( &q, 23 );

    pop( &q, &e );

    printf("%d", e);

    return 0;
}
