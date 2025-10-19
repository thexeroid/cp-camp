#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int N, K;
    cin >> N >> K;

    map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        int el;
        cin >> el;

        mp[el]++;
    }

    priority_queue<int> pq;
    for (auto it : mp)
    {
        if (it.second > 1)
            pq.push(it.second);
    }

    while (K > 0 && !pq.empty())
    {
        int top = pq.top();
        pq.pop();

        top--;
        K--;

        if (top > 1)
            pq.push(top);
    }

    int incompatible_pairs = 0;
    while (!pq.empty())
    {
        int top = pq.top();
        pq.pop();

        incompatible_pairs += top * (top - 1) / 2;
    }

    int total_pairs = N * (N - 1) / 2;
    cout << (total_pairs - incompatible_pairs) << endl;
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