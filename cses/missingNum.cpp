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
    int xor1 = 0, xor2 = 0;
    int n, num;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> num;
        xor2 ^= num;
        xor1 ^= i;
    }
    xor1 ^= n;
    cout << (xor1 ^ xor2) << endl;
    return 0;
}