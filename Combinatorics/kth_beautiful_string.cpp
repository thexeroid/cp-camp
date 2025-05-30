#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin >> n >> k;

    int target_term = n * (n - 1) / 2 - k + 1;
    string ans(n, 'a');

    for (int i = 0; i < n - 1; i++)
    {
        if (target_term <= (n - i - 1))
        {
            int j = target_term + i;
            ans[i] = 'b';
            ans[j] = 'b';
            break;
        }
        else
        {
            target_term -= (n - i - 1);
        }
    }

    cout << ans << endl;
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