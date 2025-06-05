// The key was to view it as compartment of 4 points and then, in a compartment there would be 2 intersecting diags or 1 pair of intersecting diagonals and no. of ways to choose a compartment = NC4 * 1 = NC4

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int mod = 1e9 + 7;

int binpow(int base, int exp)
{
    int res = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % mod;
        }

        exp >>= 1;
        base = (base * base) % mod;
    }

    return res;
}

int inv(int num)
{
    return binpow(num, mod - 2);
}

int multiply(int *nums, int N)
{
    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        ans = (ans * nums[i]) % mod;
    }

    return ans;
}

void solve()
{
    int N;
    cin >> N;

    int int_res[] = {
        N,
        N - 1,
        N - 2,
        N - 3,
        inv(24)};
    cout << multiply(int_res, 5) << endl;
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