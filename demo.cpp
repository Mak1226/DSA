#include <bits/stdc++.h>
using namespace std;
bool checkPrime(int x)
{
    int k = sqrt(x);
    for (int i = 2; i <= k; i++)
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
    // int x, y, z;
    // cin >> x >> y >> z;
    // cout << "Hello World " << x + y + z << endl;
    // string str;
    // getline(cin,str);
    // cout << str << endl;
    // int arr[5];
    // arr[1] = 3;
    // int arr[5] = {1,2,3,4,5};
    // int hash[5] = {1};
    // for(auto it: hash)
    //     cout << it << " ";
    // cout << arr[1] << endl;
    // string str = "Hello World";
    // does(str);
    // cout << str << endl;
    // int x;
    // bool flag = checkPrime(x);
    // cout << flag << endl;
    // vector<int>:: reverse_iterator it = v.rbegin();
    // cout << *(++it) << endl;
    // vector<int> v = {1,2,3,4,5};
    // auto m = max_element(v.begin(),v.end());
    // auto n = min_element(v.begin(),v.end());
    // cout << *m << " " << *n << endl;
    // v.insert(v.end(),6);
    // for(auto &it: v)
    //     cout << it << endl;
    // int n = 231787;
    // cout << (int)(log10(n) + 1) << endl;
    // cout << __builtin_popcount(n) << endl;
    return 0;
}