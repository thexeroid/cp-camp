#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void perform_insertion(set<int> &cuts, multiset<int> &segments, int cut_pos)
{
    auto left = cuts.lower_bound(cut_pos);
    --left;
    auto right = cuts.upper_bound(cut_pos);

    int size_prev_segment = *right - *left;
    int size_curr_left_segment = cut_pos - *left;
    int size_curr_right_segment = *right - cut_pos;

    cuts.insert(cut_pos);

    auto it = segments.find(size_prev_segment);
    segments.erase(it);
    segments.insert(size_curr_left_segment);
    segments.insert(size_curr_right_segment);
}

void solve()
{
    int H, W, N;
    cin >> H >> W >> N;

    set<int> height_cuts = {0, H};
    set<int> width_cuts = {0, W};

    multiset<int> height_segments = {H};
    multiset<int> width_segments = {W};

    while (N--)
    {
        char ch;
        cin >> ch;

        if (ch == 'H')
        {
            int Y;
            cin >> Y;

            perform_insertion(height_cuts, height_segments, Y);
        }

        if (ch == 'V')
        {
            int X;
            cin >> X;

            perform_insertion(width_cuts, width_segments, X);
        }

        cout << *prev(height_segments.end(), 1) * *prev(width_segments.end(), 1) << endl;
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