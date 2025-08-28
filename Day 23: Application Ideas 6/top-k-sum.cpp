/*
Implement a running top-k sum, where we can insert elements dynamically while maintaining the sum of the top k elements efficiently, we can modify the approach slightly.

We will use a min-heap to maintain the k largest elements. Additionally, we'll maintain a running sum of the top k elements encountered so far. Whenever we insert a new element into the min-heap, we'll add it to the running sum.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

class BlackBox
{
    priority_queue<int> pq;

    int K;
    int K_sum;

public:
    BlackBox(int K)
    {
        this->K = K;
        this->K_sum = 0;
    }

    void insert(int num)
    {
        K_sum += num;
        pq.push(-num);

        if (pq.size() > K)
        {
            int sm = -pq.top();
            K_sum -= sm;
            pq.pop();
        }
    }

    int get_top_K_sum()
    {
        return K_sum;
    }
};

void solve()
{
    BlackBox bb(3);
    bb.insert(2);
    bb.insert(1);
    bb.insert(5);
    bb.insert(4);
    bb.insert(3);

    cout << bb.get_top_K_sum() << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}