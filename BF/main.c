/*
    BF�㷨

    ��ʵ�ϣ�BF�㷨�����ǡ�BoyFriend���㷨����˼������һ���ܻƺܱ�����ԭ����Brute Force

    BF�㷨�������ص�ģʽƥ���㷨�����ĺ���˼���ǣ�

    �������ַ���S��T������ΪN��M������S[1]��T[1]�Ƚϣ�
    ����ȣ����ٱȽ�S[2]��T[2]��һֱ��T[M]Ϊֹ��
    ��S[1]��T[1]���ȣ���T�����ƶ�һ���ַ���λ�ã������ν��бȽϡ�

    ���㷨������Ҫ����M*(N-M+1)�αȽϣ�ʱ�临�Ӷ�ΪO(M*N)��
    ������S��������T���Ӵ��������Ӵ��Ķ�λ����ͨ����������ģʽƥ�䡣

    ����˳��洢�ṹʵ��BF�㷨��
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE     20

typedef struct
{
    char data[MAXSIZE];
    int lenght;
}myString;

void initString( myString **str )
{
    (*str) = (myString *)malloc(sizeof(myString));

    if( !(*str) )
    {
        printf("���������ԡ�");
        exit(0);
    }

    (*str)->lenght = 0;
}

int compareString( myString fat, myString son )
{
    int i,j,k;

    for( i=0; i<fat.lenght; i++)
    {
        for( j=0,k=i; ; j++,k++ )
        {
            if( fat.data[k] != son.data[j] )
                break;
            if( j == son.lenght-1 )
                return 1;
        }
    }
    return 0;
}

int main()
{
    myString *fat, *son;
    char in;
    int result = 0;

    initString( &fat );
    initString( &son );

    printf("�����븸��(��#�Ž���)��");

    scanf("%c", &in);
    while( '#'!=in && fat->lenght < MAXSIZE)
    {
        fat->data[fat->lenght++] = in;
        scanf("%c", &in);
    }

    printf("�������Ӵ�(��#�Ž���)��");

    scanf("%c", &in);
    scanf("%c", &in);
    while( '#'!=in && son->lenght < MAXSIZE )
    {
        son->data[son->lenght++] = in;
        scanf("%c", &in);
    }

    result = compareString( *fat, *son );

    if( result )
        printf("���������Ӵ���");
    else
        printf("��������");


    return 0;
}
