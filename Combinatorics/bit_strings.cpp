/*

Your task is to calculate the number of bit strings of length n.
For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.


*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int power(int base, int exp, int mod)
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

void solve()
{
    int N;
    cin >> N;

    cout << power(2, N, 1e9 + 7) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}