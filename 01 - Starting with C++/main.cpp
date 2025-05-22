#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define endl "\n"

void playingWithOperators()
{
    int a = 10000000000, b = 10;
    cout << "**-- Arithmetic operators --**" << '\n';
    cout << "The value of a + b is " << a + b << '\n';
    cout << "The value of a - b is " << a - b << '\n';
    cout << "The value of a * b is " << a * b << '\n';
    cout << "The value of a / b is " << a / b << '\n';
    cout << "The value of a % b is " << a % b << '\n';
}

void playingWithDataTypes()
{
    double x;
    cin >> x;
    cout << fixed << setprecision(2);
    /*. FIXED-> means everything next happens for after the floating point part only.
  setprecision(2) -> Now on, every print will happen with roundoff to 2 decimal places. */
    cout << x << '\n'; // will print the number.
}

void pattern1(int rows, int cols)
{
    /*
        ****
        ****
        ****

        ROWS = 3
        COLS = 4
    */

    for (int i = 0; i < rows; i++)
    {
        string stars = "";
        for (int j = 0; j < cols; j++)
        {
            stars += '*';
        }

        cout << stars << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // pattern1(3, 4);

    // playingWithOperators();

    playingWithDataTypes();

    return 0;
}