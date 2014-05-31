/*

    ��ѭ������ģ��Լɪ�����⣬��41������ɱ��˳���������

*/

#include <stdio.h>
#include <stdlib.h>

#define OK      1
#define FALSE   0
#define TRUE    1
#define ERROR   0

typedef int     status;
typedef int     ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node,*LinkList;

//����41�и��˵Ķ��У��������
status initList( LinkList *L )
{
    (*L) = (LinkList)malloc(sizeof(Node));

    int i;
    Node *p,*q;

    p = (*L);

    p->next = NULL;

    for(i=1; i<=41; i++)
    {
        q = (Node *)malloc(sizeof(Node));

        q->data = i;
        q->next = p->next;
        p->next = q;

        p = q;
    }

    q->next = (*L)->next;

    return OK;
}

//���α�������3������ɱ��
status order4Kill( LinkList *L )
{
    int i = 0;
    int j = 1;

    Node *p, *q;

    p = (*L);

    while( TRUE )
    {
        i++;
        p = p->next;

        if( !p )
            return OK;

        if( i==2 )
        {
            q = p->next;

            p->next = p->next->next;
            p = p->next;

            printf("%d,", q->data);
            q->next = NULL;
            free(q);

            if( j%13 == 0 )
                printf("\n");

            i = 1;
            j++;
        }
    }
}

int main()
{
    LinkList list = NULL;

    initList(&list);

    order4Kill(&list);

    return 0;
}
