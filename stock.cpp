// Buy and Sell Stock O(n)

#include <bits/stdc++.h>
using namespace std;
void buyAndSellStock(vector<int> v);
int main()
{
    buyAndSellStock({7,1,3,5,7,9,3,1,3,7,9});
    return 0;
}
void buyAndSellStock(vector<int> v)
{
    int n = v.size(), profit = 0, m = v[0];
    for (int i = 1; i < n; i++)
    {
        profit = max(profit, v[i] - m);
        m = min(m,v[i]);
    }
    cout << profit << endl;
    
}