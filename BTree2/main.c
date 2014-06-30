/*
    线索二叉树

    对空指针部分优化，表示前缀和后继元素
*/

#include <stdio.h>
#include <stdlib.h>

typedef char    ElemType;

typedef struct BTreeNode
{
    ElemType data;
    int l_flag;
    struct BTreeNode *l_child;
    int r_flag;
    struct BTreeNode *r_child;
}Node, *BTree;

//定义全局变量，保存当前遍历的前一个节点
Node *pre = NULL;

//声明函数
void create( BTree *T, int *flag );
void completeTree( BTree T );
void InOrderTraverse( BTree T );

//主函数
int main()
{
    BTree T = NULL;
    int flag = 0;

    pre = (Node *)malloc(sizeof(Node));

    create( &T, &flag );

    completeTree( T );

    return 0;
}

//接收用户的前序遍历输入
void create( BTree *T, int *flag )
{
    ElemType c;

    scanf("%c",&c);

    if( ' ' == c )
    {
        *T = NULL;
        *flag = 1;
    }
    else
    {
        (*T) = (Node *)malloc(sizeof(Node));
        (*T)->l_flag = 0;
        (*T)->r_flag = 0;
        (*T)->data = c;

        create( &(*T)->l_child, &(*T)->l_flag);
        create( &(*T)->r_child, &(*T)->r_flag);
    }
}

//消除空指针的浪费
void completeTree( BTree T )
{

    if( T )
    {
        completeTree( T->l_child );

        if( T->l_flag == 1 )
        {
            T->l_child = pre;
        }
        if( pre->r_flag == 1 )
        {
            pre->r_child = T;
        }

        printf("%c", T->data);

        pre = T;

        completeTree( T->r_child );
    }
}

//非递归实现中序遍历
void InOrderTraverse( BTree T )
{

}


