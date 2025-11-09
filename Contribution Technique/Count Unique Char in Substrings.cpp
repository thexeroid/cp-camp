/*

SELF SOLVED.

Key Idea:
1. Change POV to a alphabet is unique in how many substrings.
2. Do it for all alphabets.
3. For that to happen, monitor left and right boundaries for each char and expand the boundaries before another char both sides.
4. Then inside the boundary, all substrings will have that char only once.
5. Do it for all boundaries for that char.
6. Sum it up.
7. That's it, do it for all chars and it's done.

Count Unique Char in Substrings
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
N. The score of a string is the number of unique characters present in the string (characters which are present only once in the string). For example the score of the string "character" is
3
3 because the characters
h
h,
t
t, and
e
e appear exactly once.

Find the sum of the score of all substrings of
S
S.

Input Format
The first line contains
T
T, the number of test cases
(
1
≤
T
≤
10
)
(1≤T≤10).
The first line of each test case contains an integer
N
N, the size of the string,
(
1
≤
N
≤
1
0
5
)
(1≤N≤10
5
 ).
The second line of each test case contains a string
S
S of length
N
N.

Output Format
For each test case print the sum of the score of all substrings of
S
S in a new line.

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
        int ch_contri = 0;

        int left = -1;
        int i = 0;
        while (i < N && S[i] != ch)
            i++;

        while (i < N)
        {
            int right = i + 1;
            while (right < N && S[right] != ch)
                right++;

            int options_left = i - left;
            int options_right = right - i;

            ch_contri += options_left * options_right;

            left = i;
            i = right;
        }

        ans += ch_contri;
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