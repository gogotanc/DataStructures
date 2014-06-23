#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE     10

typedef char        ElemType;

//方法二
void method_2( ElemType *str, ElemType *next )
{
    // [x] == [x+i]
    int i, x, y;
    int len;

    len = str[0];
    next[0] = len;

    for( i=1; i<=len; i++ )
    {
        for( x=1,y=1; (x+y)<i; )
        {
            if( str[x] == str[x+y] )
            {
                x++;
            }
            else
            {
                x=1;
                y++;
            }
        }
        next[i] = i-y;
    }

}

//自创的方法一
void method_1( ElemType *str, ElemType *next )
{
    int i, j, x, y, z;
    //int count;

    i = str[0];

    next[0] = i;
    next[1] = 0;

    next[2] = 1;

    for( j=3; j<=i; j++ )
    {
        for( y=2; y<j; y++ )
        {
            z = y;
            x = 1;
            next[j] = 1;

            while( str[x] == str[z] )
            {
                x++;
                z++;
                if( z == j )
                {
                    next[j] = j-y+1;
                    break;
                }
            }
            if( z == j )
                break;
        }

        /*count = 1;
        for( k=j-1,x=1; x<k; x++ )
        {
            if( str[k] != str[x] )
                break;
            count++;
        }
        next[j] = count;*/
    }
}

void initStr( ElemType **str )
{
    (*str) = (ElemType *)malloc( MAXSIZE * sizeof(ElemType) );
}

int main()
{
    ElemType *str, *next;
    char in;
    int len = 0, i;

    initStr( &str );
    initStr( &next );

    scanf("%c", &in);
    while( '#' != in && len <9 )
    {
        len++;
        str[len] = in;
        scanf("%c", &in);
    }
    str[0] = len;

    //method_1( str, next );
    method_2( str, next );

    for( i=1; i<=next[0]; i++ )
        printf("%d", next[i]);

    return 0;
}
