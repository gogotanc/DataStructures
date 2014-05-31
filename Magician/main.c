/*
    ħ��ʦ����һ�����е�13�ź��ƣ�Ԥ�Ƚ������źú������һ�����泯�¡�
    �Թ���˵�����Ҳ����ƣ�ֻ�����Ϳ��Բµ�ÿ������ʲô���Ҵ��������������������ţ�
    �ֳ���ʾ����ħ��ʦ�����������������Ϊ1�����������������Ǻ���A��������A���������ϣ�
    �ڶ�����1,2������һ���Ʒ�����Щ�Ƶ����棬���ڶ����Ʒ������������Ǻ���2��
    Ҳ���������������������ν��н�13����ȫ��������׼ȷ����
*/

#include <stdio.h>
#include <stdlib.h>

#define OK      1
#define FALSE   0
#define TRUE    1
#define ERROR   0

typedef int     status;
typedef int     element;

typedef struct  MyNode
{
    element data;
    struct Node *next;
}Node,*LinkList;

//����һ��13��Ԫ�صĵ�ѭ������
status initList( LinkList *L )
{
    (*L) = (LinkList)malloc(sizeof(Node));

    if( !(*L))
        return ERROR;

    Node *p, *q;
    int i = 13;

    p = (*L);
    p->next = NULL;

    for( ; i>0; i--)
    {
        q = (Node *)malloc(sizeof(Node));

        if( !q )
            return ERROR;

        q->data = -1;

        q->next = p->next;
        p->next = q;
        p = q;
    }
    p->next = (*L)->next;

    return OK;
}

//������Ǽ�֤�漣��ʱ��
status magic( LinkList *L )
{
    Node *p;
    int i, j;

    p = (*L);

    for( i=1; i<=13; i++)
    {
        for( j=0; j<i; j++)
        {
            p = p->next;
            while( p->data != -1)
            {
                p = p->next;
            }
        }

        p->data = i;
    }

    return OK;
}

status printfList( LinkList L )
{
    Node *p;
    int i = 13;

    p = L;

    while( i )
    {
        p = p->next;
        printf("%d,",p->data);
        i--;
    }
    return OK;
}

int main()
{
    LinkList list = NULL;

    initList(&list);

    magic(&list);

    printfList(list);

    return 0;
}
