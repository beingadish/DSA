#include<bits/stdc++.h>

#define N 4

using namespace std;

bool isSafe(int r,int c,int chess[N][N])
{
    for(int row=0;row<=r;row++)//checking in upper part of row
    {
        if(chess[row][c]==1)
        return false;
    }
    for(int i=r,j=c;i>=0&&j>=0;i--,j--)//checking in left upper diagonal
    {
        if(chess[i][j]==1)
        return false;
    }
    for(int i=r,j=c;i>=0&&j<N;i--,j++)//checking in right upper diagonal
    {
        if(chess[i][j]==1)
        return false;
    }
    return true;
}

bool nQueen(int chess[N][N],int r)
{
    if(r==N)
    return true;

    for(int col=0;col<N;col++)
    {
        if(isSafe(r,col,chess)==true)
        {
            chess[r][col]=1;
            if(nQueen(chess,r+1)==true)
            return true;
            chess[r][col]=0;
        }
    }
    return false;
}

void printChess(int chess[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        cout<<" "<<setw(2)<<chess[i][j]<<" ";
        cout<<endl; 
    }
}

void solution()
{
    int chess[N][N]={ {0 ,0 ,0 ,0 },
                      {0 ,0 ,0 ,0 },
                      {0 ,0 ,0 ,0 },
                      {0 ,0 , 0,0 } };
    if(nQueen(chess,0)==true)
    {
        printChess(chess);
    }
    else{
        cout<<"Solution not Possible...";
    }
}

int main()
{
    solution();
    return 0;
}