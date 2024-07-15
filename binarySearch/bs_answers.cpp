#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int choice;
    cout << "1.SqRoot\n2.NthRoot\n3.Koko Bananas\n4.Bouquets\n5.Smallest Divisor\n6.Ship\n7.Kth Missing Num\n8.Cows\n9.Book\n10.Gas\n11.Merged Median\n12.Kth Element Merged Array" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Test Case 1:" << endl;
        cout << "78" << endl;
        squareRoot(78);
        cout << "Test Case 2:" << endl;
        cout << "25" << endl;
        squareRoot(25);
        break;
    case 2:
        cout << "Test Case 1:" << endl;
        cout << "3 27" << endl;
        nthRoot(3, 27);
        cout << "Test Case 2:" << endl;
        cout << "4 69" << endl;
        nthRoot(4, 69);
        break;
    case 3:
        cout << "Test Case 1:" << endl;
        cout << "7 15 6 3\nHours: 8" << endl;
        kokoBananas({7, 15, 6, 3}, 8);
        cout << "Test Case 2:" << endl;
        cout << "25, 12, 8, 14, 19\nHours: 5" << endl;
        kokoBananas({25, 12, 8, 14, 19}, 5);
        break;
    case 4:
        cout << "Test Case 1:" << endl;
        cout << "7 7 7 7 13 11 12 7\n3  2" << endl;
        bouquets({7, 7, 7, 7, 13, 11, 12, 7}, 3, 2);
        cout << "Test Case 2:" << endl;
        cout << "1 10 3 10 2\n3 2" << endl;
        bouquets({1, 10, 3, 10, 2}, 3, 2);
        break;
    case 5:
        cout << "Test Case 1:" << endl;
        cout << "1 2 3 4 5\n8" << endl;
        thresholdDivisor({1, 2, 3, 4, 5}, 8);
        cout << "Test Case 2:" << endl;
        cout << "8 4 2 3\n10" << endl;
        thresholdDivisor({8, 4, 2, 3}, 10);
        break;
    case 6:
        cout << "Test Case 1:" << endl;
        cout << "4 7 9 10\n1" << endl;
        shipCapacity({4, 7, 9, 10}, 1);
        cout << "Test Case 2:" << endl;
        cout << "4 7 9 10\n4" << endl;
        shipCapacity({4, 7, 9, 10}, 4);
        break;
    case 7:
        cout << "Test Case 1:" << endl;
        cout << "4 7 9 10\n1" << endl;
        kthMissingNumber({4, 7, 9, 10}, 1);
        cout << "Test Case 2:" << endl;
        cout << "4 7 9 10\n4" << endl;
        kthMissingNumber({4, 7, 9, 10}, 4);
        cout << "" << endl;
        break;
    case 8:
        cout << "Test Case 1:" << endl;
        cout << "0 3 47 10 9\n4" << endl;
        placeCows({0, 3, 47, 10, 9}, 4);
        cout << "Test Case 2:" << endl;
        cout << "4 2 1 3 6\n2" << endl;
        placeCows({4, 2, 1, 3, 6}, 2);
        break;
    case 9:
        cout << "Test Case 1:" << endl;
        cout << "12 34 67 90\n2" << endl;
        bookAllocation({12, 34, 67, 90}, 2);
        cout << "Test Case 2:" << endl;
        cout << "25 46 28 49 24\n4" << endl;
        bookAllocation({25, 46, 28, 49, 24}, 4);
        break;
    case 10:
        cout << "Test Case 1:" << endl;
        cout << "1 2 3 4 5\n4" << endl;
        gasStationBrute({1, 2, 3, 4, 5}, 4);
        gasStationBetter({1, 2, 3, 4, 5}, 4);
        gasStationOptimal({1, 2, 3, 4, 5}, 4);
        cout << "Test Case 2:" << endl;
        cout << "1 2 3 4 5 6 7 8 9 10\n1" << endl;
        gasStationBrute({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1);
        gasStationBetter({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1);
        gasStationOptimal({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1);
        break;
    case 11:
        cout << "Test Case 1:" << endl;
        cout << "2 4 6\n1 3 5" << endl;
        sortedArrayMedianBetter({2, 4, 6}, {1, 3, 5});
        sortedArrayMedianOptimal({2, 4, 6}, {1, 3, 5});
        cout << "Test Case 2:" << endl;
        cout << "2 4 6\n1 3" << endl;
        sortedArrayMedianBetter({2, 4, 6}, {1, 3});
        sortedArrayMedianOptimal({2, 4, 6}, {1, 3});
        break;
    case 12:
        cout << "Test Case 1:" << endl;
        cout << "2 3 6 7 9\n1 4 8 10\nTarget: 5" << endl;
        kthElementMergedArray({2, 3, 6, 7, 9}, {1, 4, 8, 10}, 5);
        cout << "Test Case 2:" << endl;
        cout << "100 112 256 349 770\n72 86 113 265 445 892\nTarget: 7" << endl;
        kthElementMergedArray({100, 112, 256, 349, 770}, {72, 86, 113, 119, 265, 445, 892}, 7);
        break;
    default:
        break;
    }
    return 0;
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
