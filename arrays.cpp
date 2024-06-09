// Second Largest & Smallest Element O(n)
// Check sorted array O(n)
// Remove Duplicates
// Left Rotate by K elements Brute TC = O(n+k), SC = O(k)
// Left Rotatea by K elements Optimal TC = O(2n), SC = O(1)
// Move Zeroes to end O(n)
// Union of Arrays O(n1+n2)
// Intersection of Arrays O(n1+n2)
// Missing Number Sum O(n)
// Missing Number XOR O(n)
// Number that appears only once O(n)
// Merge Sorted Array Optimal1 = O(min(m,n)) + O(nlogn) + O(mlogm)
// Merge Sorted Array Optimal2 = O(log (m+n)) * O(m+n)
// Missing and Repeating Number O(4N)
// Count Inversion Optimal = O(nlogn)
// Count Reverse Pairs Optimal = O(2nlogn)

#include <bits/stdc++.h>
using namespace std;

void secondLargest(vector<int> v);
void secondSmallest(vector<int> v);
bool sortedArray(vector<int> v);
void removeDuplicates(vector<int> v);
void rotateBrute(vector<int> v, int k);
void rotateOptimal(vector<int> v, int k);
void zeroes(vector<int> v);
void unionArray(vector<int> v1, vector<int> v2);
void intersectionArray(vector<int> v1, vector<int> v2);
void missingNumSum(vector<int> v);
void missingNumXor(vector<int> v);
void consequtiveOnes(vector<int> v);
void oneFrequency(vector<int> v);
void mergeIntervals(vector<vector<int>> v);
void mergeSortedBetter(vector<int> v1, vector<int> v2);
void mergeSortedOptimal(vector<int> v1, vector<int> v2);
void missRepeat(vector<int> v);
void inversions(vector<int> v);
void reversePairs(vector<int> v);

