/*
    魔术师利用一副牌中的13张黑牌，预先将他们排好后叠放在一起，牌面朝下。
    对观众说：“我不看牌，只数数就可以猜到每张牌是什么，我大声数数，你们听，不信？
    现场演示。”魔术师将最上面的那张牌数为1，把他翻过来正好是黑桃A，将黑桃A放在桌子上，
    第二次数1,2，将第一张牌放在这些牌的下面，将第二张牌翻过来，正好是黑桃2，
    也将它放在桌子上这样依次进行将13张牌全部翻出，准确无误。
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

//产生一个13个元素的单循环链表
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

//下面就是见证奇迹的时刻
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
