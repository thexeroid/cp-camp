#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define P pair<int, int>
#define F first
#define S second

template <typename T>
void print(T num, bool space = true)
{
    cout << num;
    if (space)
        cout << " ";
}

// void print_stack(stack<P> stk, int step)
// {
//     string border = "----------";
//     cout << endl
//          << border << "STEP " << step << border << endl;
//     while (!stk.empty())
//     {
//         cout << stk.top().first << " " << stk.top().second;
//         stk.pop();
//     }
//     cout << endl
//          << border << endl;
// }

void solve()
{
    stack<P> stk;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        int ans = 0;
        if (!stk.empty())
        {
            while (!stk.empty() && stk.top().F >= num)
                stk.pop();

            if (!stk.empty())
                ans = stk.top().S;
        }

        print(ans, i != (N - 1));
        stk.push({num, i + 1});
    }

    print(endl, false);
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