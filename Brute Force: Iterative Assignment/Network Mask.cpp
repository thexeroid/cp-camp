// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl "\n"

// signed convert_ip_to_32bit_integer(string &ip)
// {
//     int N = ip.size();

//     signed ans = 0;
//     int bit_pos = 31;

//     int s = 0, e = 0;
//     while (s < N)
//     {
//         while (e < N && ip[e] != '.')
//             e++;

//         int octet = stoi(ip.substr(s, e - s + 1));
//         for (int i = 7; i >= 0; i--)
//         {
//             bool digit = (octet >> i) & 1;

//             ans |= (digit << bit_pos);
//             bit_pos--;
//         }

//         s = e + 1;
//         e = s;
//     }

//     return ans;
// }

// string format_to_ip(signed signed_ip)
// {
//     int i = 0;
//     signed octets[4];

//     for (int bit_pos = 31; bit_pos >= 0; bit_pos -= 8)
//     {
//         signed curr_octet = 0;
//         int curr_octet_bit_pos = 7;

//         for (int d = 0; d <= 7; d++)
//         {
//             int ip_octet_bit_pos = (bit_pos - d);
//             bool ip_octet_bit = signed_ip & (1 << ip_octet_bit_pos);

//             curr_octet |= (ip_octet_bit << curr_octet_bit_pos);
//             curr_octet_bit_pos--;
//         }

//         octets[i] = curr_octet;
//         i++;
//     }

//     string ans;
//     for (int i = 0; i < 4; i++)
//     {
//         string octet = to_string(octets[i]);
//         ans += octet;

//         if (i != 3)
//             ans.push_back('.');
//     }

//     return ans;
// }

// pair<string, int> arr[100001];
// void solve()
// {
//     int N, K;
//     cin >> N >> K;

//     for (int i = 0; i < N; i++)
//     {
//         cin >> arr[i].first;
//         arr[i].second = convert_ip_to_32bit_integer(arr[i].first);
//     }

//     signed subnet_mask;

//     string ans = "-1";
//     for (int bit_pos = 31; bit_pos >= 1; bit_pos--)
//     {
//         subnet_mask = ~((1 << bit_pos) - 1);

//         unordered_set<signed> s;
//         signed network_mask;
//         for (int i = 0; i < N; i++)
//         {
//             string ip = arr[i].first;

//             signed signed_ip = arr[i].second;
//             network_mask = signed_ip & subnet_mask;

//             s.insert(network_mask);
//         }

//         if (s.size() == K)
//         {
//             ans = format_to_ip(subnet_mask);
//             break;
//         }
//     }

//     cout << ans << endl;
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

template <typename T>
void print(string label, const T &t, bool endline = false)
{
    cout << label << " " << t << "; ";
    if (endline)
        cout << endl;
}

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

pair<string, uint32_t> arr[100001];
void solve()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = convert_to_number(arr[i].first);
    }

    string ans = "-1";
    for (int pos = 1; pos <= 31; pos++)
    {
        uint32_t subnet_mask = (~0u) << (32 - pos);

        set<uint32_t> s;
        for (int i = 0; i < n; i++)
        {
            uint32_t network_address = arr[i].second & subnet_mask;
            s.insert(network_address);
        }

        if (s.size() == k)
        {
            ans = convert_to_ip(subnet_mask);
            break;
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}