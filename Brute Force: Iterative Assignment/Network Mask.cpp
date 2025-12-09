#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

signed convert_ip_to_32bit_integer(string &ip)
{
    int N = ip.size();

    signed ans = 0;
    int bit_pos = 31;

    int s = 0, e = 0;
    while (s < N)
    {
        while (e < N && ip[e] != '.')
            e++;

        int octet = stoi(ip.substr(s, e - s + 1));
        for (int i = 7; i >= 0; i--)
        {
            bool digit = (octet >> i) & 1;

            ans |= (digit << bit_pos);
            bit_pos--;
        }

        s = e + 1;
        e = s;
    }

    return ans;
}

string format_to_ip(signed signed_ip)
{
    int i = 0;
    signed octets[4];

    for (int bit_pos = 31; bit_pos >= 0; bit_pos -= 8)
    {
        signed curr_octet = 0;
        int curr_octet_bit_pos = 7;

        for (int d = 0; d <= 7; d++)
        {
            int ip_octet_bit_pos = (bit_pos - d);
            bool ip_octet_bit = signed_ip & (1 << ip_octet_bit_pos);

            curr_octet |= (ip_octet_bit << curr_octet_bit_pos);
            curr_octet_bit_pos--;
        }

        octets[i] = curr_octet;
        i++;
    }

    string ans;
    for (int i = 0; i < 4; i++)
    {
        string octet = to_string(octets[i]);
        ans += octet;

        if (i != 3)
            ans.push_back('.');
    }

    return ans;
}

pair<string, int> arr[100001];
void solve()
{
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].first;
        arr[i].second = convert_ip_to_32bit_integer(arr[i].first);
    }

    signed subnet_mask;

    string ans = "-1";
    for (int bit_pos = 31; bit_pos >= 1; bit_pos--)
    {
        subnet_mask = ~((1 << bit_pos) - 1);

        unordered_set<signed> s;
        signed network_mask;
        for (int i = 0; i < N; i++)
        {
            string ip = arr[i].first;

            signed signed_ip = arr[i].second;
            network_mask = signed_ip & subnet_mask;

            s.insert(network_mask);
        }

        if (s.size() == K)
        {
            ans = format_to_ip(subnet_mask);
            break;
        }
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