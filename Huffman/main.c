#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE    128

typedef char    ElemType;

//定义赫夫曼树节点
typedef struct Node
{
    ElemType data;
    int num;
    char *code;
    struct Node *l_chlid;
    struct Node *r_child;
    struct Node *next;
}Node, *HufQueue, *HufTree;

void printCode( HufTree *T )
{
    Node *n;
    n = (*T);

    if( n->l_chlid == NULL && n->r_child == NULL )
    {
        printf("元素 %c 编码为 \" %s \". \n", n->data, n->code );
    }
    else
    {
        printCode( &n->l_chlid );
        printCode( &n->r_child );
    }
}

//给字符串添加字符
char * addCode( char *str, char code )
{
    int i;
    char *buf;
    int len = strlen( str );
    buf = (char *)malloc( len * sizeof(char));

    for( i=0; i<len; i++ )
    {
        buf[i] = str[i];
    }
    buf[len] = code;
    buf[len+1] = '\0';
    return buf;
}

//对Huffman树进行编码
void encode( Node **n, char *c )
{
    if( c == NULL )
    {
        c = (char *)malloc(sizeof(char));
        c[0] = '\0';
    }

    Node *x;
    x = (*n);
    char l_code = '0';
    char r_code = '1';

    x->code = (char *)malloc(sizeof(char));
    x->code = c;

    if( x->l_chlid != NULL )
    {
        encode( &x->l_chlid, addCode( c, l_code ) );
    }
    if( x->r_child != NULL )
    {
        encode( &x->r_child, addCode( c, r_code ) );
    }
}

//将元素放入合适的位置，按大小顺序排列
void push( HufQueue *Q, Node **n )
{
    HufQueue x = NULL;
    Node *y;
    x = (*Q);

    if( x->next == NULL )
    {
        x->next = (*n);
        return;
    }

    while( x->next != NULL )
    {
        y = x;
        x = x->next;

        if( (*n)->num <= x->num )
        {
            (*n)->next = x;
            y->next = (*n);
            break;
        }

        if( x->next == NULL )
        {
            x->next = (*n);
            break;
        }
    }
}

//获取最小的元素，也就是第一个元素。
void get( HufQueue *Q, Node **n )
{
    HufQueue q = NULL;
    q = (*Q);

    if( q->next != NULL )
    {
        (*n) = q->next;
        q->next = q->next->next;
    }
    else
    {
        (*n) = NULL;
    }
}

//带权的链表生成Huffman树  想递归实现
void createTree( HufTree *T, HufQueue *Q )
{
    HufQueue q = NULL;
    HufTree t = NULL;
    Node *x, *y;
    Node *n;

    q = (*Q);
    t = (*T);

    get( &q, &x );
    get( &q, &y );

    //test
    printf("\n--------------------------------\n");
    if( x != NULL)
    {
        printf("x data: %c = %d ", x->data,x->num);
    }
    printf(" ... ");
    if( y != NULL )
    {
        printf("y data: %c = %d ", y->data,y->num);
    }
    printf("\n--------------------------------\n");

    if( x != NULL && y == NULL )
    {
        (*T) = (HufTree)malloc(sizeof(Node));
        (*T)->next = x;
    }
    else
    {
        n = (Node *)malloc(sizeof(Node));

        n->num = x->num + y->num;

        if( x->num < y->num )
        {
            n->l_chlid = x;
            n->r_child = y;
        }
        else
        {
            n->l_chlid = y;
            n->r_child = x;
        }
        n->data = '\\';
        n->next = NULL;

        push( &q, &n );

        createTree( &t, &q );
    }
}

//带权的链表生成Huffman树  迭代实现
void createTree2( HufTree *T, HufQueue *Q )
{
    HufQueue q = NULL;
    Node *x, *y;
    Node *n;

    q = (*Q);

    get( &q, &x );
    get( &q, &y );

    while( 1 )
    {
        //test
        /*
        printf("\n--------------------------------\n");
        if( x != NULL)
        {
            printf("x data: %c = %d ", x->data,x->num);
        }
        printf(" ... ");
        if( y != NULL )
        {
            printf("y data: %c = %d ", y->data,y->num);
        }
        printf("\n--------------------------------\n");
        */

        if( x != NULL && y == NULL )
        {
            (*T) = (HufTree)malloc(sizeof(Node));
            (*T) = x;
            break;
        }

        n = (Node *)malloc(sizeof(Node));

        n->num = x->num + y->num;
        n->data = '\\';
        n->code = NULL;
        n->next = NULL;

        if( x->num < y->num )
        {
            n->l_chlid = x;
            n->r_child = y;
        }
        else
        {
            n->l_chlid = y;
            n->r_child = x;
        }

        push( &q, &n );

        get( &q, &x );
        get( &q, &y );
    }
}

