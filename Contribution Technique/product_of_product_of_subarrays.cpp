/*

Product(Product of all subarrays of array)

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int binpow(int base, int pow)
{
    int res = 1;
    while (pow > 0)
    {
        if (pow % 2 == 1)
            res *= base;

        pow >>= 1;
        base = (base * base);
    }

    return res;
}

int arr[100000];
void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 1, prev = 1;
    for (int i = 0; i < N; i++)
    {
        prev = prev * binpow(arr[i], i + 1);
        ans *= prev;
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