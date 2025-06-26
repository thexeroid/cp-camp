#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int mod = 1e9 + 7;

int derangement(int n, int mod)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;

    int d_n_minus_2 = 1;
    int d_n_minus_1 = 0;

    for (int i = 2; i <= n; i++)
    {
        int derangement_i = ((i - 1) * ((d_n_minus_1 + d_n_minus_2) % mod)) % mod;
        d_n_minus_2 = d_n_minus_1;
        d_n_minus_1 = derangement_i;
    }

    return d_n_minus_1;
}

void solve()
{
    int n;
    cin >> n;

    cout << derangement(n, mod) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}