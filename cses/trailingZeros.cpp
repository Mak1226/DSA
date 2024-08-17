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
    int n;
    cin >> n;
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;
    cout << count << endl;
    return 0;
}