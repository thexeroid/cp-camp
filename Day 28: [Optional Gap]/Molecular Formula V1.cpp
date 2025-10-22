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
    if (s >= N)
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

void solve()
{
    string S;
    cin >> S;

    int N = S.size();

    stack<pair<string, int>> stk;

    int i = 0;
    while (i < N)
    {
        if (is_upper_alpha(S[i])) // average O(1)
        {
            auto [el, cnt, temp] = get_nearest_el(S, i);
            stk.push({el, cnt});

            i = temp;
        }
        else if (is_starting_brace(S[i])) // O(1)
        {
            stk.push({"(", -1});
            i++;
        }
        else if (is_ending_brace(S[i])) // O(D)
        {
            i++;

            int multiple = 0;
            while (i < N && is_digit(S[i]))
            {
                multiple = multiple * 10 + (S[i] - '0');
                i++;
            }
            multiple = max(1LL, multiple);

            stack<pair<string, int>> temp;
            while (!stk.empty() && stk.top().first != "(")
            {
                auto it = stk.top();
                stk.pop();

                temp.push({it.first, it.second * multiple});
            }

            if (!stk.empty())
                stk.pop();

            while (!temp.empty())
            {
                auto it = temp.top();
                temp.pop();

                stk.push(it);
            }
        }
    }

    map<string, int> mp;
    while (!stk.empty())
    {
        auto it = stk.top();
        stk.pop();

        mp[it.first] += it.second;
    }

    for (auto [key, val] : mp)
    {
        cout << key;
        if (val > 1)
            cout << val;
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