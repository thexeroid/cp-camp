#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

string get_rotation(string &S, int rotation_num)
{
    int N = S.size();

    int start = rotation_num - 1;
    int end = start + N - 1;

    string ans;
    for (int i = start; i <= end; i++)
    {
        ans.push_back(S[i % N]);
    }

    return ans;
}

int get_operations_to_make_equal(string &A, string &B)
{
    int N = A.size();

    for (int i = 1; i <= N; i++)
    {
        string cr = get_rotation(A, i);

        if (cr == B)
        {
            return i - 1;
        }
    }

    return -1;
}

string arr[50];
void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int final_ans = INT_MAX;
    bool bl = false;
    for (int rn = 1; rn <= arr[0].size(); rn++)
    {
        string cr = get_rotation(arr[0], rn);
        // cout << "rotation num: " << rn << " current rotation: " << cr << endl;

        int curr_ans = 0;
        for (int i = 0; i < n; i++)
        {
            string str = arr[i];
            int cnt_ops = get_operations_to_make_equal(str, cr);
            // cout << "count operations: " << cnt_ops << " current rotation: " << cr << " str: " << str << endl;

            if (cnt_ops == -1)
            {
                bl = true;
                break;
            }
            else
            {
                curr_ans += cnt_ops;
            }
        }

        if (bl)
        {
            break;
        }

        final_ans = min(final_ans, curr_ans);
        // cout << "current rotation: " << cr << " final answer: " << final_ans << endl;
    }

    cout << (final_ans == INT_MAX ? -1 : final_ans) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}