/*
Failed attempt.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int arr[100];
int PS[100];

int get_one_count(int l, int r, int N)
{
    if (l > r)
        return 0;
    if (r >= N)
        return 0;
    if (l < 0)
        return 0;

    if (l == 0)
        return PS[r];
    return PS[r] - PS[l - 1];
}

void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    PS[0] = (arr[0] == 1);
    for (int i = 1; i < N; i++)
    {
        PS[i] = PS[i - 1] + (arr[i] == 1);
    }

    int ans = 0;

    int left = 0, right = N - 1;

    int left_ones = 0, right_ones = 0;
    while (left < N && arr[left] != 0)
    {
        left++;
        left_ones++;
    }

    while (right >= 0 && arr[right] != 0)
    {
        right--;
        right_ones++;
    }

    while (left <= right)
    {
        int len = (right - left + 1);
        int one_count = get_one_count(left, right, N);
        int new_one_count = len - one_count;

        if (new_one_count > one_count)
        {
            ans = max(ans, new_one_count + left_ones + right_ones);
        }

        int t_left = left + 1;
        int t_left_one = 0;
        while (t_left < N && arr[t_left] != 0)
        {
            t_left_one++;
            t_left++;
        }

        int t_right = right - 1;
        int t_right_one = 0;
        while (t_right >= 0 && arr[t_right] != 0)
        {
            t_right_one++;
            t_right--;
        }

        if (t_left <= t_right)
        {
            int net_left_move_gain = (right - t_left + 1) - get_one_count(t_left, right, N);
            int net_right_move_gain = (t_right - left + 1, N) - get_one_count(left, t_right, N);

            if (net_left_move_gain > net_right_move_gain)
            {
                left = t_left;
                left_ones += t_left_one;
            }
            else
            {
                right = t_right;
                right_ones += t_right_one;
            }
        }
        else
            break;
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