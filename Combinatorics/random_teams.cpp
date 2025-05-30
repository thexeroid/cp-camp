#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

// int C(int n, int r)
// {
//     if (n < r)
//         return 0;
//     if (n == r)
//         return 1;

//     return n * C(n - 1, r) / (n - r);
// }

int nC2(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;

    return n * (n - 1) / 2;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int k_max = nC2(n - m + 1);

    int base = n / m;
    int rem = n % m;

    int k_min = rem * nC2(base + 1) + (m - rem) * nC2(base);

    cout << k_min << " " << k_max << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}