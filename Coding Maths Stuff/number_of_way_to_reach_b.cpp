#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int mod = 1e9 + 7;

int mu(int a, int b)
{
    return (a * b) % mod;
}

int fact[100001];

void precompute()
{
    fact[0] = 1;

    for (int i = 1; i <= 1e5; i++)
    {
        fact[i] = mu(i, fact[i - 1]);
    }
}

int binpow(int base, int pow)
{
    int res = 1;
    while (pow > 0)
    {
        if (pow % 2 == 1)
        {
            res = (res * base) % mod;
        }

        pow >>= 1;
        base = (base * base) % mod;
    }

    return res;
}

int inv(int num)
{
    return binpow(num, mod - 2);
}

int C(int n, int r)
{
    return mu(fact[n], mu(inv(fact[r]), inv(fact[n - r])));
}

void solve()
{
    int N, M;
    cin >> N >> M;

    cout << C(N + M, M) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}