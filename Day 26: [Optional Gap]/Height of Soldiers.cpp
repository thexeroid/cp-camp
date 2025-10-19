#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define P pair<int, int>
#define F first
#define S second

P *getNSL(int *arr, int N)
{
    stack<P> stk;
    P *ans = new P[N];
    for (int i = 0; i < N; i++)
    {
        int el = arr[i];

        while (!stk.empty() && stk.top().S >= el)
        {
            stk.pop();
        }

        ans[i] = (!stk.empty() ? stk.top() : P{-1, -1});
        stk.push({i, el});
    }

    return ans;
}

P *getNSR(int *arr, int N)
{
    stack<P> stk;
    P *ans = new P[N];

    for (int i = N - 1; i >= 0; i--)
    {
        int el = arr[i];

        while (!stk.empty() && stk.top().S >= el)
        {
            stk.pop();
        }

        ans[i] = (!stk.empty() ? stk.top() : P{N, N});
        stk.push({i, el});
    }

    return ans;
}

void solve()
{
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    P *NSL = getNSL(arr, N);
    P *NSR = getNSR(arr, N);

    int ans[N]{};
    for (int i = 0; i < N; i++)
    {
        int max_segment_size_idx = NSR[i].F - NSL[i].F - 2;
        ans[max_segment_size_idx] = max(ans[max_segment_size_idx], arr[i]);
    }

    for (int i = N - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
    cout << endl;
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