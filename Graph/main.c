/*
    邻接矩阵（无向图）
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { V1, V2, V3, V4 } node;

int main()
{
    node n, m;

    int graph[4][4] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0}};

    for( n=V1; n<=V4; n++ )
    {
        for( m=V1; m<=V4; m++ )
        {
            if( 1 == graph[n][m] )
            {
                printf("节点%d --> 节点%d\n", n, m);
            }
        }
    }

    return 0;
}
