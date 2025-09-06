// We are given N ranges varies from Li to Ri on number line. Then you are given Q queries in form of ? Y, which means you have to return how many ranges passes through this points. Constraints N, Q <=1e5 Li, Ri, Y <=1e9

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int count_ranges(vector<int> &starts, vector<int> &ends, int Y)
{
    // Find the number of ranges that start at or before Y
    int start_count = starts.size() - (upper_bound(starts.begin(), starts.end(), Y) - starts.begin());

    // Find the number of ranges that ends before Y
    int end_count = (lower_bound(ends.begin(), ends.end(), Y) - ends.begin());

    // The number of ranges passing through Y is the overlap
    return (starts.size() - (start_count + end_count));
}

pair<int, int> arr[100001];
int B[100001];
void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int first, second;
        cin >> first >> second;

        arr[i] = {first, second};
    }

    sort(arr, arr + N);

    for (int i = 0; i < N; i++)
        B[i] = arr[i].second;
    sort(B, B + N);

    int Q;
    cin >> Q;
    while (Q--)
    {
        int Y;
        cin >> Y;

        auto it_li = upper_bound(arr, arr + N, make_pair(Y, LLONG_MAX));
        int cnt_li = (arr + N) - it_li;

        auto it_ri = lower_bound(B, B + N, Y);
        int cnt_ri = N - ((B + N) - it_ri);

        cout << (N - (cnt_li + cnt_ri)) << endl;
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