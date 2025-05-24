#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    string s;
    cin >> s;

    int ch1 = s[0], ch2 = s[1];

    int fp = (ch1 - 'a') * 25;
    int sp = (ch2 - 'a');
    if (ch1 > ch2)
    {
        sp += 1;
    }

    cout << (fp + sp) << endl;
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