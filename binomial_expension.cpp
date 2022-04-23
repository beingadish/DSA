#include <iostream>
using namespace std;

const int mod = 1009;
const int N = 1e5 + 10;
int f[N];

int power(int a, int n)
{
    int temp = 1;
    while (n)
    {
        if (n % 2)
        {
            temp = (temp * 1LL * a) % mod;
            n--;
        }
        else
        {
            a = (a * 1LL * a) % mod;
            n /= 2;
        }
    }
    return temp;
}

int C(int n, int k)
{
    if (k > n)
        return 0;
    int res = f[n];
    res = (res * power(f[k], mod - 2)) % mod;
    res = (res * power(f[n - k], mod - 2)) % mod;
    return res;
}

int main()
{
    f[0] = f[1] = 1;
    for (int i = 2; i < N; i++)
    {
        f[i] = (f[i - 1] * 1LL * i) % mod;
    }
    int t, n, k;
    cin >> t;
    while (t--)
    {

        cin >> n >> k;
        cout << C(n, k) << endl;
    }
    return 0;
}
