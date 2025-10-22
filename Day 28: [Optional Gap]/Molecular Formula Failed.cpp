#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool is_lower_alpha(char ch)
{
    return 'a' <= ch && ch <= 'z';
}

bool is_upper_alpha(char ch)
{
    return 'A' <= ch && ch <= 'Z';
}

bool is_digit(char ch)
{
    return '0' <= ch && ch <= '9';
}

bool is_starting_brace(char ch) { return ch == '('; }
bool is_ending_brace(char ch) { return ch == ')'; }

tuple<string, int, int> get_nearest_el(string &S, int s)
{
    int N = S.size();
    if (s > N)
        return {"", 0, N};

    string el_name(1, S[s]);
    int i = s + 1;
    while (i < N && is_lower_alpha(S[i]))
    {
        el_name.push_back(S[i]);
        i++;
    }

    int count = 0;
    while (i < N && (is_digit(S[i])))
    {
        count = count * 10 + (S[i] - '0');
        i++;
    }

    return {el_name, (max(1LL, count)), i};
}

pair<int, int> read_nearest_num(string &S, int s)
{
    int N = S.size();

    int num = 0;
    int i = s;
    while (i < N && is_digit(S[i]))
    {
        num = num * 10 + (S[i] - '0');
        i++;
    }

    return {num, i};
}

map<string, int> multiply_compound(string &S, int s, int e, int factor = 1)
{
    int N = S.size();
    if (s >= N || e >= N)
        return {};

    map<string, int> mp;
    int i = s;
    while (i <= e)
    {
        if (is_starting_brace(S[i]))
        {
            int copy_e = e;
            while (s <= copy_e && !is_ending_brace(S[copy_e]))
                copy_e--;
            pair<int, int> p = read_nearest_num(S, copy_e + 1);
            int num = p.first;

            map<string, int> temp = multiply_compound(S, i + 1, copy_e - 1, num);
            for (auto pair : temp)
                mp[pair.first] += pair.second;
            i = p.second;

            continue;
        }

        tuple<string, int, int> nearest_el = get_nearest_el(S, i);
        string el = get<0>(nearest_el);
        int cnt = get<1>(nearest_el);
        i = get<2>(nearest_el);

        mp[el] += cnt;
    }

    for (auto pair : mp)
    {
        mp[pair.first] *= factor;
    }

    return mp;
}

void solve()
{
    string S;
    cin >> S;

    map<string, int> res = multiply_compound(S, 0, S.size() - 1);
    for (auto pair : res)
    {
        cout << pair.first << pair.second << endl;
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