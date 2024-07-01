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

#include <bits/stdc++.h>
using namespace std;

void binarySearch(vector<int> v, int target);
void lowerBound(vector<int> v, int target);
void upperBound(vector<int> v, int target);
void insertPosition(vector<int> v, int num);
void ceilValue(vector<int> v, int num);
void floorValue(vector<int> v, int num);
void firstLastOccurance(vector<int> v, int target);
void searchRotatedArrayI(vector<int> v, int target);
void searchRotatedArrayII(vector<int> v, int target);
void minSortedArray(vector<int> v);
void rotationCount(vector<int> v);
void searchMissingElement(vector<int> v, int target);
void singlePeak(vector<int> v);
void multiplePeak(vector<int> v);
void squareRoot(int num);
void nthRoot(int n, int m);
void kokoBananas(vector<int> v, int h);
void bouquets(vector<int> v, int k, int m);
void thresholdDivisor(vector<int> v, int threshold);
void shipCapacity(vector<int> v, int days);

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
void searchRotatedArrayI(vector<int> v, int target)
{
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int m = l - (r - l) / 2;
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
void minSortedArray(vector<int> v)
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
void searchMissingElement(vector<int> v, int target)
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
void squareRoot(int num)
{
    int l = 1, r = num, ans = 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (m * m == ans)
        {
            cout << m << endl;
            return;
        }
        else if (m * m < num)
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << ans << endl;
}
int findPower(int n, int m, int mid)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}
void nthRoot(int n, int m)
{
    int l = 1, r = m;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (findPower(n, m, mid) == 1)
        {
            cout << mid << endl;
            return;
        }
        else if (findPower(n, m, mid) == 2)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << -1 << endl;
}
int findHours(vector<int> v, int h)
{
    int hours = 0;
    for (int m : v)
        hours += ceil((double)m / h);
    return hours;
}
void kokoBananas(vector<int> v, int h)
{
    int n = 0;
    for (int num : v)
        n = max(n, num);
    int l = 1, r = n;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int hours = 0;
        hours = findHours(v, m);
        if (hours <= h)
        {
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << l << endl;
}
int findBouquets(vector<int> v, int mid, int m, int k)
{
    int c = 0, bouquets = 0;
    for (int it : v)
    {
        if (it <= mid)
            c++;
        else
        {
            bouquets += c / m;
            c = 0;
        }
    }
    bouquets += c / m;
    return c;
}
void bouquets(vector<int> v, int k, int m)
{
    if (v.size() < k * m)
    {
        cout << -1 << endl;
        return;
    }
    int n = 0;
    for (int num : v)
        n = max(n, num);
    int l = 1, r = n;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (findBouquets(v, mid, m, k) >= k)
            l = mid + 1;
        else
            r = mid - 1;
    }
}
int findThreshold(vector<int> v, int m)
{
    int sum = 0;
    for (int it : v)
        sum += ceil((double)it / m);
    return sum;
}
void thresholdDivisor(vector<int> v, int threshold)
{
    int n = 0;
    for (int it : v)
        n = max(n, it);
    int l = 1, r = n, t = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (findThreshold(v, m) <= threshold)
            r = m - 1;
        else
            l = m + 1;
    }
    cout << t << endl;
}
int findDays(vector<int> v, int cap)
{
    int days = 1, load = 0;
    for(int it: v)
    {
        if(load + it > cap)
        {
            days++;
            load = it;
        }
        else
            load += it;
    }
    return days;
}
void shipCapacity(vector<int> v, int days)
{
    int n = 0, s = 0;
    for (int it : v)
    {
        n = max(n, it);
        s += it;
    }
    int l = n, r = s;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int day = findDays(v, m);
        if(day<days)
            r = m - 1;
        else
            l = m + 1;
    }
    cout << l << endl;
}
