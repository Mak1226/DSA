#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926535897932384626
#define pb push_back
#define pp pop_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const unsigned int M = 1000000007;
void display(vector<int> &s1, vector<int> &s2)
{
    cout << s1.size() << endl;
    for (int it : s1)
        cout << it << " ";
    cout << endl;
    cout << s2.size() << endl;
    for (int it : s2)
        cout << it << " ";
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    if ((n % 4 == 1) || (n % 4 == 2))
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<int> s1, s2;

    if (n % 2)
    {
        s2.push_back(n--);
        for (int i = 1; i <= n / 2; i += 2)
        {
            s1.push_back(i);
            s1.push_back(n - i + 1);
        }
        for (int i = 2; i < n / 2; i += 2)
        {
            s2.push_back(i);
            s2.push_back(n - i + 1);
        }
    }
    else
    {
        for (int i = 1; i < n / 2; i += 2)
        {
            s1.push_back(i);
            s1.push_back(n - i + 1);
        }
        for (int i = 2; i <= n / 2; i += 2)
        {
            s2.push_back(i);
            s2.push_back(n - i + 1);
        }
    }
    display(s1, s2);
    return 0;
}