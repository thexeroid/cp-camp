#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int mod = 1e9 + 7;

int binpow(int base, int pow, int mod)
{
    int res = 1;
    while (pow != 0)
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

void solve()
{
    int k;
    cin >> k;

    int pow = (binpow(2, k, mod - 1) - 2) % (mod - 1);
    int base = 4;

    int res = (binpow(base, pow, mod) * 6) % mod;

    cout << (res + mod) % mod << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}