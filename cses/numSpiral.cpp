#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926535897932384626
#define pb push_back
#define pp pop_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const unsigned int M = 1000000007;

void displayValue()
{
    ll int x, y;
    cin >> x >> y;
    ll int element;
    if (x >= y)
    {
        ll int row_elem = x & 1 ? ((x - 1) * (x - 1)) + 1 : x * x;
        ll int val = x & 1 ? y - 1 : -y + 1;
        element = row_elem + val;
    }
    else
    {
        ll int row_elem = y & 1 ? y * y : ((y - 1) * (y - 1)) + 1;
        ll int val = y & 1 ? -x + 1 : x - 1;
        element = row_elem + val;
    }
    cout << element << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        displayValue();
    return 0;
}