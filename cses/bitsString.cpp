#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926535897932384626
#define pb push_back
#define pp pop_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const unsigned int M = 1000000007;

ll findFactor(int b)
{
    if (!b)
        return 1;
    ll res = findFactor(b / 2);
    if (b & 1)
        return (2 * ((res * res * 1LL) % M)) % M;
    else
        return (res * res * 1LL) % M;
}
int main()
{
    int b;
    cin >> b;
    cout << findFactor(b) << endl;
    return 0;
}