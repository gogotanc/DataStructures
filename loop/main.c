/*

����һ��������Ϊ�л����޻���

�����ַ����ж��Ƿ��л���

*/


#include <stdio.h>
#include <stdlib.h>

#define OK      1
#define FALSE   0

typedef int     status;
typedef int     ElemType;

typedef struct MyNode
{
    ElemType data;
    struct MyNode *next;
    struct MyNode *prior;
}Node,*LinkList;

status CreateListWithLoop(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(Node));

    if( !(*L) )
    {
        return FALSE;
    }

    Node *p,*q;

    p = (*L);


    int i = 10;

    while(i--)
    {

    }

    return OK;
}

status CreateListWithoutLoop(LinkList *L)
{
    return OK;
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
