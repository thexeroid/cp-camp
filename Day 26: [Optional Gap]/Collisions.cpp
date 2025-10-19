#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int N, M;
    cin >> N >> M;

    map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        int pos_x, speed_x;
        cin >> pos_x >> speed_x;

        mp[pos_x * speed_x]++;
    }

    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        int pos_y, speed_y;
        cin >> pos_y >> speed_y;

        int target = pos_y * speed_y;
        auto it = mp.find(target);
        if (it != mp.end())
        {
            int freq = it->second;
            if (freq > 0)
            {
                mp[target]--;
                freq--;
                ans++;
            }
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