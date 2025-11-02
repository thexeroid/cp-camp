/*

An **O(N)** solution is possible if we keep track of the frequency of each page count using a frequency array.

**Approach:**

1. Initialize:

   * ( B = 0 )
   * `countGreater = 0` — the number of books with pages greater than the current ( B ).

2. For each book read:

   * Increase the frequency of the number of pages for that book.
   * If the book’s page count is greater than the current ( B ), increment `countGreater`.
   * If `countGreater > B`, then increment ( B ) by 1.
   * After increasing ( B ), decrease `countGreater` by the frequency of books that have exactly ( B ) pages (since those no longer count as “greater than B”).

**Time Complexity per test case:**
O(N)

----------------------------------------
i = 0
|
2 1 4 4





----------------------------------------


*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
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