// Check Prime Number
// O(sqrt(n))

#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int x);
int main()
{
    int x;
    cin >> x;
    cout << checkPrime(x) << endl;
    return 0;
}
bool checkPrime(int x)
{
    int k = sqrt(x);
    for (int i = 2; i <= k; i++)
        if (x % i == 0)
            return false;
    return true;
}