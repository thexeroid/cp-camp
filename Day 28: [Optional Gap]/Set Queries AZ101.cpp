/*
This solution uses **two ordered sets**:

* `s` — to store the integers that are currently present in the set.
* `ns` — to store candidate integers that are **not present** but could be the next missing integers.

  * When we insert `x` into `s`, we also consider inserting `x + 1` into `ns`, **unless `x + 1` is already present in `s`**.

**Query handling:**

1. **Type 1 `x` (insert `x`)**:

* Insert `x` into `s`.
   * Remove `x` from `ns` if it exists.
   * If `x + 1` is not already in `s`, insert `x + 1` into `ns`.

2. **Type 2 `x` (find next missing ≥ `x`)**:

   * If `x` is not in `s`, then `x` itself is the answer.
   * Otherwise, the answer is the **smallest element in `ns` that is ≥ `x`** (found via `lower_bound` / ceiling).

> **Why it works:** Consecutive present numbers collapse the candidates in `ns` to the **next missing integer**, so you can always efficiently jump to the next free number.

---

**Complexity:**

* **Time Complexity per test case:** `O(Q log Q)`
* **Space Complexity per test case:** `O(Q)`
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int Q;
    cin >> Q;

    set<int> p, np;
    while (Q--)
    {
        int op, val;
        cin >> op >> val;

        if (op == 1)
        {
            if (np.count(val))
                np.erase(val);

            p.insert(val);

            if (!p.count(val + 1))
                np.insert(val + 1);
        }

        if (op == 2)
        {
            int ans;
            if (!p.count(val))
                ans = val;
            else
                ans = *np.lower_bound(val);

            cout << ans << endl;
        }
    }
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