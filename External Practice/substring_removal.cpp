#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int mod = 998244353;

void solve()
{
    int n;
    string s;

    cin >> n >> s;

    int L = 0, R = 0;

    int i = 0;
    while (i < n && s[i] == s[0])
    {
        L++;
        i++;
    }

    i = n - 1;
    while (0 <= i && s[i] == s[n - 1])
    {
        R++;
        i--;
    }

    int ans;
    if (s[0] == s[n - 1])
    {
        ans = (((L + 1) % mod) * ((R + 1) % mod)) % mod;
    }
    else
    {
        ans = (L + R + 1) % mod;
    }

    cout << (ans + mod) % mod << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}