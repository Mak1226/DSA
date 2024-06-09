// Bubblesort O(n*n)
// Selectionsort O(n*n)
// Insertionsort O(n*n)
// Mergesort O(nlogn)
// Quicksort O(nlogn)
// Recursive Bubblesort O(n*n)
// Recursive Insertionsort O(n*n)

#include <bits/stdc++.h>
using namespace std;
void bubblesort(vector<int> v);
void selectionsort(vector<int> v);
void insertionsort(vector<int> v);
void mergesort(vector<int> &v, int l, int r);
void quicksort(vector<int> &v, int l, int r);
void recursive_bubblesort(vector<int> &v, int n);
void recursive_insertionsort(vector<int> &v, int i, int n);
int main()
{
    vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> mv, qv, rb, ri;
    mv = qv = rb = ri = v;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Bubblesort" << endl;
        bubblesort(v);
        break;
    case 2:
        cout << "Selectionsort" << endl;
        selectionsort(v);
        break;
    case 3:
        cout << "Insertionsort" << endl;
        insertionsort(v);
        break;
    case 4:
        mergesort(mv, 0, mv.size() - 1);
        cout << "Mergesort" << endl;
        for (auto it : mv)
            cout << it << " ";
        cout << endl;
        break;
    case 5:
        quicksort(qv, 0, qv.size() - 1);
        cout << "Quicksort" << endl;
        for (auto it : qv)
            cout << it << " ";
        cout << endl;
        break;
    case 6:
        recursive_bubblesort(rb, mv.size());
        cout << "Recursive Bubblesort" << endl;
        for (auto it : rb)
            cout << it << " ";
        cout << endl;
        break;
    case 7:
        recursive_insertionsort(mv, 0, mv.size() - 1);
        cout << "Recursive Insertionsort" << endl;
        for (auto it : ri)
            cout << it << " ";
        cout << endl;
        break;
    default:
        break;
    }
    // bubblesort(v);
    // selectionsort(v);
    // insertionsort(v);
    // mergesort(mv, 0, mv.size() - 1);
    // quicksort(qv, 0, qv.size() - 1);
    // recursive_bubblesort(rb, rb.size());
    // recursive_insertionsort(iv, 0, iv.size());

    return 0;
}
void bubblesort(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);

    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
void selectionsort(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] <= m)
                m = j;
        }
        swap(v[m], v[i]);
    }
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
void insertionsort(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
void merge(vector<int> &v, int l, int m, int r)
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
    for (int x = l; x <= r; x++)
        v[x] = mv[x - l];
}
void mergesort(vector<int> &v, int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergesort(v, l, m);
    mergesort(v, m + 1, r);
    merge(v, l, m, r);
}
int partition(vector<int> &v, int l, int r)
{
    int p = v[l];
    int i = l, j = r;
    while (i < j)
    {
        while (v[i] <= p && i <= r - 1)
            i++;
        while (v[j] > p && j >= l + 1)
            j--;
        if (i < j)
            swap(v[i], v[j]);
    }
    swap(v[l], v[j]);
    return j;
}
void quicksort(vector<int> &v, int l, int r)
{
    if (l > r)
        return;
    int pivot = partition(v, l, r);
    quicksort(v, l, pivot - 1);
    quicksort(v, pivot + 1, r);
}
void recursive_bubblesort(vector<int> &v, int n)
{
    if (n == 1)
        return;

    for (int j = 0; j < n - 1; j++)
    {
        if (v[j] > v[j + 1])
            swap(v[j], v[j + 1]);
    }
    recursive_bubblesort(v, n - 1);
}
void recursive_insertionsort(vector<int> &v, int i, int n)
{
    if (i == n)
        return;
    int j = i;
    while (j > 0 && v[j - 1] > v[j])
    {
        swap(v[j - 1], v[j]);
        j--;
    }
    recursive_insertionsort(v, i + 1, n);
}