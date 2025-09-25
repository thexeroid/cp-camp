/*
Description
You are given an array
A
A, where each
i
ith index represents an elevation on that index. The width of each bar is
1
1. You have to compute how much water it is able to trap after raining.

Input Format
The first line of the input contains one integer
T
T - the number of test cases. Then
T
T test cases follow.
The first line of each test case contains one integer
N
N - the length of the array.
The second line of each test case contains
N
N space-separated integers, where
A
i
A
i
​
  denotes the height of the
i
t
h
i
th
  bar.

Output Format
For each test case, print how much water it is able to trap after raining.

Constraints
1
≤
T
≤
100
1≤T≤100
1
≤
N
≤
1
0
5
1≤N≤10
5

0
≤
A
i
≤
1
0
5
0≤A
i
​
 ≤10
5

It's guaranteed that the sum of
N
N over all test cases is at most
1
0
5
10
5
 .

Sample Input 1
3
3
3 0 2
5
2 0 0 4 3
5
1 2 3 1 5
Sample Output 1
2
4
2
Note
For the first test case the elevations are
[
3
,
0
,
2
]
[3,0,2]. Water trapped above the middle bar is
min
⁡
(
3
,
2
)
−
0
=
2
min(3,2)−0=2, so total trapped water is
2
2. For the second test case the trapped water amounts to
4
4. For the third test case the total trapped water is
2
2.

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define P pair<int, int>
#define F first
#define S second

P *getMGL(int *arr, int N)
{
    stack<P> stk;
    P *ans = new P[N];

    for (int i = 0; i < N; i++)
    {
        int el = arr[i];
        while (!stk.empty() && stk.top().S <= el)
        {
            stk.pop();
        }

        P mgl = {-1, -1};
        if (!stk.empty())
        {
            mgl = stk.top();
        }

        ans[i] = mgl;
        if (stk.empty())
        {
            stk.push({i, el});
        }
    }

    return ans;
}

P *getMGR(int *arr, int N)
{
    stack<P> stk;
    P *ans = new P[N];

    for (int i = N - 1; i >= 0; i--)
    {
        int el = arr[i];

        while (!stk.empty() && stk.top().S <= el)
        {
            stk.pop();
        }

        P mgr = {-1, -1};
        if (!stk.empty())
        {
            mgr = stk.top();
        }

        ans[i] = mgr;
        if (stk.empty())
            stk.push({i, el});
    }

    return ans;
}

void solve()
{
    int N;
    cin >> N;

    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    P *MGL = getMGL(arr, N);
    P *MGR = getMGR(arr, N);

    int acc = 0;
    for (int i = 0; i < N; i++)
    {
        int el = arr[i];

        int water = min({MGL[i].S, MGR[i].S}) - el;

        if (water > 0)
            acc += water;
    }

    cout << acc << endl;
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