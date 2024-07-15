// Lower Bound O(nlogn)
// Upper Bound O(nlogn)
// Insert Position O(nlogn) => Similar to lower Bound
// Floor and Ceil Value O(nlogn)
// First and Last Occurance O(2nlogn)
// Search in Rotated Array I & II O(logn)
// Minimum in Sorted Rotated Array O(logn)
// Count number of rotation O(logn)
// Search Missing Element O(logn)
// Find Peak element I & II O(logn)
// Ship Capacity to load O(sum - min)*O(logn)
// Minimize Max Dist b/w gas stations Brute = O(k*n) + O(n)
// Gas Station Better TC = O(nlogn) + O(klogn) | SC = O(n-1)
// Gas Station Optimal TC = o(nlogn) + O(klogn) | SC = o(1)

#include <bits/stdc++.h>
using namespace std;

void binarySearch(vector<int> v, int target);
void lowerBound(vector<int> v, int target);
void upperBound(vector<int> v, int target);
void insertPosition(vector<int> v, int num);
void ceilValue(vector<int> v, int num);
void floorValue(vector<int> v, int num);
void firstLastOccurance(vector<int> v, int target);
void countOccurance(vector<int> v, int target);
void searchRotatedArrayI(vector<int> v, int target);
void searchRotatedArrayII(vector<int> v, int target);
void minRotatedSortedArray(vector<int> v);
void rotationCount(vector<int> v);
void searchSingleElement(vector<int> v);
void singlePeak(vector<int> v);
void multiplePeak(vector<int> v);

