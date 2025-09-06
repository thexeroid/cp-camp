#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
/*
    order_of_key (k)
    find_by_order(k)
*/

inline void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

inline void sub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += mod;
}

inline int mul(int a, int b)
{
    return (int)((long long)a * b % mod);
}

inline int power(int a, long long b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int inv(int a)
{
    a %= mod;
    if (a < 0)
        a += mod;
    int b = mod, u = 0, v = 1;
    while (a)
    {
        int t = b / a;
        b -= t * a;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    assert(b == 1);
    if (u < 0)
        u += mod;
    return u;
}

struct Mean
{
    int sum, cnt;

    Mean() : sum(0), cnt(0) {};

    void insert(int x)
    {
        add(sum, x);
        add(cnt, 1);
    }

    void remove(int x)
    {
        sub(sum, x);
        sub(cnt, 1);
    }

    int GetMean() const
    {
        if (!cnt)
            return -1;
        return mul(sum, inv(cnt));
    }
};

struct Mode
{
    set<pair<int, int>> s;
    map<int, int> M;

    void insert(int x)
    {
        M[x]++;
        if (M[x] > 1)
            s.erase(s.find({-(M[x] - 1), x}));
        s.insert({-M[x], x});
    }

    void remove(int x)
    {
        s.erase(s.find({-M[x], x}));
        M[x]--;
        if (M[x])
            s.insert({-M[x], x});
    }

    int GetMode()
    {
        if (s.empty())
            return -1;
        return s.begin()->second;
    }
};

struct Median
{
    ordered_set s;
    map<int, int> M;

    void insert(int x)
    {
        M[x]++;
        s.insert({x, M[x]});
    }

    void remove(int x)
    {
        s.erase(s.find({x, M[x]}));
        M[x]--;
    }

    int GetMedian()
    {
        if (s.empty())
            return -1;
        int n = (int)s.size();
        if (n % 2 == 0)
        {
            int sum = s.find_by_order(n / 2 - 1)->first;
            add(sum, s.find_by_order(n / 2)->first);
            return mul(sum, inv(2));
        }
        return s.find_by_order(n / 2)->first;
    }
};

signed main()
{
    // freopen("IN", "r", stdin);
    // freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int q;
        cin >> q;

        Mean mean;
        Mode mode;
        Median median;

        while (q--)
        {
            string s;
            cin >> s;

            if (s == "insert")
            {
                int x;
                cin >> x;
                mean.insert(x);
                mode.insert(x);
                median.insert(x);
            }
            else if (s == "remove")
            {
                int x;
                cin >> x;
                mean.remove(x);
                mode.remove(x);
                median.remove(x);
            }
            else if (s == "getMean")
            {
                cout << mean.GetMean() << "\n";
            }
            else if (s == "getMode")
            {
                cout << mode.GetMode() << "\n";
            }
            else if (s == "getMedian")
            {
                cout << median.GetMedian() << "\n";
            }
        }
    }
    return 0;
}
