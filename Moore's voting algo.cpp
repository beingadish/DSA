#include <bits/stdc++.h>

using namespace std;

int find(int a[], int n)
{
    int count = 1;
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[max] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            max = i;
            count = 1;
        }
    }
    return a[max];
}

bool check(int a[], int n, int m)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == m)
            count++;
    }
    if (count > n / 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int ismajority(int a[], int n)
{
    int m = find(a, n);

    if (check(a, n, m))
        cout << m << " is the majority Element" << endl;
    else
        cout << "Majority element doesn't exist" << endl;
}

void main()
{
    int arr[] = {1, 6, 9, 1, 1, 6, 1, 8, 1};
    int n = (sizeof(arr)) / sizeof(arr[0]);

    ismajority(arr, n);

}