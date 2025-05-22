#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int power(int base, int exponent, int mod)
{
    if (exponent == 0)
        return 1;
    if (base == 0)
        return 0;

    int half = power(base, exponent / 2, mod);

    int ans = (half * half) % mod;
    if (exponent % 2 == 1)
        ans = (ans * base) % mod;

    return ans;
}

void solve()
{
    int a, b;
    cin >> a >> b;

    cout << power(a, b, 1e9 + 7) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
}