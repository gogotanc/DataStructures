/*
    ��8*8�������������ϣ�Ҫ����ÿһ�з���һ���ʺ�����������������б����û�г�ͻ��


    �ݹ��㷨��
    1.���и���������
    2.δ���������������ݹ顣
*/

#include <stdio.h>
#include <stdlib.h>

int count = 0;

//�ж� �� �� б�� �����Ƿ�Σ��
int notDanger( int row, int j, int (*chess)[8] )
{
    int i, k;
    int flag_1 = 0,flag_2 = 0,flag_3 = 0,flag_4 = 0,flag_5 = 0;

    //�ж���
    for( i=0; i<8; i++ )
    {
        if( *(*(chess+i)+j) != 0 )
        {
            flag_1 = 1;
            break;
        }
    }

    //�ж�����
    for( i=row,k=j; i>=0 && k>=0; i--,k-- )
    {
        if( *(*(chess+i)+k) != 0 )
        {
            flag_2 = 1;
            break;
        }
    }

    //�ж�����
    for( i=row,k=j; i<8 && k<8; i++,k++ )
    {
        if( *(*(chess+i)+k) != 0 )
        {
            flag_3 = 1;
            break;
        }
    }

    //�ж�����
    for( i=row,k=j; i<8 && k>=0; i++,k-- )
    {
        if( *(*(chess+i)+k) != 0 )
        {
            flag_4 = 1;
            break;
        }
    }

    //�ж�����
    for( i=row,k=j; i>=0 && k<8; i--,k++ )
    {
        if( *(*(chess+i)+k) != 0 )
        {
            flag_5 = 1;
            break;
        }
    }

    if( flag_1 || flag_2 || flag_3 || flag_4 || flag_5 )
        return 0;
    else
        return 1;

}

//���� row  ��ʼ��
//���� col  ��
//���� (*chess)[8] ��ָ��
void eightQueens( int row, int col, int (*chess)[8] )
{
    int chess_2[8][8], i, j;

    for( i=0; i<8; i++ )
    {
        for( j=0; j<8; j++ )
        {
            chess_2[i][j] = chess[i][j];
        }
    }

    if( 8 == row )
    {
        printf("NO.%d:\n", ++count);
        for( i=0; i<8; i++ )
        {
            for( j=0; j<8; j++ )
            {
                printf("%d ", chess[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        for( j=0; j<col; j++ )
        {
            if( notDanger( row, j, chess_2 ) )
            {
                for( i=0; i<8; i++ )
                {
                    *(*(chess_2+row)+i) = 0;
                }

                *(*(chess_2+row)+j) = 1;

                eightQueens( row+1, col, chess_2 );
            }
        }
    }
}

int main()
{
    int chess[8][8], i, j;

    for( i=0; i<8; i++ )
    {
        for( j=0; j<8; j++ )
        {
            chess[i][j] = 0;
        }
    }

    eightQueens( 0, 8, chess );

    return 0;
}
