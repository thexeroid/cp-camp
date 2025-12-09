#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int arr[100000];
int PS[100000];
void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    PS[0] = arr[0];
    for (int i = 1; i < N; i++)
        PS[i] = PS[i - 1] + arr[i];

    int res = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            int subarr_sum = PS[j];
            if (i > 0)
            {
                subarr_sum = PS[j] - PS[i - 1];
            }

            res *= subarr_sum;
        }
    }

    cout << res << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}