#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    set<char> mem;
    for (int i = 0; i < k; i++)
    {
        char ch;
        cin >> ch;

        mem.insert(ch);
    }

    int ans = 0;

    int i = 0;
    int counter = 0;
    while (i < n)
    {
        char ch = s[i];

        if (mem.find(ch) != mem.end())
        {
            counter++;
        }
        else
        {
            ans += counter * (counter + 1) / 2;
            counter = 0;
        }

        i++;

        if (i == n)
        {
            ans += counter * (counter + 1) / 2;
            counter = 0;
        }
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