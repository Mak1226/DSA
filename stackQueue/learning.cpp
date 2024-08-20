#include <bits/stdc++.h>
using namespace std;

void displayStack(stack<int> st);
void displayStackPair(stack<pair<int, int>> st);
void minStackPair(int operation, int val);
void minStack(int operation, int val);
void stackInput(vector<int> v, bool flag);
void clearStack();

stack<int> st;
stack<pair<int, int>> stp;

int main()
{
    cout << "Test Case 1" << endl;
    stackInput({1, 10, 1, 12, 1, 13, 2, 1, 13, 1, 14, 1, 15, 2, 2, 4}, false);
    clearStack();
    cout << "Test Case 2" << endl;
    stackInput({2, 2, 1, 11, 1, 12, 3, 2, 1, 13, 3, 4, 2, 2}, true);
    return 0;
}

void clearStack()
{
    st = {};
    stp = {};
}
void stackInput(vector<int> v, bool flag)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        switch (v[i])
        {
        case 1:
        {
            int val = v[++i];
            if (flag)
                minStack(1, val);
            else
                minStackPair(1, val);
            break;
        }
        case 2:
        {
            if (flag)
                minStack(2, -1);
            else
                minStackPair(2, -1);
            break;
        }
        case 3:
        {
            if (flag)
                minStack(3, -1);
            else
                minStackPair(2, -1);
            break;
        }
        case 4:
        {
            if (flag)
                minStack(4, -1);
            else
                minStackPair(4, -1);
            break;
        }
        }
    }
}
void displayStackPair(stack<pair<int, int>> s)
{
    vector<int> v;
    while (!s.empty())
    {
        v.push_back(s.top().first);
        s.pop();
    }
    for (auto it = v.rbegin(); it != v.rend(); it++)
        cout << *it << " ";
    cout << endl;
}
void displayStack(stack<int> s)
{
    vector<int> v;
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    for (auto it = v.rbegin(); it != v.rend(); it++)
        cout << *it << " ";
    cout << endl;
}
void minStackPair(int operation, int val)
{
    switch (operation)
    {
    case 1:
        cout << "Push" << endl;
        if (stp.empty())
            stp.push({val, val});
        else
            stp.push({val, min(val, stp.top().second)});
        displayStackPair(stp);
        break;
    case 2:
        cout << "Pop" << endl;
        if (stp.empty())
            cout << -1 << endl;
        else
        {
            cout << stp.top().first << endl;
            stp.pop();
        }
        displayStackPair(stp);
        break;
    case 3:
        cout << "Top" << endl;
        if (stp.empty())
            cout << -1 << endl;
        else
            cout << stp.top().first << endl;
        break;
    case 4:
        cout << "Min" << endl;
        if (stp.empty())
            cout << -1 << endl;
        else
            cout << stp.top().second << endl;
        break;
    default:
        break;
    }
}
void minStack(int operation, int val)
{
    int Min;
    switch (operation)
    {
    case 1:
        cout << "Push" << endl;
        if (st.empty())
        {
            st.push(val);
            Min = val;
        }
        else
        {
            if (val > Min)
                st.push(val);
            else
            {
                st.push(2 * val - Min);
                Min = val;
            }
        }
        displayStack(st);
        break;
    case 2:
        cout << "Pop" << endl;
        if (st.empty())
            cout << -1 << endl;
        else
        {
            if (st.top() > Min)
                cout << st.top() << endl;
            else
            {
                cout << Min << endl;
                Min = 2 * Min - st.top();
            }
            st.pop();
        }
        displayStack(st);
        break;
    case 3:
        cout << "Top" << endl;
        if (st.empty())
            cout << -1 << endl;
        else
        {
            if (st.top() > Min)
                cout << st.top() << endl;
            else
                cout << Min << endl;
        }
        break;
    case 4:
        cout << "Min" << endl;
        if (st.empty())
            cout << -1 << endl;
        else
            cout << Min << endl;
        break;
    default:
        break;
    }
}