int main()
{
    vector<int> v = {1, 2, 4, 67, 4, 2, 45, 67, 34, 5663, 567, 453, 5, 67, 23, 65, 34, 756, 34565, 743};
    vector<int> vs = {1, 2, 3, 4, 5};
    secondLargest(v);
    secondSmallest(v);
    cout << sortedArray(vs) << endl;
    removeDuplicates(vs);
    rotateBrute(vs, 3);
    rotateOptimal(vs, 3);
    zeroes({1, 2, 0, 0, 3, 4, 5, 0, 0, 0});
    unionArray({1, 2, 2, 3, 4}, {1, 2, 3, 4, 4, 5, 5});
    intersectionArray({1, 2, 3, 4, 4, 5, 5}, {1, 2, 2, 3, 4});
    missingNumSum({1, 2, 4, 5});
    missingNumXor({1, 2, 4, 5});
    consequtiveOnes({1, 2, 1, 1, 1, 1, 6, 4, 5, 1, 1, 0, 5});
    oneFrequency({0, 1, 2, 3, 1, 0, 3});
    missRepeat({1, 1, 2, 3, 4, 6});
    inversions({5, 3, 2, 4, 1});
    reversePairs({40, 25, 19, 12, 9, 6, 2});
    return 0;
}
void secondLargest(vector<int> v)
{
    int l = v[0], sl = INT_MIN, s = v.size();
    for (int i = 1; i < s; i++)
    {
        if (v[i] > l)
        {
            sl = l;
            l = v[i];
        }
        else if (v[i] < l && v[i] > sl)
            sl = v[i];
    }
    cout << sl << endl;
}
void secondSmallest(vector<int> v)
{
    int s = v[0], ss = INT_MAX, l = v.size();
    for (int i = 1; i < l; i++)
    {
        if (v[i] < s)
        {
            ss = s;
            s = v[i];
        }
        else if (v[i] > s && v[i] < ss)
            ss = v[i];
    }
    cout << ss << endl;
}
bool sortedArray(vector<int> v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
        if (v[i - 1] > v[i])
            return false;
    return true;
}
void removeDuplicates(vector<int> v)
{
    int p = 0, n = v.size();
    for (int i = 1; i < n; i++)
        if (v[i] != v[p])
            v[++p] = v[i];
    for (int i = 0; i <= p; i++)
        cout << v[i] << " ";
    cout << endl;
}
void rotateBrute(vector<int> v, int k)
{
    int n = v.size();
    k %= n;
    vector<int> temp(k);
    for (int i = 0; i < k; i++)
        temp[i] = v[i];
    for (int i = k; i < n; i++)
        v[i - k] = v[i];
    for (int i = n - k; i < n; i++)
        v[i] = temp[i - (n - k)];

    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
void reverseFunction(vector<int> &v, int l, int r)
{
    while (l < r)
        swap(v[l++], v[r--]);
}
void rotateOptimal(vector<int> v, int k)
{
    int n = v.size();
    k %= n;
    reverseFunction(v, 0, k - 1);
    reverseFunction(v, k, n - 1);
    reverseFunction(v, 0, n - 1);
    for (auto it : v)
        cout << it << " ";
    cout << endl;
    // reverse(v.begin(), v.begin() + k);
    // reverse(v.begin() + k, v.end());
    // reverse(v.begin(), v.end());
}
void zeroes(vector<int> v)
{
    int n = v.size();
    int j = -1;
    for (int i = 0; i < n; i++)
        if (v[i] == 0)
        {
            j = i;
            break;
        }
    if (j == -1)
        return;
    for (int i = j + 1; i < n; i++)
        if (v[i] != 0)
            swap(v[i], v[j++]);
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
void unionArray(vector<int> v1, vector<int> v2)
{
    int i = 0, j = 0;
    vector<int> uv;

    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] <= v2[j])
        {
            if (uv.size() == 0 || uv.back() != v1[i])
                uv.push_back(v1[i]);
            i++;
        }
        else
        {
            if (uv.size() == 0 || uv.back() != v2[j])
                uv.push_back(v2[j]);
            j++;
        }
    }
    while (i < v1.size())
    {
        if (uv.size() == 0 || uv.back() != v1[i])
            uv.push_back(v1[i]);
        i++;
    }
    while (j < v2.size())
    {
        if (uv.size() == 0 || uv.back() != v2[j])
            uv.push_back(v2[j]);
        j++;
    }
    for (auto it : uv)
        cout << it << " ";
    cout << endl;
}
void intersectionArray(vector<int> v1, vector<int> v2)
{
    vector<int> iv;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
            i++;
        else if (v2[j] < v1[i])
            j++;
        else
        {
            iv.push_back(v2[j]);
            i++;
            j++;
        }
    }
    for (auto it : iv)
        cout << it << " ";
    cout << endl;
}
void missingNumSum(vector<int> v)
{
    int n = v.size() + 1, s1, s2 = 0;
    s1 = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++)
        s2 += v[i];
    cout << (s1 - s2) << endl;
}
void missingNumXor(vector<int> v)
{
    int xor1 = 0, xor2 = 0, n = v.size();
    for (int i = 0; i < n; i++)
    {
        xor2 ^= v[i];
        xor1 ^= (i + 1);
    }
    xor1 ^= n + 1;
    cout << (xor1 ^ xor2) << endl;
}
void consequtiveOnes(vector<int> v)
{
    int m = 0, c = 0, n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            c++;
            m = max(m, c);
        }
        else
            c = 0;
    }
    cout << m << endl;
}
void oneFrequency(vector<int> v)
{
    int XOR = 0, n = v.size();
    for (int i = 0; i < n; i++)
        XOR ^= v[i];
    cout << XOR << endl;
}
void mergeIntervals(vector<vector<int>> v)
{
    int n = v.size();
    vector<vector<int>> ans;
    int s = v[0][0];
    int e = v[0][1];
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] <= e)
            e = max(v[i][1], e);
        else
        {
            ans.push_back({s, e});
            s = v[i][0];
            e = v[i][1];
        }
    }
    ans.push_back({s, e});
    for (auto itr : ans)
    {
        for (auto it : itr)
            cout << "[" << it << "," << "]";
        cout << endl;
    }
}
void mergeSortedBetter(vector<int> v1, vector<int> v2)
{
    int n = v1.size(), m = v2.size();
    int l = n - 1, r = 0;
    while (l >= 0 && r < m)
    {
        if (v1[l] > v2[r])
        {
            swap(v1[l], v2[r]);
            l--;
            r++;
        }
        else
            break;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
}
void swapGreater(vector<int> &v1, vector<int> &v2, int l, int r)
{
    if (v1[l] > v2[r])
        swap(v1[l], v2[r]);
}
void mergeSortedOptimal(vector<int> v1, vector<int> v2)
{
    int n = v1.size(), m = v2.size(), len = n + m;
    int gap = (len / 2) + (len % 2);
    while (gap > 0)
    {
        int l = 0;
        int r = l + gap;
        while (r < len)
        {

            if (l < n && r >= n)
                swapGreater(v1, v2, l, r - n);
            else if (l >= n)
                swapGreater(v2, v2, l - n, r - n);
            else
                swapGreater(v1, v1, l, r);
            l++;
            r--;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
    for (auto it : v1)
        cout << it << " ";
    for (auto it : v2)
        cout << it << " ";
    cout << endl;
}
void missRepeat(vector<int> v)
{
    int n = v.size(), XOR = 0;
    for (int i = 0; i < n; i++)
    {
        XOR ^= v[i];
        XOR ^= (i + 1);
    }
    int setBit = 0;
    while (true)
    {
        if ((XOR & (1 << setBit)) != 0)
            break;
        setBit++;
    }
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++)
    {
        if ((v[i] & (1 << setBit)) != 0)
            one ^= v[i];
        else
            zero ^= v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if ((i & (1 << setBit)) != 0)
            one ^= i;
        else
            zero ^= i;
    }
    int c = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == zero)
            c++;
    if (!c)
        cout << "Missing " << zero << " | " << "Repeating " << one << endl;
    else
        cout << "Missing " << one << " | " << "Repeating " << zero << endl;
}
int mergeInv(vector<int> &v, int l, int m, int r)
{
    int cnt = 0;
    vector<int> mv;
    int i = l, j = m + 1;
    while (i <= m && j <= r)
    {
        if (v[i] <= v[j])
        {
            mv.push_back(v[i]);
            i++;
        }
        else
        {
            mv.push_back(v[j]);
            cnt += (m - i + 1);
            j++;
        }
    }
    while (i <= m)
    {
        mv.push_back(v[i]);
        i++;
    }
    while (j <= r)
    {
        mv.push_back(v[j]);
        j++;
    }
    for (int k = l; k <= r; k++)
        v[k] = mv[k - l];
    return cnt;
}
int mergesortInv(vector<int> &v, int l, int r)
{
    int cnt = 0;
    if (l >= r)
        return cnt;
    int m = (l + r) / 2;
    cnt += mergesortInv(v, l, m);
    cnt += mergesortInv(v, m + 1, r);
    cnt += mergeInv(v, l, m, r);
    return cnt;
}
void inversions(vector<int> v)
{
    int n = v.size();
    cout << mergesortInv(v, 0, n - 1) << endl;
}
int countPairs(vector<int> v, int low, int m, int high)
{
    int r = m + 1, c = 0;
    for (int i = low; i <= m; i++)
    {
        while (r <= high && v[i] > 2 * v[r])
            r++;
        c += (r - (m + 1));
    }
    return c;
}
void mergeRev(vector<int> &v, int l, int m, int r)
{
    vector<int> mv;
    int i = l, j = m + 1;
    while (i <= m && j <= r)
    {
        if (v[i] <= v[j])
        {
            mv.push_back(v[i]);
            i++;
        }
        else
        {
            mv.push_back(v[j]);
            j++;
        }
    }
    while (i <= m)
    {
        mv.push_back(v[i]);
        i++;
    }
    while (j <= r)
    {
        mv.push_back(v[j]);
        j++;
    }
    for (int k = l; k <= r; k++)
        v[k] = mv[k - l];
}
int mergesortRev(vector<int> &v, int l, int r)
{
    int cnt = 0;
    if (l >= r)
        return cnt;
    int m = (l + r) / 2;
    cnt += mergesortRev(v, l, m);
    cnt += mergesortRev(v, m + 1, r);
    cnt += countPairs(v, l, m, r);
    mergeRev(v, l, m, r);
    return cnt;
}
void reversePairs(vector<int> v)
{
    int n = v.size();
    cout << mergesortRev(v, 0, n - 1);
}
