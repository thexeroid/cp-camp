#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int compute_ideal(int k, int n)
{
    return (n * n - 2 * n * k + 3 * n - 3 * k + k * k + 2) / 2;
}

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    int temps[n];
    for (int i = 0; i < n; i++)
    {
        cin >> temps[i];
    }

    // Main Logic
    int ans = 0;

    int i = 0;
    int counter = 0;

    while (i < n)
    {
        bool computed_bool = (temps[i] <= q);

        if (computed_bool)
        {
            counter++;
        }
        else
        {
            if (k <= counter)
            {
                ans += compute_ideal(k, counter);
            }
            counter = 0;
        }

        i++;

        if (i == n && k <= counter)
        {
            ans += compute_ideal(k, counter);
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