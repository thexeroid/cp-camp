#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int N;
    cin >> N;

    unordered_map<int, int> mp;
    int B = 0;
    int books_with_greater_than_B_pages = 0;

    for (int i = 0; i < N; i++)
    {
        int curr_book_pages;
        cin >> curr_book_pages;

        mp[curr_book_pages]++;
        if (curr_book_pages > B)
            books_with_greater_than_B_pages++;

        while (books_with_greater_than_B_pages > B)
        {
            B++;
            books_with_greater_than_B_pages -= mp[B];
        }

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