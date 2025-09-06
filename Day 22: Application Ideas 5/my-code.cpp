#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const auto cmp = [](pair<int, int> it1, pair<int, int> it2)
{
    if (it1.first != it2.first)
        return it1.first < it2.first;

    return it1.second > it2.second;
};

class BlackBox
{
private:
    int mod = 1e9 + 7;

    int binpow(int base, int pow)
    {
        int res = 1;

        while (pow > 0)
        {
            if (pow % 2 == 1)
            {
                res = (res * base) % mod;
            }

            pow >>= 1;
            base = (base * base) % mod;
        }

        return res;
    }

    int inv(int num)
    {
        return binpow(num, mod - 2);
    }

    // mean
    int sum;
    int total_els;

    // median
    multiset<int> left, right;

    // mode
    map<int, int> freq;
    multiset<pair<int, int>, decltype(cmp)> ms;

    bool is_empty()
    {
        return total_els == 0;
    }

public:
    BlackBox() : sum(0), total_els(0), ms(cmp) {}

    void rebalance()
    {
        if (left.size() + 1 < right.size())
        {
            auto it = right.begin();
            int it_val = *it;

            right.erase(it);
            left.insert(it_val);
        }

        if (left.size() > right.size())
        {
            auto it = prev(left.end(), 1);
            int it_val = *it;

            left.erase(it);
            right.insert(it_val);
        }
    }

    void insert(int el)
    {
        // mean
        sum += el;
        if (sum > mod)
            sum -= mod;
        total_els += 1;
        // total_els %= mod;

        // median
        if (right.empty())
        {
            right.insert(el);
        }
        else if (el >= *right.begin())
        {
            right.insert(el);
        }
        else
        {
            left.insert(el);
        }

        // mode
        int el_freq = freq[el];
        auto pair_it = ms.find({el_freq, el});
        if (pair_it != ms.end())
        {
            ms.erase(pair_it);
        }
        ms.insert({el_freq + 1, el});
        freq[el]++;

        rebalance();
    }

    void remove(int el)
    {
        sum -= el;
        if (sum < 0)
            sum += mod;

        total_els -= 1;

        auto it_left = left.find(el);
        if (it_left != left.end())
            left.erase(it_left);
        else
        {
            auto it_right = right.find(el);
            if (it_right != right.end())
                right.erase(it_right);
        }

        int el_freq = freq[el];
        auto pair_it = ms.find({el_freq, el});
        if (pair_it != ms.end())
        {
            ms.erase(pair_it);
            freq[el]--;
            el_freq--;
        }

        if (el_freq > 0)
        {
            ms.insert({el_freq, el});
        }
        else
            freq.erase(el);

        rebalance();
    }

    int getMean()
    {
        if (is_empty())
            return -1;

        return (sum * inv(total_els)) % mod;
    }

    int getMedian()
    {
        if (is_empty())
            return -1;

        if (total_els % 2 != 0)
        {
            return *right.begin();
        }
        else
        {
            int m1 = *left.rbegin();
            int m2 = *right.begin();

            return (((m1 + m2) % mod) * inv(2)) % mod;
        }
    }

    int getMode()
    {
        if (is_empty())
            return -1;

        return ms.rbegin()->second;
    }
};

void solve()
{
    BlackBox bb;
    int Q;
    cin >> Q;

    while (Q--)
    {
        string op;
        cin >> op;

        if (op == "insert")
        {
            int x;
            cin >> x;

            bb.insert(x);
        }

        if (op == "remove")
        {
            int x;
            cin >> x;

            bb.remove(x);
        }

        if (op == "getMean")
        {
            cout << bb.getMean() << endl;
        }

        if (op == "getMedian")
        {
            cout << bb.getMedian() << endl;
        }

        if (op == "getMode")
        {
            cout << bb.getMode() << endl;
        }
    }
};

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