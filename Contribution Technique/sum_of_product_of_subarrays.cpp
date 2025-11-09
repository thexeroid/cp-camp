/*
Sum(Product of all subarrays of array)
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int arr[100000];
void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 0, prev_sum = 0;
    for (int i = 0; i < N; i++)
    {
        prev_sum = arr[i] * (prev_sum + 1);
        ans += prev_sum;
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