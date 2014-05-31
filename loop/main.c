/*

����һ����������Ϊ�л����޻���

�����ַ����ж��Ƿ��л���

����һ��ʹ��p��q����ָ�룬p������ǰ�ߣ���qÿ�ζ���ͷ��ʼ�ߣ�����ÿ���ڵ㣬��p�ߵĲ����Ƿ��qһ����
��ͼ����p��6�ߵ�3ʱ������6������ʱ��q��head��������ֻ�������͵�3������������ȣ�����ì�ܣ����ڻ���
http://blog.fishc.com/1973.html

��������ʹ��p��q����ָ�룬pÿ����ǰ��һ����qÿ����ǰ������������ĳ��ʱ��p == q������ڻ���

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

//����һ���л���˫������
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

//����һ���޻���˫������
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

//��ӡ����
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

//����ָ�뷨
status MethodOne(LinkList *L)
{
    printf("����һ�ж���");

    Node *p,*q;

    p = (*L);

    q = (*L);

    do
    {
        p = p->next;
        q = q->next->next;

        if( p == q )
        {
            printf("�������л���");
            return OK;
        }
    }while( q || p);

    printf("�������޻���");
    return OK;
}

//���㲽����
status MethodTwo( LinkList *L )
{
    printf("�������ж���");

    Node *p,*q;

    p = (*L);

    int i = 0;
    int j = 0;

    while( TRUE )
    {
        p = p->next;

        if( !p )
        {
            printf("�������޻���\n");
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
            printf("�������л���\n");
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
