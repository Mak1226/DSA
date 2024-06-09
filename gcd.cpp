// GCD/HCF using the Euclidian Method
// Time Complexity = O[log to the base phi min(x,y)]

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    while (x > 0 && y > 0)
    {
        if (x > y)
            x = x % y;
        else
            y = y % x;
    }
    int res = (x == 0) ? y : x;
    cout << res;
}