#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 9
#define sqr 3
//int row,col;
int grid[N][N]={
   {8,0,0,0,0,0,0,0,0},
   {0,0,3,6,0,0,0,0,0},
   {0,7,0,0,9,0,2,0,0},
   {0,5,0,0,0,7,0,0,0},
   {0,0,0,0,4,5,7,0,0},
   {0,0,0,1,0,0,0,3,0},
   {0,0,1,0,0,0,0,6,8},
   {0,0,8,5,0,0,0,1,0},
   {0,9,0,0,0,0,4,0,0}
};
bool isSafe(int row, int col, int num)
{
    int i,j;
    int srow,scol;
    for(i=0;i<N;i++)
    {
        if(grid[row][i]==num)
            return false;
    }
    for(i=0;i<N;i++)
    {
        if(grid[i][col]==num)
            return false;
    }
    srow = (row/3)*3;
    scol = (col/3)*3;
    for(i=srow; i<srow+sqr;i++)
    {
        for(j=scol;j<scol+sqr;j++)
        {
            if(grid[i][j]==num)
            {
                return false;
            }
        }
    }
    return true;
}

bool findUnassignedLocation(int *row,int *col)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(grid[i][j]==0)
            {
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false;
}
bool solveSudoku()
{
    int num;
    int row,col;
    if(!findUnassignedLocation(&row,&col))
        return true;
    for(num=1;num<=N;num++)
    {
        if(isSafe(row,col,num))
        {
            grid[row][col]=num;
            if(solveSudoku())
                return true;
            grid[row][col]=0;
        }
    }
    return false;  
}
int main()
{
    int i,j;
    if(solveSudoku())
    {
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                printf("%d ",grid[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No solution");
    }
    
}