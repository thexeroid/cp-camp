/*
Description
You have to find the largest rectangular area possible in a given histogram where the largest rectangle can be made of contiguous bars. Assume that all bars have the same width, and the width is
1
1 unit.

Let
N
N be the number of bars and
H
i
H
i
​
  be the height of the
i
i-th bar. The rectangle must be formed by one or more contiguous bars, and its area is computed as the height of the shortest bar in the chosen range multiplied by the number of bars in that range.

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
H
i
H
i
​
  denotes the height of the
i
i-th bar.

Output Format
For each test case, print the largest area of the rectangle in the histogram.

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


1
≤
H
i
≤
1
0
5
1≤H
i
​
 ≤10
5


Where:

T
T is the number of test cases.
N
N is the number of bars in the histogram.
H
i
H
i
​
  is the height of the
i
i-th bar.
Sample Input 1
3
3
2 1 2
4
1 2 3 4
4
5 4 1 2
Sample Output 1
3
6
8
Note
For the first test case, the maximum rectangle is formed by taking all three bars with heights
[
2
,
1
,
2
]
[2,1,2]. The limiting (minimum) height is
1
1 and width is
3
3, so area =
1
×
3
=
3
1×3=3.
For the second test case, take the last two bars with heights
[
3
,
4
]
[3,4] (or the contiguous range giving area
6
6): the limiting height is
3
3 and width is
2
2, so area =
3
×
2
=
6
3×2=6.
For the third test case, take the first two bars with heights
[
5
,
4
]
[5,4]: the limiting height is
4
4 and width is
2
2, so area =
4
×
2
=
8
4×2=8.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define P pair<int, int>
#define F first
#define S second

P *getNSL(int *arr, int N)
{
    P *ans = new P[N];

    stack<P> stk;
    for (int i = 0; i < N; i++)
    {
        int el = arr[i];
        P nsl = {-1, -1};

        while (!stk.empty() && stk.top().S >= el)
            stk.pop();

        if (!stk.empty())
        {
            nsl = stk.top();
        }

        ans[i] = nsl;
        stk.push({i, el});
    }

    return ans;
}

P *getNSR(int *arr, int N)
{
    P *ans = new P[N];

    stack<P> stk;
    for (int i = N - 1; i >= 0; i--)
    {
        int el = arr[i];
        P nsr = {N, N};

        while (!stk.empty() && stk.top().S >= el)
            stk.pop();

        if (!stk.empty())
        {
            nsr = stk.top();
        }

        ans[i] = nsr;
        stk.push({i, el});
    }

    return ans;
}

void solve()
{
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    P *NSL = getNSL(arr, N);
    P *NSR = getNSR(arr, N);

    int maxArea = 0;
    for (int i = 0; i < N; i++)
    {
        int nsli = NSL[i].F;
        int nsri = NSR[i].F;

        int width = (nsri - nsli - 1);
        int breadth = arr[i];

        maxArea = max(maxArea, width * breadth);
    }

    cout << maxArea << endl;
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