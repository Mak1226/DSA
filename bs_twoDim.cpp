#include <bits/stdc++.h>
using namespace std;

void maxOnes(vector<vector<int>> v);
void search2DMatrix(vector<vector<int>> v, int target);
void search2DUnsorted(vector<vector<int>> v, int target);
void peakElement2D(vector<vector<int>> v);
void medianSortedMatrix(vector<vector<int>> v);

int main()
{
    int choice, custom;
    cout << "1.MaxOnes\n2.Search\n3.Search row in col-sorted\n4.Peak\n5.Median" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Test Case 1:" << endl;
        cout << "1 1 1\n0 0 1\n0 0 0" << endl;
        maxOnes({{1, 1, 1}, {0, 0, 1}, {0, 0, 0}});
        cout << "Test Case 2:" << endl;
        cout << "0 0\n0 0" << endl;
        maxOnes({{0, 0}, {0, 0}});
        break;
    case 2:
        cout << "Test Case 1:" << endl;
        cout << "1 2 3 4\n5 6 7 8\n9 10 11 12\n13 14 15 16\nTarget: 8" << endl;
        search2DMatrix({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}, 8);
        cout << "Test Case 2:" << endl;
        cout << "1 2 4\n6 7 8\n9 10 34\nTarget: 78" << endl;
        search2DMatrix({{1, 2, 4}, {6, 7, 8}, {9, 10, 34}}, 78);
        break;
    case 3:
        cout << "Test Case 1:" << endl;
        cout << "1 4 7 11 15\n2 5 8 12 19\n3 6 9 16 22\n10 13 14 17 24\n18 21 23 26 30\nTarget: 5" << endl;
        search2DUnsorted({{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}, 5);
        cout << "1 4 7 11 15\n2 5 8 12 19\n3 6 9 16 22\n10 13 14 17 24\n18 21 23 26 30\nTarget: 20" << endl;
        search2DUnsorted({{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}, 20);
        break;
    default:
        break;
    }
    return 0;
}

int lowerBoundOccur(vector<int> v, int target)
{
    int n = v.size();
    int l = 0, r = n - 1, ans = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v{m] >= target)
            {
                ans = m;
                r = m - 1;
            }
            else l = m + 1;
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
        for (auto it : v)
            c += upperBoundOccur(it, mid);
        return c;
    }
    void medianSortedMatrix(vector<vector<int>> v)
    {
        int n = v.size(), m = v[0].size();
        int l = INT_MAX, r = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            l = min(l, v[i][0]);
            r = max(r, v[i][m - 1]);
        }
        int rem = (n * m) / 2;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int smallerThanEqualsTo = findSmallEqual(v, mid);
            if (smallerThanEqualsTo <= rem)
                l = mid + 1;
            else
                r = mid - 1;
        }
        cout << l << endl;
    }
