// Print all factors of N
// Same logic works for prime number
// O(sqrt(n))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    set<int> st;
    int k = sqrt(x);
    for (int i = 1; i <= k; i++)
    {
        if (x % i == 0)
        {
            st.insert(i);
            st.insert(x / i);
            // cout << i << " ";
            // if(x/i!=i)
            //     cout << x/i << " ";
        }
    }
    for (auto it : st)
        cout << it << endl;
    return 0;
}