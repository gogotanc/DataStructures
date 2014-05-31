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

    return OK;
}

int main()
{
    LinkList list = NULL;

    initList(&list);

    return 0;
}
