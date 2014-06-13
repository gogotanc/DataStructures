/*
    ���е�˳��洢�ṹ:

    ѭ���������������ǹ̶��ģ�
    �������Ķ�ͷ�Ͷ�βָ�붼��������Ԫ��������ж������ı䣬
    ����ѭ�������߼��Ͼͺ�����һ�����δ洢�ռ䡣
    ��Ҫע����ǣ���ʵ�ʵ��ڴ浱�У�
    �������������Ļ��δ洢��������ֻ����˳���ģ��������߼��ϵ�ѭ����
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
