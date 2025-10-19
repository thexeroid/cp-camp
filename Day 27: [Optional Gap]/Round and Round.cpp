#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define P pair<int, int>
#define F first
#define S second

int get_rotated_dir(int current_dir, char relative_rotation_dir)
{
    int N = 4;

    if (relative_rotation_dir == 'L')
        current_dir -= 1;
    if (relative_rotation_dir == 'R')
        current_dir += 1;

    current_dir = (current_dir + N) % N;

    return current_dir;
}

P move(P current_pos, int current_dir)
{
    P ans = current_pos;
    if (current_dir == 0)
        ans.S--;
    if (current_dir == 1)
        ans.F--;
    if (current_dir == 2)
        ans.S++;
    if (current_dir == 3)
        ans.F++;

    return ans;
}

void solve()
{
    int N;
    cin >> N;

    string S;
    cin >> S;

    P ans = {0, 0};
    int dir = 2;
    for (int i = 0; i < 4 * N; i++)
    {
        if (op == 'W')
        {
            ans = move(ans, dir);
        }
        else if (op == 'L')
        {
            dir = get_rotated_dir(dir, 'L');
        }
        else
        {
            dir = get_rotated_dir(dir, 'R');
        }
    }

    cout << (ans == make_pair(0LL, 0LL) || dir != 2 ? "YES" : "NO") << endl;
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