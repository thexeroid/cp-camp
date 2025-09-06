#include <bits/stdc++.h>
using namespace std;

int count_ranges(vector<int> &starts, vector<int> &ends, int Y)
{
    // Find the number of ranges that start at or before Y
    int start_count = starts.size() - (upper_bound(starts.begin(), starts.end(), Y) - starts.begin());

    // Find the number of ranges that ends before Y
    int end_count = (lower_bound(ends.begin(), ends.end(), Y) - ends.begin());

    // The number of ranges passing through Y is the overlap
    return (starts.size() - (start_count + end_count));
}

int main()
{
    vector<pair<int, int>> ranges = {{1, 5}, {3, 7}, {6, 9}, {8, 11}};
    vector<int> queries = {0, 3, 6, 8, 12};

    vector<int> starts, ends;
    for (const auto &range : ranges)
    {
        starts.push_back(range.first);
        ends.push_back(range.second);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    for (int Y : queries)
    {
        cout << count_ranges(starts, ends, Y) << endl;
    }
}
