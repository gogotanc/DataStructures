#include <stdio.h>
#include <stdlib.h>

#define OK      1
#define ERROR   0

typedef int     status;
typedef int     ElemType;

typedef struct DaulNode
{
    ElemType data;
    struct DaulNode *prior;
    struct DaulNode *next;
}DaulNode, *DuLinkList;

status InitList(DuLinkList *L)
{
    (*L) = (DuLinkList)malloc(sizeof(DaulNode));

    if( !(*L) )
    {
        return ERROR;
    }

    (*L)->prior = (*L)->next = NULL;

    DaulNode *p, *q;
    int i;

    p = (*L);

    for(i=0; i<26; i++)
    {
        q = (DuLinkList)malloc(sizeof(DaulNode));

        if(!q)
        {
            return ERROR;
        }

        q->data = 'A' + i;
        q->prior = p;
        q->next = p->next;
        p->next = q;

        p = q;
    }

    p->next = (*L)->next;
    (*L)->prior = p;
    (*L)->next->prior = p;

    return OK;
}

status Caesar(DuLinkList *L, int i)
{
    if(i>0)
    {
        do
        {
            (*L) = (*L)->next;
        }while(--i);
    }

    if(i<0)
    {
        do
        {
            (*L) = (*L)->prior;
        }while(i++);
    }

    return OK;
}

int main()
{
    int index,i;
    status result;
    DuLinkList list = NULL;

    result = InitList(&list);

    printf("%d\n请输入一个整数：\n",result);
    scanf("%d", &index);
    printf("\n");

    Caesar(&list,index);

    for(i=0; i<26; i++)
    {
        list = list->next;
        printf("%c", list->data);
    }

    return 0;
}
