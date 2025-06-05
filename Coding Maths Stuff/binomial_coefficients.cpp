#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int mod = 1e9 + 7;

int mem[1000001];

void precompute()
{
    mem[0] = 1;

    for (int i = 1; i <= 1e6; i++)
    {
        mem[i] = (mem[i - 1] * i) % mod;
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

void solve()
{
    int a, b;
    cin >> a >> b;

    cout << (((mem[a] * inv(mem[b])) % mod) * inv(mem[a - b])) % mod << endl;
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