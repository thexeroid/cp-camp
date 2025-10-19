#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int N;
    cin >> N;

    int subset_size = 1 << N;
    int arr[subset_size];

    for (int i = 0; i < subset_size; i++)
        cin >> arr[i];

    sort(arr, arr + subset_size);

    map<int, int> sum_mp;
    vector<int> subset_sums;

    for (int i = 1; i < subset_size; i++)
    {
        int el = arr[i];

        if (sum_mp.count(el))
        {
            int after_val = sum_mp[el]--;
            if (after_val == 0)
                sum_mp.erase(el);
        }
        else
        {
            cout << el << " ";
            int size_ss = subset_sums.size();
            for (int i = 0; i < size_ss; i++)
            {
                int pos_sum = el + subset_sums[i];
                sum_mp[pos_sum]++;

                subset_sums.push_back(pos_sum);
            }

            subset_sums.push_back(el);
        }
    }
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