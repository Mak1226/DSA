#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926535897932384626
#define pb push_back
#define pp pop_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const unsigned int M = 1000000007;
int main()
{
    ll n;
    cin >> n;
    while (n > 1)
    {
        cout << n << " ";
        n = (n & 1) ? 3 * n + 1 : n / 2;
    }
    cout << n << endl;
    return 0;
}