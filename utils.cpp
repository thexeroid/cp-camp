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

template <class T>
void print(T *arr, int N)
{
    cout << "[ ";
    for (int i = 0; i < N; i++)
    {
        T item = arr[i];
        cout << get<0>(item) << " " << get<1>(item) << " " << get<2>(item);
        if (i != N - 1)
            cout << ", ";
    }
    cout << " ]" << endl;
}

template <class T>
void out(string label, T val, bool newline = false)
{
    cout << label << ": " << val << "; ";
    if (newline)
        cout << endl;
}

template <class T>
void space(T val)
{
    cout << val << " ";
}