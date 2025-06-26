#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

// TC: O(2^N), SC: O(N)
int recursive_derangement(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;

    return (n - 1) * (recursive_derangement(n - 1) + recursive_derangement(n - 2));
}

// TC: O(N), SC: O(N)
int arr[1000001];
int linear_derangment(int n)
{
    arr[0] = 1;
    arr[1] = 0;

    for (int i = 2; i < 1000001; i++)
    {
        arr[i] = (i - 1) * (arr[i - 1] + arr[i - 2]);
    }

    return arr[n];
}

// TC: O(N), SC: O(1)
int optimized_linear_derangment(int n)
{

    if (n == 0)
        return 1;
    if (n == 1)
        return 0;

    int first = 1;
    int second = 0;

    for (int i = 2; i <= n; i++)
    {
        int derangement = (i - 1) * (second + first);
        first = second;
        second = derangement;
    }

    return second;
}

void solve()
{
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}