Problem: https://leetcode.com/problems/total-appeal-of-a-string/description/

Technique: You find the atomic item whose contribution is to be counted. It can be single el, pair, triplet, etc.

The common things you do with it are:

1. Sum(Sum(Subarray))
2. Sum(Product(Subarray))
3. Product(Sum(Subarray))

```cpp

```

4. Product(Product(Subarray))
5. The count of subarrays containing X (like below) = total subarrays - the count of subarrays not containing X

Solution:

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

Some more techniques were there like:

1. no. of inverses in all subarray of an array. It was an O(N^2) solution where we iterated over all pairs and then just computed the contribution using bar method like stretch the left bar to start and stretch the right bar to the end. Count the possibilities

2. sum of subsequences of an array - contribution of each element in all subsequences.
   Changed POV.
   Same here. Like, fix the element and do other combinations and all.
   Contribution of an element becomes = el _ 2^(N - 1)
   Total sum becomes = sigma(el _ 2^(N - 1))
