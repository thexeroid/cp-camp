#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int mod = 1e9;
int mem[1000][1000]{};

void precompute()
{
    // nCr = (n - 1)C(r) + (n - 1)C(r - 1)
    mem[0][0] = 1;

    for (int i = 1; i < 1000; i++)
    {
        mem[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            mem[i][j] = (mem[i - 1][j - 1] + mem[i - 1][j]) % mod;
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        cout << mem[n][i];
        if (i != n)
            cout << " ";
    }

    cout << endl;
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