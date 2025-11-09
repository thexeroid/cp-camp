/*
Sum of all subarrays of array

Main idea: starting bars * ending ends for each el = contribution of each el and then sum it up.
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
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}