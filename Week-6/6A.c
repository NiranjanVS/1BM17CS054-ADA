#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define N 4
bool isSafe(int board[N][N],int row, int  col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])
            return false;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]==1)
            return false;
    }
    for(i=row,j=col;i<N && j>=0;i++,j--)
    {
        if(board[i][j]==1)
            return false;
    }
    return true ;
}
bool nQueesmain(int board[N][N],int col)
{
    int i;
    if(col>=N)
    {
        return true;
    }
    for(i=0;i<N;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col]=1;
            if(nQueesmain(board,col+1))
                return true;
            board[i][col]=0;
        }
    } 
    return false;
}
bool solveNqueue()
{
    int i,j;
    int board[N][N]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    if(nQueesmain(board,0))
    {
        //printf("{");
        for(i=0;i<N;i++)
        {
            printf("{");
            for(j=0;j<N;j++)
            {
                printf("%d ",board[i][j]);
            }
            printf("}\n");
        }
        //printf("}\n");
    }
    else
    {
        printf("No solution");
    }
    
}
int main()
{
    solveNqueue();
    return 0;
}