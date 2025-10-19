#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const T &item, string message = "")
{
    cout << "START PRINTING: " << message << endl;
    for (auto it : item)
        cout << it << " ";
    cout << endl;
    cout << "END PRINTING: " << message << endl;
};