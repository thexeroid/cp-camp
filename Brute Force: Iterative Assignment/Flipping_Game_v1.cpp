#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int arr[100];
void solve()
{
    int N;
    cin >> N;

    int base = 0;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        // Count the no. of 1s
        base += (num == 1);
        // transform based on contribution: the sum of subarray tells the number of 1s in that range.
        arr[i] = (num == 0 ? 1 : -1);
    }

    int acc = 0;
    int gain = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (acc > 0)
        {
            acc += arr[i];
        }
        else
        {
            acc = arr[i];
        }

        gain = max(gain, acc);
    }

    cout << base + gain << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}