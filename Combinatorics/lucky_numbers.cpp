/*

The numbers of all offices in the new building of the Tax Office of IT City will have lucky numbers.

Lucky number is a number that consists of digits 7 and 8 only. Find the maximum number of offices in the new building of the Tax Office given that a door-plate can hold a number not longer than n digits.

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int power(int base, int exp)
{
    int res = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = (res * base);
        }

        exp >>= 1;
        base = (base * base);
    }

    return res;
}

void solve()
{
    int n;
    cin >> n;

    cout << power(2, n + 1) - 2 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}