int main()
{
    int choice;
    cout << "1.BS\n2.LB/UB\n3.Insert Pos\n4.Ceil/Floor\n5.Count occur\n6.Search in Rotated Array I-II\n7.Min in Rotated Array\n8.Rotation Count\n9.Single Element\n10.Peak" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Test Case 1:" << endl;
        cout << "1 2 3 4 5 6\nTarget: 30" << endl;
        binarySearch({1, 2, 3, 4, 5, 6}, 30);
        cout << "Test Case 2:" << endl;
        cout << "1 2 3 4 5 6\nTarget: 3" << endl;
        binarySearch({1, 2, 3, 4, 5, 6}, 3);
        break;
    case 2:
        cout << "Lower Bound & Upper Bound" << endl;
        cout << "Test Case 1:" << endl;
        cout << "1 2 2 3\nTarget: 2" << endl;
        lowerBound({1, 2, 2, 3}, 2);
        cout << "Test Case 2:" << endl;
        cout << "3 5 8 15 19\nTarget: 9" << endl;
        lowerBound({3, 5, 8, 15, 19}, 9);
        cout << "Test Case 1:" << endl;
        cout << "1 2 2 3\nTarget: 2" << endl;
        upperBound({1, 2, 2, 3}, 2);
        cout << "Test Case 2:" << endl;
        cout << "3 5 8 15 19\nTarget: 9" << endl;
        upperBound({3, 5, 8, 15, 19}, 9);
        break;
    case 3:
        cout << "Test Case 1:" << endl;
        cout << "1 2 4\nTarget: 6" << endl;
        insertPosition({1, 2, 4, 7}, 6);
        cout << "Test Case 2:" << endl;
        cout << "1 2 4 7\nTarget: 2" << endl;
        insertPosition({1, 2, 4, 7}, 2);
        break;
    case 4:
        cout << "Ceil and Floor" << endl;
        cout << "Test Case 1:" << endl;
        cout << "3 4 4 7 8 10\nTarget: 5" << endl;
        ceilValue({3, 4, 4, 7, 8, 10}, 5);
        cout << "Test Case 2:" << endl;
        cout << "3 4 4 7 8 10\nTarget: 8" << endl;
        ceilValue({3, 4, 4, 7, 8, 10}, 8);
        cout << "Test Case 1:" << endl;
        cout << "3 4 4 7 8 10\nTarget: 5" << endl;
        floorValue({3, 4, 4, 7, 8, 10}, 5);
        cout << "Test Case 2:" << endl;
        cout << "3 4 4 7 8 10\nTarget: 8" << endl;
        floorValue({3, 4, 4, 7, 8, 10}, 8);
        break;
    case 5:
        cout << "Test Case 1:" << endl;
        cout << "2 2 3 3 3 3 4" << endl;
        countOccurance({2, 2, 3, 3, 3, 3, 4}, 5);
        cout << "Test Case 2:" << endl;
        cout << "1 1 2 2 2 2 2 3" << endl;
        countOccurance({1, 1, 2, 2, 2, 2, 2, 3}, 2);
        break;
    case 6:
        cout << "Search In rotated Array I-II" << endl;
        cout << "Test Case 1:" << endl;
        cout << "4 5 6 7 0 1 2 3\nTarget: 0" << endl;
        searchRotatedArrayI({4, 5, 6, 7, 0, 1, 2, 3}, 0);
        cout << "7 8 1 2 3 3 3 4 5 6\nTarget: 3" << endl;
        searchRotatedArrayII({7, 8, 1, 2, 3, 3, 3, 4, 5, 6}, 3);
        cout << "Test Case 2:" << endl;
        cout << "4 5 6 7 0 1 2\nTarget: 3" << endl;
        searchRotatedArrayI({4, 5, 6, 7, 0, 1, 2}, 3);
        cout << "7 8 1 2 3 3 3 4 5 6\nTarget: 10" << endl;
        searchRotatedArrayII({7, 8, 1, 2, 3, 3, 3, 4, 5, 6}, 10);
        break;
    case 7:
        cout << "Test Case 1:" << endl;
        cout << "4 5 6 7 0 1 2 3" << endl;
        minRotatedSortedArray({4, 5, 6, 7, 0, 1, 2, 3});
        cout << "Test Case 2:" << endl;
        cout << "3 4 5 1 2" << endl;
        minRotatedSortedArray({3, 4, 5, 1, 2});
        break;
    case 8:
        cout << "Test Case 1:" << endl;
        cout << "4 5 6 7 0 1 2 3" << endl;
        rotationCount({4, 5, 6, 7, 0, 1, 2, 3});
        cout << "Test Case 2:" << endl;
        cout << "3 4 5 1 2" << endl;
        rotationCount({3, 4, 5, 1, 2});
        break;
    case 9:
        cout << "Test Case 1:" << endl;
        cout << "1 1 2 2 3 3 4 5 5 6 6" << endl;
        searchSingleElement({1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6});
        cout << "Test Case 2:" << endl;
        cout << "1 1 3 5 5" << endl;
        searchSingleElement({1, 1, 3, 5, 5});
        break;
    case 10:
        cout << "Single and Multiple Peak" << endl;
        cout << "Test Case 1:" << endl;
        cout << "1 2 3 4 5 6 7 8 5 1" << endl;
        singlePeak({1, 2, 3, 4, 5, 6, 7, 8, 5, 1});
        cout << "1 2 1 3 5 6 4" << endl;
        multiplePeak({1, 2, 1, 3, 5, 6, 4});
        cout << "Test Case 2:" << endl;
        cout << "5 4 3 2 1" << endl;
        singlePeak({5, 4, 3, 2, 1});
        cout << "2 1 3 4 5 6" << endl;
        multiplePeak({2, 1, 3, 4, 5, 6});
        break;
    default:
        break;
    }
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
    if (firstOccur(v, target) == -1)
        cout << 0 << endl;
    else
        cout << (lastOccur(v, target) - firstOccur(v, target)) + 1 << endl;
}
void searchRotatedArrayI(vector<int> v, int target)
{
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[m] == target)
        {
            cout << m << endl;
            return;
        }
        if (v[l] <= v[m])
        {
            if (v[l] <= target && target <= v[m])
                r = m - 1;
            else
                l = m + 1;
        }
        else
        {
            if (v[m] <= target && target <= v[r])
                l = m + 1;
            else
                r = m - 1;
        }
    }
    cout << "-1" << endl;
}
void searchRotatedArrayII(vector<int> v, int target)
{
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[m] == target)
        {
            cout << m << endl;
            return;
        }
        if (v[l] == v[m] && v[m] == v[r])
        {
            l++;
            r--;
            continue;
        }
        if (v[l] <= v[m])
        {
            if (v[l] <= target && target <= v[m])
                r = m - 1;
            else
                l = m + 1;
        }
        else
        {
            if (v[m] <= target && target <= v[r])
                l = m + 1;
            else
                r = m - 1;
        }
    }
    cout << -1 << endl;
}
void minRotatedSortedArray(vector<int> v)
{
    int l = 0, r = v.size() - 1, ans = INT_MAX;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[l] < v[r])
        {
            ans = min(ans, v[l]);
            break;
        }
        if (v[l] <= v[m])
        {
            ans = min(ans, v[m]);
            l = m + 1;
        }
        else
        {
            ans = min(ans, v[m]);
            r = m - 1;
        }
    }
    cout << ans << endl;
}
void rotationCount(vector<int> v)
{
    int l = 0, r = v.size() - 1, ans = INT_MAX, ind = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[l] < v[r])
        {
            if (v[l] < ans)
            {
                ind = l;
                ans = v[l];
            }
            break;
        }
        if (v[l] <= v[m])
        {
            if (v[l] < ans)
            {
                ind = l;
                ans = v[l];
            }
            l = m + 1;
        }
        else
        {
            if (v[m] < ans)
            {
                ind = m;
                ans = v[m];
            }
            r = m - 1;
        }
    }
    cout << ind << endl;
}
void searchSingleElement(vector<int> v)
{
    int l = 1, r = v.size() - 2;
    if (v[0] != v[1])
    {
        cout << v[0] << endl;
        return;
    }
    else if (v[r] != v[r + 1])
    {
        cout << v[r + 1] << endl;
        return;
    }
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[m] != v[m - 1] && v[m] != v[m + 1])
        {
            cout << v[m] << endl;
            return;
        }
        if ((m & 1 && v[m] == v[m - 1]) || (!(m & 1) && v[m] == v[m + 1]))
            l = m + 1;
        else
            r = m - 1;
    }
    cout << -1 << endl;
}
void multiplePeak(vector<int> v)
{
    int n = v.size();
    int l = 1, r = n - 2;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (v[0] > v[1])
    {
        cout << 0 << endl;
        return;
    }
    if (v[n - 1] > v[n - 2])
    {
        cout << n - 1 << endl;
        return;
    }
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[m] > v[m - 1] && v[m] > v[m + 1])
        {
            cout << m << endl;
            return;
        }
        else if (v[m] > v[m - 1])
            l = m + 1;
        else
            r = m - 1;
    }
}
void singlePeak(vector<int> v)
{
    int n = v.size();
    int l = 1, r = n - 2;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (v[0] > v[1])
    {
        cout << 0 << endl;
        return;
    }
    if (v[n - 1] > v[n - 2])
    {
        cout << n - 1 << endl;
        return;
    }
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[m] > v[m - 1] && v[m] > v[m + 1])
        {
            cout << m << endl;
            return;
        }
        else if (v[m] > v[m - 1])
            l = m + 1;
        else if (v[m] > v[m - 1])
            r = m - 1;
    }
}
