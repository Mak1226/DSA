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
// Ship Capacity to load O(sum - min)*O(logn)\
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
void kthMissingNumber(vector<int> v, int k);
void placeCows(vector<int> v, int n);
void bookAllocation(vector<int> v, int s);
void gasStationBrute(vector<int> v, int k);
void gasStationBetter(vector<int> v, int k);
void gasStationOptimal(vector<int> v, int k);
void sortedArrayMedianBetter(vector<int> v1, vector<int> v2);
void sortedArrayMedianOptimal(vector<int> v1, vector<int> v2);
void kthElementMergedArray(vector<int> v1, vector<int> v2, int k);
void maxOnes(vector<vector<int>> v);
void search2DMatrix(vector<vector<int>> v, int target);
void search2DUnsorted(vector<vector<int>> v, int target);
void peakElement2D(vector<vector<int>> v);

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
    for (int it : v)
    {
        if (load + it > cap)
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
        if (day < days)
            r = m - 1;
        else
            l = m + 1;
    }
    cout << l << endl;
}
void kthMissingNumber(vector<int> v, int k)
{
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int miss = v[m] - (m + 1);
        if (miss < k)
            l = m + 1;
        else
            r = m - 1;
    }
    cout << l + k << endl;
}
bool findCows(vector<int> v, int cows, int dis)
{
    int c = 1, last = v[0], n = v.size();
    for (int i = 1; i < n; i++)
    {
        if (v[i] - last >= dis)
        {
            c++;
            last = v[i];
        }
        if (c >= cows)
            return true;
    }
    return false;
}
void placeCows(vector<int> v, int num)
{
    sort(v.begin(), v.end());
    int l = 0, r = v.back() - v.front();
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (findCows(v, num, m))
            l = m + 1;
        else
            r = m - 1;
    }
    cout << r << endl;
}
int findStudents(vector<int> v, int p)
{
    int c = 1;
    long long int pages = 0;
    for (int it : v)
    {
        if (pages + it <= p)
            pages += it;
        else
        {
            c++;
            pages = it;
        }
    }
    return pages;
}
void bookAllocation(vector<int> v, int s)
{
    int l = 0, r = 0;
    for (int it : v)
    {
        l = max(l, it);
        r += it;
    }
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (findStudents(v, m) > s)
            l = m + 1;
        else
            r = m - 1;
    }
    cout << l << endl;
}
void gasStationBrute(vector<int> v, int k)
{
    int n = v.size();
    vector<int> num(n - 1, 0);
    for (int i = 1; i <= k; i++)
    {
        long double maxStation = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++)
        {
            long double diff = v[i + 1] - v[i];
            long double secLen = diff / (long double)(num[i] + 1);
            if (maxStation < secLen)
            {
                maxStation = secLen;
                maxInd = i;
            }
        }
        num[maxInd]++;
    }
    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = v[i + 1] - v[i];
        long double secLen = diff / (long double)(num[i] + 1);
        maxAns = max(maxAns, secLen);
    }
    cout << maxAns << endl;
}
void gasStationBetter(vector<int> v, int k)
{
    int n = v.size();
    vector<int> num(n - 1, 0);
    priority_queue<pair<long double, int>> pq;
    for (int i = 0; i < n - 1; i++)
        pq.push({v[i + 1] - v[i], i});
    for (int i = 1; i <= k; i++)
    {
        auto it = pq.top();
        pq.pop();
        int secInd = it.second;
        num[secInd]++;
        long double initDiff = v[secInd + 1] - v[secInd];
        long double newSecLen = initDiff / (long double)(num[secInd] + 1);
        pq.push({newSecLen, secInd});
    }
    cout << pq.top().first << endl;
}
int findGasStations(vector<int> v, int dist)
{
    int c = 0;
    for (int i = 1; i < v.size(); i++)
    {
        int inbetween = (v[i] - v[i - 1]) / dist;
        if (inbetween * dist == (v[i] - v[i - 1]))
            inbetween--;
        c += inbetween;
    }
    return c;
}
void gasStationOptimal(vector<int> v, int k)
{
    int n = v.size();
    long double l = 0;
    long double r = 0;
    for (int i = 0; i < n - 1; i++)
        r = max(r, (long double)(v[i + 1] - v[i]));
    long double diff = 1e-6;
    while (r - l > diff)
    {
        long double mid = l + (r - l) / 2.0;
        if (findGasStations(v, mid) > k)
            l = mid;
        else
            r = mid;
    }
    cout << r << endl;
}
void sortedArrayMedianBetter(vector<int> v1, vector<int> v2)
{
    int n1 = v1.size(), n2 = v2.size();
    int n = n1 + n2;
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int i = 0, j = 0, c = 0;
    int elem1 = -1, elem2 = -1;
    while (i < n1 && j < n2)
    {
        if (v1[i] < v2[j])
        {
            if (c == ind1)
                elem1 = v1[i];
            if (c == ind2)
                elem2 = v1[i];
            c++;
            i++;
        }
        else
        {
            if (c == ind1)
                elem1 = v2[i];
            if (c == ind2)
                elem2 = v2[i];
            c++;
            j++;
        }
    }
    while (i < n1)
    {
        if (c == ind1)
            elem1 = v1[i];
        if (c == ind2)
            elem2 = v1[i];
        c++;
        i++;
    }
    while (j < n2)
    {
        if (c == ind1)
            elem1 = v2[i];
        if (c == ind2)
            elem2 = v2[i];
        c++;
        j++;
    }
    if (n & 1)
        cout << elem2 << endl;
    else
        cout << (double)(elem1 + elem2) / 2.0 << endl;
}
void sortedArrayMedianOptimal(vector<int> v1, vector<int> v2)
{
    int n1 = v1.size(), n2 = v2.size();
    if (n1 > n2)
        return sortedArrayMedianOptimal(v2, v1);
    int l = 0, r = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;
    while (l <= r)
    {
        int mid1 = l + (r - l) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = v1[mid1];
        if (mid2 < n2)
            r2 = v2[mid2];
        if (mid1 - 1 >= 0)
            l1 = v1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = v2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n & 1)
            {
                cout << (double)(max(l1, l2)) << endl;
                return;
            }
            else
            {
                cout << (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                return;
            }
        }
        else if (l1 > r2)
            r = mid1 - 1;
        else
            l = mid1 + 1;
    }
}
void kthElementMergedArray(vector<int> v1, vector<int> v2, int k)
{
    int n1 = v1.size(), n2 = v2.size();
    if (n1 > n2)
        return kthElementMergedArray(v2, v1, k);
    int l = max(k - n2, 0), r = min(k, n1);
    int remain = k;
    while (l <= r)
    {
        int m1 = l + (r - l) / 2;
        int m2 = remain - m1;
        int r1 = (m1 < n1) ? v1[m1] : INT_MAX;
        int r2 = (m2 < n2) ? v2[m2] : INT_MAX;
        int l1 = (m1 - 1 >= 0) ? v1[m1 - 1] : INT_MIN;
        int l2 = (m2 - 1 >= 0) ? v2[m2 - 1] : INT_MIN;
        if (l1 <= r2 && l2 <= r1)
        {
            cout << max(l1, l2) << endl;
            return;
        }
        else if (l1 > r2)
            r = m1 - 1;
        else
            l = m2 + 1;
    }
}
void maxOnes(vector<vector<int>> v)
{
    int cnt_max = 0, ind = -1, i = 0;
    for (auto it : v)
    {
        int cnt_ones = it.size() - lowerBoundOccur(it, 1);
        if (cnt_max < cnt_ones)
        {
            cnt_max = cnt_ones;
            ind = i;
        }
        i++;
    }
    cout << ind << endl;
}
void search2DMatrix(vector<vector<int>> v, int target)
{
    int n = v.size(), m = v[0].size();
    int l = 0, r = n * m - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int row = mid / m;
        int col = mid % m;
        if (v[row][col] == target)
        {
            cout << "(" << row << "," << col << ")" << endl;
            return;
        }
        else if (v[row][col] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
}
void search2DUnsorted(vector<vector<int>> v, int target)
{
    int n = v.size(), m = v[0].size();
    int r = 0, c = m - 1;
    while (r < n && c >= 0)
    {
        if (v[r][c] == target)
        {
            cout << "(" << r << "," << c << ")" << endl;
            return;
        }
        else if (v[r][c] < target)
            r++;
        else
            c--;
    }
    cout << "(-1,-1)" << endl;
}
int maxElementColumn(vector<vector<int>> v, int m)
{
    int ind = -1, e_max = -1, n = v.size();
    for (int i = 0; i < n; i++)
        if (e_max < v[i][m])
        {
            e_max = v[i][m];
            ind = i;
        }
    return ind;
}
void peakElement2D(vector<vector<int>> v)
{
    int n = v.size(), m = v[0].size();
    int l = 0, r = m - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int row = maxElementColumn(v, mid);
        int left = (mid - 1 >= 0) ? v[row][mid - 1] : -1;
        int right = (mid + 1 < m) ? v[row][mid + 1] : -1;
        if (v[row][mid] > left && v[row][mid] < right)
        {
            cout << "(" << row << "," << mid << ")" << endl;
            return;
        }
        else if (v[row][mid] < left)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << "(-1,-1)" << endl;
}
int findSmallEqual(vector<vector<int>> v, int mid)
{
    int c = 0;
    for(auto it: v)
        c+= upperBoundOccur(it, mid);
    return c;
}
void medianSortedMatrix(vector<vector<int>> v)
{
    int n = v.size(), m = v[0].size();
    int l = INT_MAX, r = INT_MIN;
    for(int i=0;i<n;i++)
    {
        l = min(l, v[i][0]);
        r = max(r,v[i][m-1]);
    }
    int rem = (n * m)/2;
    while (l<=r)
    {
        int mid = l + (r-l)/2;
        int smallerThanEqualsTo = findSmallEqual(v, mid);
        if(smallerThanEqualsTo <= rem)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l << endl;
}
