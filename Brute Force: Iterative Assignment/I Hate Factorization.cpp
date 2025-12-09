#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int binpow(int base, int pow)
{
    int ans = 1;
    while (pow != 0)
    {
        if (pow % 2 == 1)
        {
            ans *= base;
        }

        pow >>= 1;
        base *= base;
    }

    return ans;
}

void solve()
{
    int X;
    cin >> X;

    map<int, int> mp;
    for (int num = -119; num <= 119; num++)
    {
        int num_pow_five = binpow(num, 5);
        mp[num_pow_five] = num;
    }

    for (int a = -118; a <= 119; a++)
    {
        int a_pow_5 = binpow(a, 5);
        int b_pow_5 = a_pow_5 - X;

        if (mp.count(b_pow_5))
        {
            cout << a << " " << mp[b_pow_5];
            break;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}