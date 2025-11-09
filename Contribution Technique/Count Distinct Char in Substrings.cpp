/*
Key Idea: Question rephrasing. See the question as
1. It is really a matter of if any alphabet is present in string or not, their frequency is irrelevant.
2. So instead of counting per string, let's count per alphabet. Diff POV.
3. So for each alphabet, we count in how many substrings they are present or not.


Count Distinct Char in Substrings
Solved

Time Limit :
2 sec
Memory Limit :
512000 MB
Description
Given a string
S
S consisting of lowercase characters of length
N
N. The score of a string is the number of distinct characters present in the string. For example, the score of "character" is
6
6.

Find the sum of the scores of all substrings of
S
S.

Input Format
The first line contains
T
T, the number of test cases (
1
≤
T
≤
10
1≤T≤10).
Each test case consists of two lines:
The first line contains an integer
N
N (
1
≤
N
≤
1
0
5
1≤N≤10
5
 ), the size of the string.
The second line contains a string
S
S of length
N
N. It's guaranteed that the sum of
N
N over all test cases does not exceed
1
0
5
10
5
 .
Output Format
For each test case, print the sum of the scores of all substrings of
S
S.

Constraints
1
≤
T
≤
10
1≤T≤10
1
≤
N
≤
1
0
5
1≤N≤10
5

Sum of
N
N over all test cases does not exceed
1
0
5
10
5
 .
Sample Input 1
5
2
ac
3
aac
5
abode
5
aaaaa
10
jdnbfjdhzw
Sample Output 1
4
8
35
15
207
Note
For the first test case:
Substrings and scores:

("a", 1)
("c", 1)
("ac", 2) Total score =
1
+
1
+
2
=
4
1+1+2=4
For the second test case:
Substrings and scores:

("a", 1)
("a", 1)
("c", 1)
("aa", 1)
("ac", 2)
("aac", 2) Total score =
1
+
1
+
1
+
1
+
2
+
2
=
8
1+1+1+1+2+2=8
00:00:00
282930313233343536
    return 0;
}
Test Case 1


ACCEPTED
Input
5
2
ac
3
aac
5
abode
5
aaaaa
10
jdnbfjdhzw
Output
4
8
35
15
207

Desired Output
4
8
35
15
207


ACCEPTED







*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int last = -1;
        int ch_contrib = N * (N + 1) / 2;
        for (int i = 0; i < N; i++)
        {
            if (S[i] == ch)
            {
                int len = i - last - 1;
                ch_contrib -= len * (len + 1) / 2;

                last = i;
            }
        }

        int len = N - last - 1;
        ch_contrib -= len * (len + 1) / 2;

        ans += ch_contrib;
    }

    cout << ans << endl;
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