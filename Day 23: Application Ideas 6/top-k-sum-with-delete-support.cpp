#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

class BlackBox
{
    multiset<int> front, back;
    int backSum;
    int K;

    void rebalance()
    {
        if (back.size() > K)
        {
            auto it = back.begin();
            int it_val = *it;

            back.erase(it);
            backSum -= it_val;

            front.insert(it_val);
        }

        if (!front.empty() && back.size() < K)
        {
            auto it = prev(front.end(), 1);
            int it_val = *it;

            front.erase(it);
            back.insert(it_val);
            backSum += it_val;
        }
    }

    void print()
    {
        cout << "FRONT:" << endl;
        for (auto it : front)
            cout << it << " ";

        cout << endl;

        cout << "BACK:" << endl;
        for (auto it : back)
            cout << it << " ";

        cout << endl;
    }

public:
    BlackBox(int K)
    {
        this->K = K;
        this->backSum = 0;
    }

    void insert(int num)
    {
        back.insert(num);
        backSum += num;

        rebalance();
    }

    void remove(int num)
    {
        auto front_it = front.find(num);
        if (front_it != front.end())
            front.erase(front_it);
        else
        {
            auto back_it = back.find(num);
            if (back_it != back.end())
            {
                back.erase(back_it);
                backSum -= num;
            }
        }

        rebalance();
    }

    int get_top_k_sum()
    {
        return backSum;
    }
};

void solve()
{
    BlackBox bb(3);

    cout << bb.get_top_k_sum() << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}