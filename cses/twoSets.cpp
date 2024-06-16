#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926535897932384626
#define pb push_back
#define pp pop_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const unsigned int M = 1000000007;
void display(set<int> &s1, set<int> &s2)
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
void makesets(int s, int l, bool flag)
{
    set<int> s1, s2;
    for (int i = 1; i <= s / 4; i++)
    {
        s1.insert(i);
        s1.insert(l - i + 1);
    }
    for (int i = s / 4 + 1; i <= s / 2; i++)
    {
        s2.insert(i);
        s2.insert(l - i + 1);
    }
    if (flag)
        s2.insert(++l);
    // if (s1.size() > s2.size())
    //     display(s1, s2);
    // else
    //     display(s2, s1);
    display(s1, s2);
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
    set<int> s1, s2;
    if (!(n & 1))
        makesets(n, n, false);
    else
        makesets(n + 1, n - 1, true);

    return 0;
}