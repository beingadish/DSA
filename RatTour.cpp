#include<bits/stdc++.h>
#define N 4

using namespace std;

bool isSafe(int maze[N][N],int a,int b)
{
    if(a>=0 && b>=0 && maze[a][b]==1)
    {
        return true;
    }
    return false;
}

bool rat(int maze[N][N],int a,int b,int sol[N][N])
{
    if(a==N-1 && b==N-1 && maze[a][b]==1)
    {
        sol[a][b]=1;
        return true;
    }
    if(isSafe(maze,a,b)==true)
    {
        if(sol[a][b]==1)
        return false;

        sol[a][b]=1;

        if(rat(maze,a+1,b,sol)==true)
        return true;

        if(rat(maze,a,b+1,sol)==true)
        return true;

        sol[a][b]=0;
        return false;
    }
    return false;
}

void printArray(int sol[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        cout<<" "<<setw(2)<<sol[i][j]<<" ";
        cout<<endl;
    }

}

void solution(int maze[N][N])
{
    int sol[N][N]={ {0 ,0 ,0 ,0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0} };
    if(rat(maze,0,0,sol)==false)
    printf("Soltion does'nt Exist...");
    else
    printArray(sol);
}

int main()
{
    int maze[N][N]={  { 1, 0, 0, 0 },
                      { 1, 1, 0, 1 },
                      { 0, 1, 0, 0 },
                      { 1, 1, 1, 1 }  };
    solution(maze);
    return 0;
}