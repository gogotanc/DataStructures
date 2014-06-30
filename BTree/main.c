/*
    该程序实现：
    输入为：用户用前序遍历法输入一个二叉树，
    输出为：每个节点位于哪一层。
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
    printf("%c 位于第%d层。\n", data, level);
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
    printf("请用前序遍历输入二叉树（节点为空请用空格表示）：");

    BTree T = NULL;
    int level = 1;

    create( &T );

    ProOrderPraverse( T, level );

    return 0;
}
