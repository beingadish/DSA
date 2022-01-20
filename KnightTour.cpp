#include <bits/stdc++.h>
#include <conio.h>
#define N 8
using namespace std;

int printChess(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << " " << setw(2) << sol[i][j] << "";
        }
        cout << endl;
    }
}

bool isSafe(int a, int b, int sol[N][N])
{
    if (a >= 0 && b >= 0 && a < N && b < N && sol[a][b] == -1)
        return true;
    else
        return false;
}

int knightout(int r, int c, int movei, int sol[N][N], int rowMove[8], int colMove[8])
{
    int a, b;

    if (movei == N * N)//here we are checking if we have reached the last position of chess
        return 1;

    for (int i = 0; i < 8; i++)
    {
        a = r + rowMove[i];//next row
        b = c + colMove[i];//next column

        if (isSafe(a, b, sol))
        {
            sol[a][b] = movei;
            if (knightout(a, b, movei + 1, sol, rowMove, colMove) == 1)
                return 1;
            else
                sol[a][b] = -1;//back tracking
        }
    }
    return 0;
}

int solution()
{
    int sol[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            sol[i][j] = -1;
    }

    int rowMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int colMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

    sol[0][0] = 0;

    if (knightout(0, 0, 1, sol, rowMove, colMove) == 0)
    {
        printf("Solution is not possible...");
        return 0;
    }
    else
        printChess(sol);

    return 1;
}

int main()
{
    solution();
    return 0;
}