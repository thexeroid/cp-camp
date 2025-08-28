// Try to do it this way some time:
// keeping left.size() = right.size() or left.size() + 1 = right.size()

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

class BlackBox
{
    multiset<int> front, back;
    int frontSum = 0, backSum = 0;

    void rebalance()
    {
        if (front.size() + 1 < back.size())
        {
            auto it = back.begin();
            int it_val = *it;
            back.erase(it);
            backSum -= it_val;
            front.insert(it_val);
            frontSum += it_val;
        }

        if (front.size() > back.size())
        {
            auto it = prev(front.end(), 1);
            int it_val = *it;
            front.erase(it);
            frontSum -= it_val;
            back.insert(it_val);
            backSum += it_val;
        }
    }

    int getMedian()
    {
        return *back.begin();
    }

public:
    void insert(int num)
    {
        if (back.empty())
        {
            back.insert(num);
            backSum += num;
        }
        else if (num >= *back.begin())
        {
            back.insert(num);
            backSum += num;
        }
        else
        {
            front.insert(num);
            frontSum += num;
        }

        rebalance();
    }

    void remove(int num)
    {
        auto back_it = back.find(num);
        if (back_it != back.end())
        {
            back.erase(back_it);
            backSum -= num;
        }
        else
        {
            auto front_it = front.find(num);
            if (front_it != front.end())
            {
                front.erase(front_it);
                frontSum -= num;
            }
        }

        rebalance();
    }

    int getCost()
    {
        int median = getMedian();
        int frontSize = front.size();
        int backSize = back.size();

        return (median * frontSize - frontSum) + (backSum - median * backSize);
    }
};

void solve()
{
    int N, K;
    cin >> N >> K;

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    // Solution starts here
    BlackBox bb;
    for (int i = 0; i < N; i++)
    {
        bb.insert(arr[i]);
        if (i >= K)
        {
            bb.remove(arr[i - K]);
        }

        if (i >= K - 1)
        {
            cout << bb.getCost() << " ";
        }
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}