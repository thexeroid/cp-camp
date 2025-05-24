/*

Pashmak decided to give Parmida a pair of flowers from the garden. There are n flowers in the garden and the i-th of them has a beauty number bi. Parmida is a very strange girl so she doesn't want to have the two most beautiful flowers necessarily. She wants to have those pairs of flowers that their beauty difference is maximal possible!

Your task is to write a program which calculates two things:

The maximum beauty difference of flowers that Pashmak can give to Parmida.
The number of ways that Pashmak can pick the flowers. Two ways are considered different if and only if there is at least one flower that is chosen in the first way and not chosen in the second way.

2
1 1
Output
0 4
Answer
0 1

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin >> n;

    int max = 1, min = 1e9;
    map<int, int> mp{};
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        mp[num]++;

        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }

    int ways_to_pick = mp[max] * mp[min];
    if (min == max)
    {
        int tfc = mp[max];
        ways_to_pick = tfc * (tfc - 1) / 2;
    }

    cout << (max - min) << " " << ways_to_pick << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}