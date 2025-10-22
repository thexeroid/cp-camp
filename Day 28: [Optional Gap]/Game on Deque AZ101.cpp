#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int N, Q;
    cin >> N >> Q;

    int mx = INT_MIN;
    deque<int> dq;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        dq.push_back(num);
        mx = max(mx, num);
    }

    pair<int, int> mp[N]{};
    int mp_size = 0;

    int op = 1;
    while (dq.front() != mx)
    {
        int first = dq.front();
        dq.pop_front();

        int second = dq.front();
        dq.pop_front();

        mp[op] = {first, second};
        mp_size++;

        dq.push_front(max(first, second));
        dq.push_back(min(first, second));

        op++;
    }

    vector<int> arr;

    dq.pop_front();

    while (!dq.empty())
    {
        arr.push_back(dq.front());
        dq.pop_front();
    }

    while (Q--)
    {
        int X;
        cin >> X;

        if (X <= mp_size)
        {
            pair<int, int> item = mp[X];
            cout << item.first << " " << item.second << endl;
        }
        else
        {
            X -= mp.size() + 1;
            X %= (N - 1);

            cout << mx << " " << arr[X] << endl;
        }
    }
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