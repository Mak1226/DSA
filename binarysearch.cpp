// Lower Bound O(nlogn)
// Upper Bound O(nlogn)
// Insert Position O(nlogn) => Similar to lower Bound
// Floor and Ceil Value O(nlogn)
// First and Last Occurance O(2nlogn)

#include <bits/stdc++.h>
using namespace std;

void binarySearch(vector<int> v, int target);
void lowerBound(vector<int> v, int target);
void upperBound(vector<int> v, int target);
void insertPosition(vector<int> v, int num);
void ceilValue(vector<int> v, int num);
void floorValue(vector<int> v, int num);
void firstLastOccurance(vector<int> v, int target);

int main()
{
    binarySearch({1, 2, 3, 4, 5, 6}, 30);
    return 0;
}
void binarySearch(vector<int> v, int target)
{
    int l = 0, r = v.size() - 1;
    bool flag = false;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[m] == target)
        {
            cout << m << endl;
            flag = true;
            break;
        }
        else if (v[m] < target)
            l = m + 1;
        else if (v[m] > target)
            r = m - 1;
    }
    if (!flag)
        cout << -1 << endl;
}
void lowerBound(vector<int> v, int target)
{
    int l = 0, r = v.size() - 1, ans = v.size();
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] >= target)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans << endl;
}
void upperBound(vector<int> v, int target)
{
    int l = 0, r = v.size() - 1, ans = v.size();
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] > target)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans << endl;
}
void insertPosition(vector<int> v, int num)
{
    int l = 0, r = v.size() - 1, ind = v.size();
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] >= num)
        {
            ind = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ind << endl;
}
void ceilValue(vector<int> v, int num)
{
    int l = 0, r = v.size() - 1, ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] >= num)
        {
            ans = v[m];
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans << endl;
}
void floorValue(vector<int> v, int num)
{
    int l = 0, r = v.size() - 1, ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] <= num)
        {
            ans = v[m];
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << ans << endl;
}
int lowerBoundOccur(vector<int> v, int target)
{
    int n = v.size();
    int l = 0, r = n - 1, ans = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] >= target)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}
int upperBoundOccur(vector<int> v, int target)
{
    int n = v.size();
    int l = 0, r = n - 1, ans = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] > target)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}
int firstOccur(vector<int> v, int target)
{
    int l = 0, r = v.size() - 1, ind = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] == target)
        {
            ind = m;
            r = m - 1;
        }
        else if (v[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return ind;
}
int lastOccur(vector<int> v, int target)
{
    int l = 0, r = v.size() - 1, ind = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] == target)
        {
            ind = m;
            l = m + 1;
        }
        else if (v[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return ind;
}
void firstLastOccurance(vector<int> v, int target)
{
    cout << "Bound Method" << endl;
    int ind = lowerBoundOccur(v, target);
    if (ind == v.size() || v[ind] != target)
        cout << -1 << " " << -1 << endl;
    else
        cout << ind << " " << (upperBoundOccur(v, target) - 1) << endl;
    cout << "Search Method" << endl;
    cout << firstOccur(v, target) << " " << lastOccur(v, target) << endl;
}
void countOccurance(vector<int> v, int target)
{
    cout << (lastOccur(v, target) - firstOccur(v, target)) << endl;
}