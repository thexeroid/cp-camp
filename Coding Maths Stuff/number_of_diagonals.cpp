#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int mod = 1e9 + 7;

int inv(int num)
{
    int base = num, pow = mod - 2;
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

void solve()
{
    int N;
    cin >> N;

    cout << ((N * (N - 3) % mod) * inv(2)) % mod << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}