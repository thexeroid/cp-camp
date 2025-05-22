#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int pow(int base, int exp, int mod)
{
    int res = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % mod;
        }

        exp >>= 1;
        base = (base * base) % mod;
    }

    return res;
}

int inv(int num, int mod)
{
    return pow(num, mod - 2, mod);
}

int compute(int a, char op, int b, int p)
{
    if (op == '+')
        return (a + b) % p;
    if (op == '-')
        return (a - b) % p;
    if (op == '*')
        return (a * b) % p;
    if (op == '/')
        return (a * inv(b, p)) % p;

    return -1;
}

map<char, int> precedence = {
    {'+', 0},
    {'-', 0},
    {'*', 1},
    {'/', 1}};

string getType(char ch)
{
    if ('0' <= ch && ch <= '9')
    {
        return "digit";
    }
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return "operator";
    }
    else if (ch == ' ')
        return "space";
    else
        return "else";
}

pair<int, int> readNum(string &s, int idx)
{
    int N = s.size();

    int num = 0;

    int i = idx;
    while (i < N && getType(s[i]) == "digit")
    {
        int digit = s[i] - '0';
        num = num * 10 + digit;

        i++;
    }

    return {
        num,
        i - 1};
}

void solve()
{
    int arr[7]{};
    int m = 0;

    string str;
    cin >> str;

    int N = str.size();
    int i = 0;

    while (i < N)
    {
        char ch = str[i];

        if (getType(ch) == "digit")
        {
            auto [num, end_idx] = readNum(str, i);
            arr[m] = num;
            i = end_idx;
        }
        else if (getType(ch) == "operator")
        {
            arr[m] = signed(ch);
        }
        else if (getType(ch) == "space")
        {
            m++;
        }

        i++;
    }

    int a = arr[0];
    int b = arr[2];
    int c = arr[4];
    int p = arr[6];

    char op1 = arr[1];
    char op2 = arr[3];

    // cout << a << " " << b << " " << c << " " << p << " " << endl;
    cout << op1 << " " << endl;

    // cout << a << ' ' << b << ' ' << c << ' ' << p << ' ' << op1 << ' ' << op2 << ' ' << endl;

    // if (precedence[op2] > precedence[op1]) {
    //     cout << compute(a, op1, compute(b, op2, c, p), p) << endl;
    // } else {
    //     cout << compute(compute(a, op1, b, p), op2, c, p) << endl;
    // }
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