//初始化原始队列
void initQueue( HufQueue *q, char (*cou)[2] )
{
    Node *x, *y;
    int j;
    int len = cou[0][1];

    if( len <= 0 )
    {
        printf("请正确输入您的消息。");
        exit(0);
    }

    (*q) = (HufQueue)malloc(sizeof(Node));
    (*q)->l_chlid = (*q)->r_child =(*q)->next = NULL;
    (*q)->num = len;
    (*q)->data = '#';
    (*q)->code = NULL;

    x = (*q);

    for( j=1; j<len+1; j++ )
    {
        y = (Node *)malloc(sizeof(Node));
        y->data = cou[j][0];
        y->num = cou[j][1];
        y->code = NULL;
        y->l_chlid = y->r_child = y->next =NULL;
        x->next = y;
        x = y;
    }
}

//获取用户输入，用字符串保存。
void getInput( char *str )
{
    char in;
    int index = 0;

    scanf("%c", &in);

    while( '#' != in && index < MAX_BUF_SIZE )
    {
        str[index++] = in;
        str[index] = '\0';

        scanf("%c", &in);
    }
}

//计算字符串中 字母的个数 和 出现次数。
void count( char *str, char (*cou)[2] )
{
    int i, j;
    int len, len2;
    char c;

    len = strlen( str );
    len2 = 0;

    for( i=0; i<len; i++ )
    {
        c = str[i];

        for( j=1; j<len2+1 || 0==len2; j++)
        {
            if( c == cou[j][0] )
            {
                cou[j][1]++;
                break;
            }

            if( j == len2 )
            {
                len2++;
                cou[len2][0] = c;
                cou[len2][1] = 1;
                break;
            }

            if( 0 == len2 )
            {
                cou[j][0] = c;
                cou[j][1] = 1;
                len2++;
                break;
            }
        }
    }

    cou[0][0] = '\\';
    cou[0][1] = len2;
}

//对整理好的统计数组进行排序
void mySort( char (*cou)[2] )
{
    char temp_data;
    int temp_num;
    int i, j;
    int len = cou[0][1];
    for( i=1; i<len+1; i++ )
    {
        for( j=i+1; j<len+1; j++ )
        {
            if( cou[i][1] > cou[j][1] )
            {
                temp_num = cou[i][1];
                temp_data = cou[i][0];
                cou[i][1] = cou[j][1];
                cou[i][0] = cou[j][0];
                cou[j][1] = temp_num;
                cou[j][0] = temp_data;
            }
        }
    }
}

int main()
{
    //int i, len;
    char str[256];
    char cou[128][2];
    char *flag = NULL;

    HufQueue Q = NULL;
    HufTree T = NULL;

    printf("请输入您需要编码的讯息：\n");

    getInput( str );

    count( str, cou );

    mySort( cou );

    //初始化带权的链表。
    initQueue( &Q, cou );

    //带权的链表生成Huffman树
    createTree2( &T, &Q );

    //对各个字符进行编码
    encode( &T, flag );

    //打印每个元素的编码
    printCode( &T );

    return 0;
}


    /*
    测试push函数
    Node *n1 = NULL;
    n1 = (Node *)malloc(sizeof(Node));
    n1->l_chlid = n1->r_child = n1->next = NULL;
    n1->data = '\\';
    n1->num = 2;
    push( &Q, &n1 );

    while( Q->next != NULL )
    {
        Q = Q->next;
        printf("data: %c = %d \n", Q->data,Q->num);
    }
    */

    /*
    测试get函数
    Node *n2 = NULL;
    n2 = (Node *)malloc(sizeof(Node));
    get(&Q,&n2);
    while( Q->next != NULL )
    {
        Q = Q->next;
        printf("data: %c = %d \n", Q->data,Q->num);
    }
    */

        /*
    打印一下排好序的原始数组。
    len = cou[0][1];
    for( i=0; i<len+1; i++ )
        printf("%c ", cou[i][0]);
    printf("\n");
    for( i=0; i<len+1; i++ )
        printf("%d ", cou[i][1]);
    printf("\n");
    */
