/*
    ����������

    �Կ�ָ�벿���Ż�����ʾǰ׺�ͺ��Ԫ��
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

//����ȫ�ֱ��������浱ǰ������ǰһ���ڵ�
Node *pre = NULL;

//��������
void create( BTree *T, int *flag );
void completeTree( BTree T );
void InOrderTraverse( BTree T );

//������
int main()
{
    BTree T = NULL;
    int flag = 0;

    pre = (Node *)malloc(sizeof(Node));

    create( &T, &flag );

    completeTree( T );

    return 0;
}

//�����û���ǰ���������
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

//������ָ����˷�
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

//�ǵݹ�ʵ���������
void InOrderTraverse( BTree T )
{

}


