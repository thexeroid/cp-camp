/*

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int a = 0; a < 32; a++)
    {
        int b = n - a * a;
        if ((b >= 0) && (a + b * b == m))
            ans++;
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}