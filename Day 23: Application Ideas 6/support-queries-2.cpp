#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

//---- Debugger ---- //
#define debarr(a, n)            \
    cout << #a << " : ";        \
    for (int i = 0; i < n; i++) \
        cout << a[i] << " ";    \
    cout << endl;
#define debmat(mat, row, col)         \
    cout << #mat << " :\n";           \
    for (int i = 0; i < row; i++)     \
    {                                 \
        for (int j = 0; j < col; j++) \
            cout << mat[i][j] << " "; \
        cout << endl;                 \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const unordered_set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
void dbs(string str, T t) { cout << str << " : " << t << "\n"; }
template <class T, class... S>
void dbs(string str, T t, S... s)
{
    int idx = str.find(',');
    cout << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}
template <class T>
void prc(T a, T b)
{
    cout << "[";
    for (T i = a; i != b; ++i)
    {
        if (i != a)
            cout << ", ";
        cout << *i;
    }
    cout << "]\n";
}
int binpow(int b, int p, int mod)
{
    int ans = 1;
    b %= mod;
    for (; p; p >>= 1)
    {
        if (p & 1)
            ans = ans * b % mod;
        b = b * b % mod;
    }
    return ans;
}
//----------------- //

class BlackBox
{
    int K;
    multiset<int> front, back;
    int backSum;

    void rearrange()
    {
        if (back.size() > K)
        {
            auto it = back.begin();
            int it_num = *it;

            back.erase(it);
            backSum -= it_num;
            front.insert(it_num);
        }

        if (!front.empty() && back.size() < K)
        {
            auto it = prev(front.end(), 1);
            int it_num = *it;

            front.erase(it);
            back.insert(it_num);
            backSum += it_num;
        }
    }

public:
    BlackBox(int K)
    {
        this->K = K;
        this->backSum = 0;
    }

    void add(int num)
    {
        back.insert(num);
        backSum += num;

        rearrange();
    }

    void remove(int num)
    {
        auto front_it = front.find(num);

        if (front_it != front.end())
        {
            front.erase(front_it);
        }
        else
        {
            auto back_it = back.find(num);
            int back_it_num = *back_it;

            if (back_it != back.end())
            {
                back.erase(back_it);
                backSum -= back_it_num;
            }
        }

        rearrange();
    }

    int get_top_K_sum()
    {
        return backSum;
    }
};

void solve()
{
    int Q, K;
    cin >> Q >> K;

    BlackBox bb(K);
    while (Q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int x;
            cin >> x;

            bb.add(x);
        }

        if (op == 2)
        {
            int x;
            cin >> x;

            bb.remove(x);
        }

        if (op == 3)
        {
            cout << bb.get_top_K_sum() << endl;
        }
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