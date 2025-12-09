Problem 1:

Platform: CodeForces
Problem: System of Equations

Technique: Basically, constraint engineering and all
like
a^2 + b = n (i)
a + b^2 = m (ii)

and 1 <= n, m <= 1000 and 0 <= a, b
we don't know the upper bound of a or b.
Let's find them.

Consider any equation, say (i)
1 <= n <= 1000
=> 1 <= a^2 + b <= 1000
=> 1 - b <= a^2 <= 1000 - b
Also, b >= 0 so, 1 - b could be negative to 1 as max value.
0 <= a^2 and for b = 1 too 1 - b would be 0 the lowest valid value of left is 0 then.

=> 0 <= a^2 <= 1000 - b
Also, the highest possible value of 1000 - b is 1000 when b = 0
So, 0 <= a^2 <= 1000
and the pairs would be (a, n - a^2) when n - a^2 >= 0

Code:

```cpp

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int a = 0; a < 32; a++)
    {
        int b = n - a * a;
        if ((b >= 0) && (a + b * b == m))
            ans++;
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

Insight 1:

Technique:

```
Two pointer works when moving a pointer gives a predictable contribution to a value like
always increase or remain same
always decrease or reamin same
something like that
```

Problem 2:

Platform: CodeForces
Problem:

```
A. Flipping Game
time limit per test1 second
memory limit per test256 megabytes
Iahub got bored, so he invented a game to be played on paper.

He writes n integers a1, a2, ..., an. Each of those integers can be either 0 or 1. He's allowed to do exactly one move: he chooses two indices i and j (1 ≤ i ≤ j ≤ n) and flips all values ak for which their positions are in range [i, j] (that is i ≤ k ≤ j). Flip the value of x means to apply operation x = 1 - x.

The goal of the game is that after exactly one move to obtain the maximum number of ones. Write a program to solve the little game of Iahub.

Input
The first line of the input contains an integer n (1 ≤ n ≤ 100). In the second line of the input there are n integers: a1, a2, ..., an. It is guaranteed that each of those n values is either 0 or 1.

Output
Print an integer — the maximal number of 1s that can be obtained after exactly one move.

Examples
InputCopy
5
1 0 0 1 0
OutputCopy
4
InputCopy
4
1 0 0 1
OutputCopy
4
Note
In the first case, flip the segment from 2 to 5 (i = 2, j = 5). That flip changes the sequence, it becomes: [1 1 1 0 1]. So, it contains four ones. There is no way to make the whole sequence equal to [1 1 1 1 1].

In the second case, flipping only the second and the third element (i = 2, j = 3) will turn all numbers into 1.
```

Key Idea:

```
We used a transformer and transformed each element to the it's contribution after the move.
Like, we mapped 0 -> +1 and 1 to -1

Now, we used kaden's algorithm which is:
If acc > 0 => acc += el else acc = el

to find max net contribution of the best segment.

We added it to the original one's count.
Also, the 1s falling in that best segment are taken care of due to multiple -1 addition so that ones from base will cancel them out and only ones - transformed from zero - will prevail.

That's it.

Also, this was because 1 move was mandatory if 0 moves were allowed for 1111 series it would be better to make ans = base + max(0LL, gain)
because if the best segment gives negative net contribution then, there's no best segment.
```

Solution:

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int arr[100];
void solve()
{
    int N;
    cin >> N;

    int base = 0;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        // Count the no. of 1s
        base += (num == 1);
        // transform based on contribution: the sum of subarray tells the number of 1s in that range.
        arr[i] = (num == 0 ? 1 : -1);
    }

    int acc = 0;
    int gain = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (acc > 0)
        {
            acc += arr[i];
        }
        else
        {
            acc = arr[i];
        }

        gain = max(gain, acc);
    }

    cout << base + gain << endl;
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
