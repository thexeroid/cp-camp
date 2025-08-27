/*
This problem is slightly differnt from learning.cpp's problem:

The problem:
Description
You have an empty array and can perform the following operations on it:

insert x - add integer x to the array
remove x - remove integer x from the array. It's guaranteed the element present in it.
getMean - find the mean of elements currently presents in the array.
getMedian - find the median of elements currently present in the array,  if the count of the numbers is even, take the average of the two middle elements.
getMode - find the mode of elements currently present in the array, if there is more than one potential element, assume that the mode is the smaller of all.
If the array is empty at the point a query is asked about a metric(mean, median, mode), print -1.

If any of the answers for the query is a fraction, let's say, P / Q in reduced form, the return the number (P*Q-1) Modulo 1000000007.

You have an empty array and can perform the following operations on it:

insert x - Add integer
x
x to the array.
remove x - Remove integer
x
x from the array.

It is guaranteed that the element is present in the array.
getMean - Find the mean of elements currently present in the array.
getMedian - Find the median of elements currently present in the array.

If the count of the numbers is even, take the average of the two middle elements.
getMode - Find the mode of elements currently present in the array.

If there is more than one potential mode, assume the mode is the smallest of all.
If the array is empty at the point a query is asked about a metric (mean, median, or mode), print -1.

If any of the answers for the query is a fraction, let's say,
P
Q
Q
P
​
  in reduced form, return the number:

(
P
×
Q
−
1
)
m
o
d
 
 
1000000007
(P×Q
−1
 )mod1000000007

where
Q
−
1
Q
−1
  is the modular multiplicative inverse of
Q
Q modulo
1000000007
1000000007.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer Q - the number of queries.
Each of the next Q lines contains a string S and integer X or just a string S - description of the query.

Output Format
For each test case, print the answer for the queries.

Constraints
1
≤
T
≤
1
0
5
1≤T≤10
5


1
≤
Q
≤
1
0
5
1≤Q≤10
5


1
≤
x
≤
1
0
9
1≤x≤10
9


It is guaranteed that the sum of
Q
Q over all test cases does not exceed
1
0
5
10
5
 .

Sample Input 1
1
12
insert 4
insert 3
insert 5
getMean
getMedian
getMode
insert 4
remove 3
insert 5
getMean
getMedian
getMode
Sample Output 1
4
4
3
500000008
500000008
4
Note
Array becomes: [4]
Array becomes [3, 4]
Array becomes [3, 4, 5]
Mean = (3+4+5) / 3 = 4
Median = 4 (middle element)
Mode = 3 (since it is smallest in value)
Array becomes [3, 4, 4, 5]
Array becomes [4, 4, 5]
Array becomes [4, 4, 5, 5]
Mean = (4+4+5+5)/4 = 4.5 (=500000008 in mod domain)
Median = (4+5)/2 = 4.5 (average of the two middle elements)
Mode = 4 (since it is smallest in value)

*/

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

const auto cmp = [](auto x, auto y)
{
    if (x.first != y.first)
        return x.first < y.first;
    else
        return x.second > y.second;
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
    int sum = 0;
    int total_els = 0;

    // median
    multiset<int> left, right;

    // mode
    map<int, int> mp;
    multiset<pair<int, int>, decltype(cmp)> ms{cmp};

    bool is_empty()
    {
        return total_els == 0;
    }

public:
    void balance()
    {
        while (left.size() < right.size())
        {
            auto it = right.begin();
            left.insert(*it);
            right.erase(it);
        }

        while (left.size() > right.size() + 1)
        {
            auto it = prev(left.end());
            right.insert(*it);
            left.erase(it);
        }
    }

    void insert(int el)
    {
        sum += el;
        total_els += 1;

        int freq = mp[el];
        auto existing_it = ms.find(make_pair(freq, el));
        if (existing_it != ms.end())
        {
            ms.erase(existing_it);
        }
        mp[el]++;
        freq++;
        ms.insert(make_pair(freq, el));

        if (left.empty())
        {
            left.insert(el);
        }
        else if (el <= *left.rbegin())
        {
            left.insert(el);
        }
        else
        {
            right.insert(el);
        }

        balance();
    }

    void remove(int el)
    {
        auto existing_it = mp.find(el);
        if (existing_it != mp.end())
        {
            sum -= el;
            total_els -= 1;

            int freq = existing_it->second;

            auto ms_it = ms.find(make_pair(freq, el));
            if (ms_it != ms.end())
            {
                ms.erase(ms_it);
            }

            mp[el]--;
            freq--;
            if (freq <= 0)
            {
                mp.erase(existing_it);
            }
            else
                ms.insert(make_pair(freq, el));

            auto left_it = left.find(el);
            if (left_it != left.end())
            {
                left.erase(left_it);
            }
            else
            {
                auto right_it = right.find(el);
                if (right_it != right.end())
                {
                    right.erase(right_it);
                }
            }

            balance();
        }
    }

    int getMean()
    {
        if (is_empty())
            return -1;

        int num = sum;
        int den = total_els;

        int ans = (num * inv(den)) % mod;

        return (ans + mod) % mod;
    }

    int getMedian()
    {
        if (is_empty())
            return -1;

        int ans;
        if ((left.size() + right.size()) % 2)
        {
            ans = *left.rbegin();
        }
        else
        {
            int num = (*left.rbegin() + *right.begin()) % mod;
            int den = 2;

            ans = (num * inv(den)) % mod;
        }

        return (ans + mod) % mod;
    }

    int getMode()
    {
        if (is_empty())
            return -1;

        int ans = (ms.rbegin()->second) % mod;
        return (ans + mod) % mod;
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