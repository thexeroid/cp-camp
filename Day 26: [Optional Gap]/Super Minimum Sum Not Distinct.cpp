/*
It's abstract. Just that in case of multiple mins, we consider first of them as min.
Maybe I will understand it better later.
*/

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

P *getNSER(int *arr, int N)
{
    stack<P> stk;
    P *ans = new P[N];

    for (int i = N - 1; i >= 0; i--)
    {
        int el = arr[i];

        while (!stk.empty() && stk.top().S > el)
            stk.pop();

        P nser_el = {N, N};
        if (!stk.empty())
        {
            nser_el = stk.top();
        }

        ans[i] = nser_el;
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
    P *NSER = getNSER(arr, N);

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int el = arr[i];

        P nsl_el = NSL[i];
        P nser_el = NSER[i];

        int total_subarrs_with_el_as_min = (i - nsl_el.F) * (nser_el.F - i);

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