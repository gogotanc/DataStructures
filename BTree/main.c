/*
    �ó���ʵ�֣�
    ����Ϊ���û���ǰ�����������һ����������
    ���Ϊ��ÿ���ڵ�λ����һ�㡣
*/



#include <stdio.h>
#include <stdlib.h>

typedef char    ElemType;

typedef struct BTreeNode
{
    ElemType data;
    struct BTreeNode *l_child;
    struct BTreeNode *r_child;
}Node, *BTree;

void create( BTree *T )
{
    char c;

    scanf("%c",&c);
    if( '*' == c )
    {
        (*T) = NULL;
    }
    else
    {
        (*T) = (Node *)malloc(sizeof(Node));
        (*T)->data = c;
        create( &(*T)->l_child );
        create( &(*T)->r_child );
    }
}

void visit( char data, int level )
{
    printf("%c λ�ڵ�%d�㡣\n", data, level);
}

void ProOrderPraverse( BTree T, int level )
{
    if( T )
    {
        visit( T->data, level );
        ProOrderPraverse( T->l_child, level+1 );
        ProOrderPraverse( T->r_child, level+1 );
    }
}

int main()
{
    printf("����ǰ�����������������ڵ�Ϊ�����ÿո��ʾ����");

    BTree T = NULL;
    int level = 1;

    create( &T );

    ProOrderPraverse( T, level );

    return 0;
}
