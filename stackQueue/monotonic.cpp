#include <bits/stdc++.h>
using namespace std;

void nextGreaterElementI(vector<int> v);
void nextGreaterElementII(vector<int> v);
void previousSmallerElement(vector<int> v);
void ngeToRight(vector<int> v, int q, vector<int> ind);
void trappingRainWaterI(vector<int> v);
void trappingRainWaterII(vector<int> v);
void subarrayMinSum(vector<int> v);
void subarrayMaxSum(vector<int> v);
void subarraySumRange(vector<int> v);
void asteroidCollision(vector<int> v);

int main()
{
    int choice;
    cout << "1.Next Greater Element I\n"
            "2.Next Greater Element II\n"
            "3.Previous Smaller Element\n"
            "4.Next Greatest Element to right\n"
            "Trapping RainWater"
         << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "Test Case 1" << endl;
        cout << "6 0 8 1 3" << endl;
        nextGreaterElementI({6, 0, 8, 1, 3});
        cout << "Test Case 2" << endl;
        cout << "4 12 5 3 1 2 5 3 1 2 4 6" << endl;
        nextGreaterElementI({4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6});
        break;
    }
    case 2:
    {
        cout << "Test Case 1" << endl;
        cout << "2 10 12 1 11" << endl;
        nextGreaterElementII({2, 10, 12, 1, 11});
        cout << "Test Case 2" << endl;
        cout << "" << endl;
        nextGreaterElementII({});
        break;
    }
    case 3:
    {
        cout << "Test Case 1" << endl;
        cout << "4 5 2 10 8" << endl;
        previousSmallerElement({4, 5, 2, 10, 8});
        cout << "Test Case 2" << endl;
        cout << "5 7 9 6 7 4 5 1 3 7" << endl;
        previousSmallerElement({5, 7, 9, 6, 7, 4, 5, 1, 3, 7});
        break;
    }
    default:
        break;
    }
    return 0;
}

void nextGreaterElementI(vector<int> v)
{
    stack<int> st;
    int n = v.size();
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= v[i])
            st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(v[i]);
    }
    for (int it : ans)
        cout << it << " ";
    cout << endl;
}
void nextGreaterElementII(vector<int> v)
{
    stack<int> st;
    int n = v.size();
    vector<int> ans(n);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= v[i % n])
            st.pop();
        if (i < n)
            ans[i] = st.empty() ? -1 : st.top();
        st.push(v[i]);
    }
    for (int it : ans)
        cout << it << " ";
    cout << endl;
}
void previousSmallerElement(vector<int> v)
{
    stack<int> st;
    vector<int> ans;
    for (int it : v)
    {
        while (!st.empty() && st.top() >= it)
            st.pop();
        ans.push_back(st.empty() ? -1 : st.top());
        st.push(it);
    }
    for (int it : ans)
        cout << it << " ";
    cout << endl;
}
void ngeToRight(vector<int> v, int q, vector<int> ind)
{
    int j = 0, n = v.size();
    stack<int> st;
    vector<int> ans;
    while (q--)
    {
        int x = ind[j++], e = v[x], c = 0;
        for (int i = x; i < n; i++)
            if (v[i] > e)
                c++;
        ans.push_back(c);
    }
    for (int it : ans)
        cout << it << " ";
    cout << endl;
}
void trappingRainWaterI(vector<int> v)
{
    int n = v.size(), t = 0;
    vector<int> p(n), s(n);
    p[0] = v[0], s[n - 1] = v[n - 1];
    for (int i = 1; i < n; i++)
        p[i] = max(p[i - 1], v[i]);
    for (int i = n - 2; i >= 0; i--)
        s[i] = max(s[i + 1], v[i]);

    for (int i = 0; i < n; i++)
        if (v[i] < p[i] && v[i] < s[i])
            t += max(p[i], s[i]) - v[i];

    cout << t << endl;
}
void trappingRainWaterII(vector<int> v)
{
    int n = v.size(), t = 0;
    int l = 0, r = n - 1;
    int lmax = 0, rmax = 0;
    while (l != r)
    {
        if (v[l] < v[r])
        {
            if (lmax > v[l])
                t += lmax - v[l];
            else
                lmax = v[l];
            l++;
        }
        else
        {
            if (rmax > v[r])
                t += rmax - v[r];
            else
                rmax = v[r];
            r--;
        }
    }
    cout << t << endl;
}
vector<int> nextSmallerElementIndex(vector<int> v)
{
    stack<int> st;
    vector<int> ans;
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && v[st.top()] > v[i])
            st.pop();
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}
vector<int> previousSmallerEqualsToElementIndex(vector<int> v)
{
    stack<int> st;
    vector<int> ans;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && v[st.top()] >= v[i])
            st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}
void subarrayMinSum(vector<int> v)
{
    vector<int> n = nextSmallerElementIndex(v);
    vector<int> p = previousSmallerEqualsToElementIndex(v);
    long long sum = 0;
    int lnt = v.size();
    for (int i = 0; i < lnt; i++)
    {
        int l = i - p[i];
        int r = n[i] - i;
        sum += 1LL * l * r * v[i];
    }
    cout << sum << endl;
}
vector<int> nextGreaterElementIndex(vector<int> v)
{
    stack<int> st;
    vector<int> ans;
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && v[st.top()] < v[i])
            st.pop();
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}
vector<int> previousGreaterEqualsToElementIndex(vector<int> v)
{
    stack<int> st;
    vector<int> ans;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && v[st.top()] <= v[i])
            st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}
void subarrayMaxSum(vector<int> v)
{
    vector<int> n = nextGreaterElementIndex(v);
    vector<int> p = previousGreaterEqualsToElementIndex(v);
    long long sum = 0;
    int lnt = v.size();
    for (int i = 0; i < lnt; i++)
    {
        int l = i - p[i];
        int r = n[i] - i;
        sum += 1LL * l * r * v[i];
    }
    cout << sum << endl;
}
void subarraySumRange(vector<int> v)
{
    subarrayMaxSum(v);
    subarrayMinSum(v);
}
void asteroidCollision(vector<int> v)
{
    int n = v.size();
    vector<int> st;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
            st.push_back(v[i]);
        else
        {
            while (!st.empty() && st.back() > 0 && st.back() < abs(v[i]))
                st.pop_back();
            if (!st.empty() && st.back() == abs(v[i]))
                st.pop_back();
            if (st.empty() || st.back() < 0)
                st.push_back(v[i]);
        }
    }
    for (int it : st)
        cout << it << " ";
    cout << endl;
}
void removeKElements(vector<int> v)
{
    
}