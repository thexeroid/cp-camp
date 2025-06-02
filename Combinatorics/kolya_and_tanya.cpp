#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int mod = 1e9 + 7;

int pow(int base, int pow, int mod)
{
    int res = 1;

    while (pow > 0)
    {
        if (pow % 2 == 1)
        {
            res = (res * base) % mod;
        }

        base = (base * base) % mod;
        pow >>= 1;
    }

    return res;
}

void solve()
{
    int n;
    cin >> n;

    cout << (pow(3, 3 * n, mod) - pow(7, n, mod) + mod) % mod << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}