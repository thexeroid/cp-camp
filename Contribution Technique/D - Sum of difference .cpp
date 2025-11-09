/*
Note to me:
WTF man! I wasn't able to even get it man.

This is a fucking question where order is for deceiving users and order doesn't matter due to the nature of the function being abs - symmetric.

Question:

Time Limit: 2 sec / Memory Limit: 1024 MiB

Score :
400 points

Problem Statement
Given are
N integers
A
1
​
 ,…,A
N
​
 .

Find the sum of
∣A
i
​
 −A
j
​
 ∣ over all pairs
i,j such that
1≤i<j≤N.

In other words, find
i=1
∑
N−1
​

j=i+1
∑
N
​
 ∣A
i
​
 −A
j
​
 ∣.

Constraints
2≤N≤2×10
5

∣A
i
​
 ∣≤10
8

A
i
​
  is an integer.

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int arr[200000];
void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    int first_part = 0;
    for (int j = 2; j <= N; j++)
        first_part += (j - 1) * arr[j - 1];

    int second_part = 0;
    for (int i = 1; i <= N - 1; i++)
        second_part += (N - i) * arr[i - 1];

    cout << first_part - second_part << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}