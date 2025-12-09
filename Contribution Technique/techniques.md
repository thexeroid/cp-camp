Problem 1:

Platform: Leetcode
Problem: total-appeal-of-a-string

Technique: You find the atomic item whose contribution is to be counted. It can be single el, pair, triplet, etc.
Technique is same as counting the contribution of X in all substrings.
You find every char is present in all substrings how many times.

Code:

```cpp
#define ll long long

class Solution {
public:
    ll appealSum(string s) {
        ll N = s.size();

        ll ans = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            ll ch_ans = N * (N + 1) / 2;

            ll last = -1;

            for (int i = 0; i < N; i++) {
                if (s[i] == ch) {
                    ll len = i - last - 1;
                    ch_ans -= len * (len + 1) / 2;

                    last = i;
                }
            }

            ch_ans -= (N - last - 1) * (N - last) / 2;
            ans += ch_ans;
        }

        return ans;
    }
};
```

---

Problem 2:
Platform: AlgoZenith
Problem: Sum(Sum(All Subarrays))

Technique: starting bars \* (multiply) ending bars count. Count how many subarrays will arr[i] be present in using (i + 1) \* (N - i) and then, just find contribution of arr[i] = arr[i] \* (i + 1) \* (N - i)
Add for all i's and you get your answer.

```cpp
/*
Sum of all subarrays of array

Main idea: starting bars * ending ends for each el = contribution of each el and then sum it up.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int arr[100000];
void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int left = (i + 1);
        int right = (N - i);

        ans += arr[i] * (left * right);
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}

```

---

Problem 3:
Platform: AlgoZenith
Problem(Sum(Product(All Subarrays)))

Technique: Building up the sum(product(all subarrays)) ending at i using
sum(product(all subarrays)) ending at (i - 1) and adding it up together.
prev_sum = arr[i] \* (prev_sum + 1);
ans += prev_sum;

```cpp
/*
Sum(Product of all subarrays of array)
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int arr[100000];
void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 0, prev_sum = 0;
    for (int i = 0; i < N; i++)
    {
        prev_sum = arr[i] * (prev_sum + 1);
        ans += prev_sum;
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
```

---

Problem 4:

Platform: AlgoZenith
Problem: Product(Product(All Subarrays))

Technique: Building up Product(Product(Subarrays)) ending at i using
Product(Product(Subarrays)) ending at (i - 1)
Like, ans = 1, prev = 1
prev = prev \* pow(arr[i], i + 1)
ans = ans \* prev

```cpp
/*

Product(Product of all subarrays of array)

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int binpow(int base, int pow)
{
    int res = 1;
    while (pow > 0)
    {
        if (pow % 2 == 1)
            res *= base;

        pow >>= 1;
        base = (base * base);
    }

    return res;
}

int arr[100000];
void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 1, prev = 1;
    for (int i = 0; i < N; i++)
    {
        prev = prev * binpow(arr[i], i + 1);
        ans *= prev;
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
```

---

Problem 5:

Platform: AtCoder
Problem: D - Sum of Difference

Technique: The question tricks you into assuming that order matters.
But, since, the function is f(x, y) = |x - y| it doesn't matter if the value of x and y are interchanged.
So, what happens is even though the question wants that i < j then, too it doesn't matter as |arr[i] - arr[j]| = |arr[j] - arr[i]| so, we can sort it.

Sorting in ascending order will make sure that |arr[i] - arr[j]| = (arr[j] - arr[i]) for i < j.

So, now the question becomes sum(all pair diffs (i, j)) = sum(arr[j] - arr[i], for all pairs i < j)

=> sum(arr[j]) - sum(arr[i])
sum(arr[j]) = arr[j] \* j (for j: 1 -> N - 1)
sum(arr[i]) = arr[i] \* (N - i - 1) (for i: 0 -> N - 2)

ans = arr[j] \* j - arr[i] \* (N - i - 1)

```cpp
/*
Note to me:
WTF man! I wasn't able to even get it man.

This is a fucking question where order is for deceiving users and order doesn't matter due to the nature of the function being abs - symmetric.

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
    for (int j = 1; j < N; j++)
        first_part += (j) * arr[j];

    int second_part = 0;
    for (int i = 0; i < N - 1; i++)
        second_part += (N - i - 1) * arr[i];

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
```

---

Problem 6:

Platform: AlgoZenith
Problem: Count Distinct Char in Substrings

Technique: Just we had to rephrase the problem.
We had to count distinct char in strings = we had to count no. of distinct chars present in substring and add it up for all strings. In other words, if a char is present in a substring despite the frequency of it, the contribution of that char in that substring would be 1 only.

So, we compute for every char, it's contribution in all substrings = we compute in how many substrings the char is present.

```cpp
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
```

---

Problem 7:

Platform: AlgoZenith
Problem: Count Unique Char in Substrings

Technique: For every char we just extend the left and right boundary to find the largest len in which that char is the only character.

Where the previous value of left and right is the place where the character occurred.
Left = i - left;
Right = right - i;

Left \* Right is the substrings count where the char is the unique char.
We add it up for all occurrences of that particular char.

```cpp
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
```

---

Problem 8:

Platform: AlgoZenith
Problem: No. of inverses count. Inverses = pair such as (i, j) such that arr[i] > arr[j] and i < j

Technique: no. of inverses in all subarray of an array. It was an O(N^2) solution where we iterated over all pairs and then just computed the contribution using bar method like stretch the left bar to start and stretch the right bar to the end. Count the subarrays in which that particular pair exists.

Like the atom = pair

---

Problem 9:

Platform: AlgoZenith
Problem: Sum of subsequences of an array

Technique:
Changed POV to contribution of each element in all subsequences.
Fix the element and do other combinations.
Contribution of an element becomes = el \* 2^(N - 1)
Total sum becomes = sigma(el \* 2^(N - 1))

---

Problem 10:

Platform: AlgoZenith
Problem: Product(Sum(Subarrays))

Technique: BS technique man use prefix sum to store subarr sum and literally multiply. Lol.

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int arr[100000];
int PS[100000];
void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    PS[0] = arr[0];
    for (int i = 1; i < N; i++)
        PS[i] = PS[i - 1] + arr[i];

    int res = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            int subarr_sum = PS[j];
            if (i > 0)
            {
                subarr_sum = PS[j] - PS[i - 1];
            }

            res *= subarr_sum;
        }
    }

    cout << res << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
```
