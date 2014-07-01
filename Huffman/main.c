#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE    128

typedef char    ElemType;

//����շ������ڵ�
typedef struct Node
{
    ElemType data;
    int num;
    struct Node *l_chlid;
    struct Node *r_child;
    struct Node *next;
}Node, *HufQueue, *HufTree;

//��Ԫ�ط�����ʵ�λ�ã�����С˳������
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

//��ȡ��С��Ԫ�أ�Ҳ���ǵ�һ��Ԫ�ء�
void get( HufQueue Q, Node **n )
{
    (*n) = Q->next;
}

//��Ȩ����������Huffman��
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

//��ʼ��ԭʼ����
void initQueue( HufQueue *q, char (*cou)[2] )
{
    Node *x, *y;
    int j;
    int len = cou[0][1];

    if( len <= 0 )
    {
        printf("����ȷ����������Ϣ��");
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

//��ȡ�û����룬���ַ������档
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

//�����ַ����� ��ĸ�ĸ��� �� ���ִ�����
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

//������õ�ͳ�������������
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

    //��ӡһ���ź����ԭʼ���顣
    len = cou[0][1];
    for( i=0; i<len+1; i++ )
        printf("%c ", cou[i][0]);
    printf("\n");
    for( i=0; i<len+1; i++ )
        printf("%d ", cou[i][1]);
    printf("\n");

    //��ʼ����Ȩ������
    initQueue( &Q, cou );



    /* ����push����
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

    /* ����get����
    printf("%d", Q->next->next->num);

    Node *n = NULL;
    n = (Node *)malloc(sizeof(Node));
    get(Q,&n);
    printf("%d",n->num);
    */

    //��Ȩ����������Huffman��
    createTree( &T, &Q );

    return 0;
}
