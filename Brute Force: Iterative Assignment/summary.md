## Q1. Pyramid

**Task:** Determine (C_X, C_Y, H).

**Description:**
Find pyramid center ((C_X, C_Y)) and height (H).

Altitude at (X,Y): max(H - |X - C_X| - |Y - C_Y|, 0)

Given:

- (N) points (x_i, y_i, h_i) with known altitude
- (0 <= x_i, y_i, C_X, C_Y <= 100)
- 0 <= hi <= 10^9
- (H >= 1)
- (1 <= N <= 100)
- Unique solution

**Key Insight:**
Since constraints are low, we can just brute-force over Cx, Cy and since (Cx, Cy, H) is unique,
we can iterate over all points and inject each Cx and Cy to find appropriate value of H.

Also, one more thing:
hi = {

> H - |xi - C_X| - |yi - C_Y|, H - |xi - C_X| - |yi - C_Y| > 0
> 0, H - |xi - C_X| - |yi - C_Y| <= 0

}

So, from this partwise function one thing is clear H exists only when
H - |xi - C_X| - |yi - C_Y| > 0
=> hi = H - |xi - C_X| - |yi - C_Y|, hi > 0
=> H = hi + |xi - C_X| + |yi - C_Y|, hi > 0

since, hi > 0 already H >=1 automatically
Thus,
we determine H and then, we test the pair (Cx, Cy, H) on every equation if they satisfy the value of all they win, if not we continue

Code:
[Solution](Pyramid.cpp)

---

## Q2:

**Task:**
Given integers n and m, count the number of non-negative integer pairs (a, b) such that:
a² + b = n
a + b² = m

Constraints:

- (0 <= a, b)
- (1 ≤ n, m ≤ 1000)

**Key Insight:**
If we can just brute-force over all a and b and check that it satisfies both equation then done.
But, we need to limit a and b to a range since, by constrainted they are not limited.

So, for that we find max value of a and b possible from both equations and then consider their intersection:
From Eqation 1:
a² + b = n

=> Given a = 0, a² + b = n => b = n => upper limit of b = 1000
=> Give b = 0, a² + b = n => a² = n => a = sqrt(n) = 31.6 => upper limit of a = 31

From Equation 2:
a + b² = m

=> Given a = 0, a + b² = m => b² = m => b = sqrt(m) = 31.6 => upper limit of b = 31
=> Give b = 0, a + b² = m => a = m => a = 1000 => upper limit of a = 1000

From both these equations, we know that:
a <= 31 && a <= 1000 => a <= 31
b <= 1000 && b <= 31 => b <= 31

so, 0 <= a, b <= 31 becomes the range.

Now, we can just merge both equations into one:
a² + b = n (i) => b = n - a²
a + b² = m (ii) =>

=> injecting value of b from (i) into (ii)
=> a + (n - a²)² = m

So, we already got, m and n and we will bruteforce from 0 to 31 for value of a and whatever makes
LHS = RHS would be our answer for
a and b will be derived from n and a.

- Also, b >= 0 in this case.

Code:
[Solution](System%20of%20Equations.cpp)

---

## Q3:

**Task:**
Given a binary array of length n, you must choose exactly one subarray [i, j] and flip all bits (0 ↔ 1).

Task:
After one flip, maximize the number of 1s in the array.

Input:
n (1 ≤ n ≤ 100)
a₁ … aₙ, where each aᵢ ∈ {0,1}

Output:
Maximum number of 1s obtainable after exactly one flip.

**Key Insight:**
It is solved based on contribution technique in general.
We count how many 1s are there in whole array and call it base.

Then, we store each item based on their contribution after operation
1 -> -1
0 -> +1

1 will lead to reduction by 1 and 0 will lead to increase by 1 upon inverting.

So, we store the array like that e.g.,
[1, 0, 1] => [-1, 1, -1]
Then we apply the kadene's algorithm to find the subarray of max sum = max gain

like this:
acc = 0
gain = INT_MIN
i: 0 -> N - 1

```cpp
    if (acc > 0) acc += arr[i]
    else acc = arr[i]

    gain = max(gain, acc);
```

Then we have max gain possible,
no we just print:
ans = base + gain

**Code:**
[Solution](Flipping_Game_v1.cpp)

---

## Q4: Network Mask

**Task:**
Problem:
Given n strings of equal length, you may repeatedly rotate any string left by 1
(move first character to the end).

Task:
Find the minimum total number of rotations needed to make all strings identical.
If impossible, print −1.

Constraints:
1 ≤ n ≤ 50
1 ≤ length of each string ≤ 50
All strings have equal length

**Key Insight:**

Mistakes to avoid / Lessons Learnt:

- Don't iterate over whole array only the array being used.
- We can shift octets directly.
- We can focus on a certain octet by using a number like 255.

pre-compute: ip -> number to reduce load

```
ans = "-1"
iterate over pos: 1 -> 31 {
    subnet_mask = (~0u) << (32 - pos);

    set<uint32_t> s;
    for every ip {
        network address = ip_number & subnet_mask
        s.insert(network address)
    }

    if (s.size() == k) {
        ans = subnet_mask;
        break;
    }
}
```

converting ip to number:

```
uint32_t convert_to_number(string &ip)
{
    int N = ip.size();

    uint32_t ans = 0;

    int s = 0;
    while (s < N)
    {
        int e = s;
        while (e < N && ip[e] != '.')
            e++;

        uint32_t octet = stoi(ip.substr(s, e - s));
        ans = (ans << 8) | octet;

        s = e + 1;
    }

    return ans;
}
```

converting number to ip:

```
string convert_to_ip(uint32_t num_ip)
{
    string ans;
    for (int co = 3; co >= 0; co--)
    {
        int octet = (num_ip >> (co * 8)) & 255;

        ans += to_string(octet);
        if (co > 0)
            ans += '.';
    }

    return ans;
}
```

[Solution](Network%20Mask.cpp)
