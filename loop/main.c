/*

创建一个单链表，分为有环和无环；

用两种方法判断是否有环。

方法一：使用p、q两个指针，p总是向前走，但q每次都从头开始走，对于每个节点，看p走的步数是否和q一样。
如图，当p从6走到3时，用了6步，此时若q从head出发，则只需两步就到3，因而步数不等，出现矛盾，存在环。
http://blog.fishc.com/1973.html

方法二：使用p、q两个指针，p每次向前走一步，q每次向前走两步，若在某个时候p == q，则存在环。

*/


#include <stdio.h>
#include <stdlib.h>

#define OK      1
#define FALSE   0
#define TRUE    1
#define ERROR   0

typedef int     status;
typedef int     ElemType;

typedef struct MyNode
{
    ElemType data;
    struct MyNode *next;
    //struct MyNode *prior;
}Node,*LinkList;

//创建一个有环的双向链表
status CreateListWithLoop(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(Node));

    if( !(*L) )
    {
        return FALSE;
    }

    Node *p,*q;

    p = (*L);

    p->next = NULL;

    int i = 0;

    for(; i<10; i++)
    {
        q = (Node *)malloc(sizeof(Node));

        if(!q)
        {
            return ERROR;
        }

        q->data = i;
        q->next = p->next;
        p->next = q;

        p = q;
    }

    q->next = (*L)->next->next;

    return OK;
}

//创建一个无环的双向链表
status CreateListWithoutLoop(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(Node));

    if( !(*L) )
    {
        return FALSE;
    }

    Node *p,*q;

    p = (*L);

    p->next = NULL;

    int i = 0;

    for(; i<10; i++)
    {
        q = (Node *)malloc(sizeof(Node));

        if(!q)
        {
            return ERROR;
        }

        q->data = i;
        q->next = p->next;
        p->next = q;

        p = q;
    }

    return OK;
}

//打印链表
status PrintfList(LinkList *L)
{
    Node *p,*q;
    int i = 15;

    p = (*L);

    for(; i>0; i--)
    {
        q = p->next;
        if( !q )
        {
            return ERROR;
        }
        printf("%d,",q->data);
        p = q;
    }
    printf("\n");

    return OK;
}

//快慢指针法
status MethodOne(LinkList *L)
{
    printf("方法一判定：");

    Node *p,*q;

    p = (*L);

    q = (*L);

    do
    {
        p = p->next;
        q = q->next->next;

        if( p == q )
        {
            printf("此链表有环。");
            return OK;
        }
    }while( q || p);

    printf("此链表无环。");
    return OK;
}

//计算步数法
status MethodTwo( LinkList *L )
{
    printf("方法二判定：");

    Node *p,*q;

    p = (*L);

    int i = 0;
    int j = 0;

    while( TRUE )
    {
        p = p->next;

        if( !p )
        {
            printf("此链表无环。\n");
            return OK;
        }

        i++;
        q = (*L);
        while( q != p )
        {
            q = q->next;
            j++;
        }
        if( i != j )
        {
            printf("此链表有环。\n");
            return OK;
        }
    }
}

int main()
{
    status result = 2;

    LinkList list = NULL;

    result = CreateListWithLoop(&list);

    //result = CreateListWithoutLoop(&list);

    //result = MethodOne(&list);

    result = MethodTwo(&list);

    result = PrintfList(&list);

    return 0;
}
