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
    int n, num, prev;
    cin >> n;
    cin >> prev;
    ll moves = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> num;
        moves += ((num - prev) >= 0) ? 0 : abs(num - prev);
        prev = max(prev, num);
    }
    cout << moves << endl;
    return 0;
}