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
            stk.pop();

        P nsl_el = {-1, -1};
        if (!stk.empty())
        {
            nsl_el = stk.top();
        }

        ans[i] = nsl_el;
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
            stk.pop();

        P nsr_el = {N, N};
        if (!stk.empty())
        {
            nsr_el = stk.top();
        }

        ans[i] = nsr_el;
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

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int el = arr[i];

        P nsl_el = NSL[i];
        P nsr_el = NSR[i];

        int total_subarrs_with_el_as_min = (i - nsl_el.F) * (nsr_el.F - i);

        ans += el * total_subarrs_with_el_as_min;
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