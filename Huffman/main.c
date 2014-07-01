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
    struct Node *l_chlid;
    struct Node *r_child;
    struct Node *next;
}Node, *HufQueue, *HufTree;

//将元素放入合适的位置，按大小顺序排列
void push( HufQueue *Q, Node **n )
{
    Node *x, *y;
    x = (*Q);
    while( x->next != NULL )
    {
        y = x;
        x = x->next;

        if( (*n)->num < x->num )
        {
            (*n)->next = x;
            y->next = (*n);
            break;
        }
    }
}

//获取最小的元素，也就是第一个元素。
void get( HufQueue Q, Node **n )
{
    (*n) = Q->next;
}

//带权的链表生成Huffman树
void createTree( HufTree *T, HufQueue *Q )
{
    Node *x, *y;
    Node *n;

    (*T) = (HufTree)malloc(sizeof(Node));

    get( *Q, &x );
    get( *Q, &y );

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

    push( Q, &n );


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

    x = (*q);

    for( j=1; j<len+1; j++ )
    {
        y = (Node *)malloc(sizeof(Node));
        y->data = cou[j][0];
        y->num = cou[j][1];
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
    int i, len;
    char str[256];
    char cou[128][2];
    HufQueue Q = NULL;
    HufTree T = NULL;

    getInput( str );

    count( str, cou );

    mySort( cou );

    //打印一下排好序的原始数组。
    len = cou[0][1];
    for( i=0; i<len+1; i++ )
        printf("%c ", cou[i][0]);
    printf("\n");
    for( i=0; i<len+1; i++ )
        printf("%d ", cou[i][1]);
    printf("\n");

    //初始化带权的链表。
    initQueue( &Q, cou );



    /* 测试push函数
    Node *n = NULL;
    n = (Node *)malloc(sizeof(Node));
    n->l_chlid = n->r_child = n->next = NULL;
    n->data = '\\';
    n->num = 2;
    push( &Q, &n );

    while( Q->next != NULL )
    {
        Q = Q->next;
        printf("%d", Q->num);
    }
    */

    /* 测试get函数
    printf("%d", Q->next->next->num);

    Node *n = NULL;
    n = (Node *)malloc(sizeof(Node));
    get(Q,&n);
    printf("%d",n->num);
    */

    //带权的链表生成Huffman树
    createTree( &T, &Q );

    return 0;
}
