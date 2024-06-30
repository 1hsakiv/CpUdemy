// https://codeforces.com/contest/633/problem/A
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    for (int x = 0; x * a <= c; x++)
    {
        int y = c - a * x;
        if (y % b != 0)
            continue;
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}