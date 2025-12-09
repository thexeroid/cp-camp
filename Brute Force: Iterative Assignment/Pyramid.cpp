#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

template <class T>
void label(string label, T val, bool newline = false)
{
    cout << label << ": ";
    cout << val << "; ";
    if (newline)
        cout << endl;
}

template <class T>
void space(T val, bool newline = false)
{
    cout << val << " ";
    if (newline)
        cout << endl;
}

tuple<int, int, int> points[101];
void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        tuple<int, int, int> item;
        cin >> get<0>(item) >> get<1>(item) >> get<2>(item);

        points[i] = item;
    }

    bool found = false;
    for (int Cx = 0; Cx <= 100; Cx++)
    {
        for (int Cy = 0; Cy <= 100; Cy++)
        {
            int H = -1;
            for (int i = 0; i < N; i++)
            {
                auto [xi, yi, hi] = points[i];

                if (hi > 0)
                {
                    H = hi + llabs(xi - Cx) + llabs(yi - Cy);
                    break;
                }
            }

            if (H == -1)
                continue;

            bool pass = true;
            for (int i = 0; i < N; i++)
            {
                auto [xi, yi, hi] = points[i];

                int computed_hi = max(H - llabs(xi - Cx) - llabs(yi - Cy), 0LL);
                if (hi != computed_hi)
                {
                    pass = false;
                    break;
                }
            }

            if (pass)
            {
                space(Cx);
                space(Cy);
                space(H, true);
                found = true;
                break;
            }
        }

        if (found)
            break;
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