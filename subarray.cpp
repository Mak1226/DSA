// Subarray with sum = K for Z+ and 0 O(nLogn)
// Subarray with sum = K for Z O(2n)
// Zero Matrix O(2mn)
// Rotate Matrix by 90 degrees
// Spiral Matrix O(nm)
// Count subarray with sum = K Better = O(N^2) & Optimal = O(nLogn)
// Subarray with XOR = K Optimal = O(n)
// Max Product Subarray

#include <bits/stdc++.h>
using namespace std;

void subarraySumBetter(vector<int> v, long long k);
void subarraySumOptimal(vector<int> v, long long k);
void zeroMatrix(vector<vector<int>> v);
void rotateMatrixBrutal(vector<vector<int>> v);
void rotateMatrixOptimal(vector<vector<int>> v);
void spiralMatrix(vector<vector<int>> v);
void countSubarraySumBetter(vector<int> v, long long k);
void countSubarraySumOptimal(vector<int> v, long long k);
void pascalTriangle(int n);
void subarrayXOR(vector<int> v, int k);
void subarrayMaxProduct(vector<int> v);

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    subarraySumBetter(v, 15);
    zeroMatrix({{1, 0, 1}, {0, 1, 1}, {1, 1, 1}});
    rotateMatrixBrutal({{1, 2}, {3, 4}});
    rotateMatrixOptimal({{1, 2}, {3, 4}});
    spiralMatrix({{1, 2, 3}});
    countSubarraySumBetter({1, 2, 3, -3, 1, 1, 1, 4, 2, -3}, 3);
    countSubarraySumOptimal({1, 2, 3, -3, 1, 1, 1, 4, 2, -3}, 3);
    pascalTriangle(6);
    return 0;
}
void subarraySumBetter(vector<int> v, long long k)
{
    long long sum = 0;
    int m = 0, n = v.size();
    map<long long, int> preSum;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum == k)
            m = max(m, i + 1);
        long long rem = sum - k;
        if (preSum.find(rem) != preSum.end())
        {
            int len = i - preSum[rem];
            m = max(m, len);
        }
        if (preSum.find(sum) == preSum.end())
            preSum[sum] = i;
    }
    cout << m << endl;
}
void subarraySumOptimal(vector<int> v, long long k)
{
    int l = 0, r = 0, m = 0;
    long long sum = v[0], n = v.size();
    while (r < n)
    {
        while (l <= r && sum > k)
            sum -= v[l++];
        if (sum == k)
            m = max(m, r - l + 1);
        r++;
        if (r < n)
            sum += v[r];
    }
    cout << m << endl;
}
void zeroMatrix(vector<vector<int>> v)
{
    int c = 1;
    int n = v.size(), m = v[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == 0)
            {
                v[i][0] = 0;
                if (j != 0)
                    v[0][j] = 0;
                else
                    c = 0;
            }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (v[i][j] != 0)
            {
                if (v[0][j] == 0 || v[i][0] == 0)
                    v[i][j] = 0;
            }

    if (v[0][0] == 0)
        for (int i = 1; i < m; i++)
            v[0][i] = 0;

    if (c == 0)
        for (int i = 0; i < n; i++)
            v[i][0] = 0;

    for (auto itr : v)
        for (auto itc : itr)
            cout << itc << " ";
    cout << endl;
}
void rotateMatrixBrutal(vector<vector<int>> v)
{
    int n = v.size(), m = v[0].size();
    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[j][n - 1 - i] = v[i][j];
    for (auto itr : res)
    {
        for (auto itc : itr)
            cout << itc << " ";
        cout << endl;
    }
}
void rotateMatrixOptimal(vector<vector<int>> v)
{
    int n = v.size(), m = v[0].size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < m; j++)
            swap(v[i][j], v[j][i]);
    for (int i = 0; i < n; i++)
        reverse(v[i].begin(), v[i].end());
    for (auto itr : v)
    {
        for (auto itc : itr)
            cout << itc << " ";
        cout << endl;
    }
}
void spiralMatrix(vector<vector<int>> v)
{
    int n = v.size(), m = v[0].size();
    int t = 0, l = 0, r = m - 1, b = n - 1;
    while (t <= b && l <= r)
    {
        for (int j = l; j <= r; j++)
            cout << v[t][j] << " ";
        t++;
        for (int j = t; j <= b; j++)
            cout << v[j][r] << " ";
        r--;
        if (t <= b)
        {
            for (int j = r; j >= l; j--)
                cout << v[b][j] << " ";
            b--;
        }
        if (l <= r)
        {
            for (int j = b; j >= t; j--)
                cout << v[j][l] << " ";
            l++;
        }
    }
    cout << endl;
}
void countSubarraySumBetter(vector<int> v, long long k)
{
    int n = v.size(), c = 0;
    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += v[j];
            if (sum == k)
                c++;
        }
    }
    cout << c << endl;
}
void countSubarraySumOptimal(vector<int> v, long long k)
{
    int n = v.size(), c = 0;
    long long sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        long long rem = sum - k;
        c += mp[rem];
        mp[sum]++;
    }
    cout << c << endl;
}
vector<int> returnRow(int n)
{
    vector<int> row;
    long long ans = 1;
    row.push_back(1);
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans /= i;
        row.push_back(ans);
    }
    return row;
}
void pascalTriangle(int n)
{
    vector<int> row;
    vector<vector<int>> triangle;
    for (int i = 1; i <= n; i++)
        triangle.push_back(returnRow(i));
    for (auto itr : triangle)
    {
        for (auto it : itr)
            cout << it << " ";
        cout << endl;
    }
}
void subarrayXOR(vector<int> v, int k)
{
    int n = v.size(), XOR = 0, c = 0;
    unordered_map<int, int> mp;
    mp[XOR]++;
    for (int i = 0; i < n; i++)
    {
        XOR = XOR ^ v[i];
        c += mp[XOR ^ k];
        mp[XOR]++;
    }
    cout << c << endl;
}
void subarrayMaxProduct(vector<int> v)
{
    int n = v.size(), pre = 1, suf = 1, m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (!pre)
            pre = 1;
        if (!suf)
            suf = 1;
        pre *= v[i];
        suf *= v[n - i + 1];
        m = max(m, max(pre, suf));
    }
    cout << m << endl;
}
