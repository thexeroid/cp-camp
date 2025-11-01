#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    int B = 0;
    for (int i = 0; i < N; i++)
    {
        int book_pages;
        cin >> book_pages;

        if (B < book_pages)
        {
            pq.push(book_pages);
        }

        while (!pq.empty() && pq.top() < B)
            pq.pop();

        if (pq.size() > B)
            B++;

        cout << B << " ";
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