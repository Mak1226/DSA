// 2 Sum O(n)
// Sort Array with 0s 1s 2s O(n)
// Moore's Voting Algorithm O(n)
// Maximun Subarray Sum - Kadane Algorithm O(n)
// Rearrange Array with +ve and -ve O(2n)
// Next Permutation O(3n)
// Leaders in array O(n)
// Longest Consequtive sequence Better = O(nlogn) | Optimal = O(3n)
// Mojority Element n/3 Better = O(n) | Optimal = O(2n)
// Three Sum Brute = O(N^3) | Better = O(N^2 * log M) | Optimal = O(nlogn) + O(N^2)
// Four Sum Brute = O(N^4) | Better = O(N^3 * log M) | Optimal =  O(N^3)

#include <bits/stdc++.h>
using namespace std;
void twoSum(vector<int> v, int k);
void arraySort012(vector<int> v);
void mooreVotingAlgo(vector<int> v);
void KadaneAlgo(vector<int> v);
void rearrangePosAndNeg(vector<int> v);
void rearrangeUnequal(vector<int> v);
void nextPermutation(vector<int> v);
void leadersInArray(vector<int> v);
void consequtiveBetter(vector<int> v);
void consequtiveOptimal(vector<int> v);
void majorityElementBetter(vector<int> v);
void majorityElementOptimal(vector<int> v);
void threeSumBrute(vector<int> v);
void threeSumBetter(vector<int> v);
void threeSumOptimal(vector<int> v);
void fourSumBrute(vector<int> v, long long target);
void fourSumBetter(vector<int> v, long long target);
void fourSumOptimal(vector<int> v, long long target);

int main()
{
    twoSum({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 1);
    arraySort012({0, 1, 2, 2, 2, 1, 1, 0, 0, 0, 1, 1, 2, 1, 0});
    KadaneAlgo({-2, -3, 4, -1, -2, 1, 5, -3});
    rearrangePosAndNeg({-1, -2, -3, -4, 5, 6, 7, 8});
    rearrangeUnequal({-1, 2, -3, 4, 5, 6});
    nextPermutation({2, 1, 5, 4, 3, 0, 0});
    consequtiveBetter({0, 1, 1, 1, 2, 3, 4, 4, 5, 50, 51, 52});
    consequtiveOptimal({0, 1, 1, 1, 2, 3, 4, 4, 5, 50, 51, 52});
    majorityElementBetter({1, 2, 2, 3, 3, 3});
    majorityElementOptimal({1, 2, 2, 3, 3, 3});
    return 0;
}
void twoSum(vector<int> v, int k)
{
    map<int, int> mp;
    int l = v.size();
    bool flag = false;
    for (int i = 0; i < l; i++)
    {
        int rem = k - v[i];
        if (mp.find(rem) != mp.end() && mp[rem] != i)
        {
            cout << "YES " << "[" << mp[rem] << "," << i << "]" << endl;
            flag = true;
            break;
        }
        else
            mp[v[i]] = i;
    }
    if (!flag)
        cout << "NO" << endl;
}
void arraySort012(vector<int> v)
{
    int n = v.size();
    int l = 0, m = 0, h = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (v[m] == 0)
            swap(v[m++], v[l++]);
        else if (v[m] == 1)
            m++;
        else
            swap(v[m], v[h--]);
    }
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
void mooreVotingAlgo(vector<int> v)
{
    int e, n = v.size(), c = 0;
    for (int i = 0; i < n; i++)
    {
        if (c == 0)
        {
            e = v[i];
            c++;
        }
        else if (e == v[i])
            c++;
        else
            c--;
    }
    cout << e << endl;
    // Might have to verify the element
}
void KadaneAlgo(vector<int> v)
{
    int sum = 0, m = INT_MIN, n = v.size();
    int ansStart = -1, ansEnd = -1, tempStart = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum > m)
        {
            m = sum;
            ansStart = tempStart;
            ansEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
            tempStart = i + 1;
        }
    }
    cout << m << endl;
    for (int i = ansStart; i <= ansEnd; i++)
        cout << v[i] << " ";
    cout << endl;
}
void rearrangePosAndNeg(vector<int> v)
{
    int n = v.size(), pos = 0, neg = 1;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            ans[pos] = v[i];
            pos += 2;
        }
        else
        {
            ans[neg] = v[i];
            neg += 2;
        }
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}
void rearrangeUnequal(vector<int> v)
{
    vector<int> pos, neg;
    int n = v.size(), index;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
            pos.push_back(v[i]);
        else
            neg.push_back(v[i]);
    }
    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            v[2 * i] = pos[i];
            v[2 * i + 1] = neg[i];
        }
        index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
            v[index++] = pos[i];
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            v[2 * i] = pos[i];
            v[2 * i + 1] = neg[i];
        }
        index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
            v[index++] = neg[i];
    }
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
void nextPermutation(vector<int> v)
{
    int n = v.size(), ind = -1;
    for (int i = n - 2; i >= 0; i--)
        if (v[i] < v[i + 1])
        {
            ind = i;
            break;
        }
    if (ind == -1)
        reverse(v.begin(), v.end());
    else
    {
        for (int i = n - 1; i >= 0; i--)
            if (v[i] > v[ind])
            {
                swap(v[i], v[ind]);
                break;
            }
    }
    reverse(v.begin() + ind + 1, v.end());
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
void leadersInArray(vector<int> v)
{
    int n = v.size(), m = INT_MIN;
    set<int> st;
    for (int i = n - 1; i >= 0; i--)
        if (v[i] > m)
            st.insert(v[i]);
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
void consequtiveBetter(vector<int> v)
{
    int n = v.size(), s = INT_MIN, c = 0, l = 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i] - 1 == s)
        {
            s = v[i];
            c++;
        }
        else if (v[i] != s)
        {
            c = 1;
            s = v[i];
        }
        l = max(l, c);
    }
    cout << l << endl;
}
void consequtiveOptimal(vector<int> v)
{
    int n = v.size(), l = 1;
    unordered_set<int> st;
    if (n == 0)
        return;
    for (int i = 0; i < n; i++)
        st.insert(v[i]);
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int c = 1, curr = it;
            while (st.find(curr + 1) != st.end())
            {
                c++;
                curr++;
            }
            l = max(l, c);
        }
    }
    cout << l << endl;
}
void majorityElementBetter(vector<int> v)
{
    vector<int> ans;
    map<int, int> mp;
    int n = v.size();
    int m = (int)(n / 3) + 1;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
        if (mp[v[i]] == m)
            ans.push_back(v[i]);
        if (ans.size() == 2)
            break;
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}
void majorityElementOptimal(vector<int> v)
{
    vector<int> ans;
    int n = v.size(), c1 = 0, c2 = 0;
    int e1 = INT_MIN, e2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (c1 == 0 && e2 != v[i])
        {
            c1 = 1;
            e1 = v[i];
        }
        else if (c2 == 0 && e1 != v[i])
        {
            c2 = 1;
            e2 = v[i];
        }
        else if (e1 == v[i])
            c1++;
        else if (e2 == v[i])
            c2++;
        else
        {
            c1--;
            c2--;
        }
    }
    ans.push_back(e1);
    ans.push_back(e2);
    sort(ans.begin(), ans.end());
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}
void threeSumBrute(vector<int> v)
{
    int n = v.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (v[i] + v[j] + v[k] == 0)
                {
                    vector<int> temp = {v[i], v[j], v[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
    for (auto itr : st)
    {
        for (auto it : itr)
            cout << it << " ";
        cout << endl;
    }
}
void threeSumBetter(vector<int> v)
{
    int n = v.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hash;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(v[i] + v[j]);
            if (hash.find(third) != hash.end())
            {
                vector<int> temp = {v[i], v[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hash.insert(v[j]);
        }
    }
    for (auto itr : st)
    {
        for (auto it : itr)
            cout << it << " ";
        cout << endl;
    }
}
void threeSumOptimal(vector<int> v)
{
    int n = v.size();
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && v[i] == v[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int s = v[i] + v[j] + v[k];
            if (s > 0)
                k--;
            else if (s < 0)
                j++;
            else
            {
                vector<int> temp = {v[i], v[j], v[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && v[j] == v[j - 1])
                    j++;
                while (j < k && v[k] == v[k + 1])
                    k--;
            }
        }
        for (auto itr : ans)
        {
            for (auto it : itr)
                cout << it << " ";
            cout << endl;
        }
    }
}
void fourSumBrute(vector<int> v, long long target)
{
    int n = v.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = v[i] + v[j];
                    sum += v[k];
                    sum += v[l];
                    if (sum == target)
                    {
                        vector<int> temp = {v[i], v[j], v[k], v[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
    for (auto itr : st)
    {
        for (auto it : itr)
            cout << it << " ";
        cout << endl;
    }
}
void fourSumBetter(vector<int> v, long long target)
{
    int n = v.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hash;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = v[i] + v[j];
                sum += v[k];
                long long fourth = target - sum;
                if (hash.find(fourth) != hash.end())
                {
                    vector<int> temp = {v[i], v[j], v[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hash.insert(v[j]);
            }
        }
    }
    for (auto itr : st)
    {
        for (auto it : itr)
            cout << it << " ";
        cout << endl;
    }
}
void fourSumOptimal(vector<int> v, long long target)
{
    int n = v.size();
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && v[i] == v[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && v[j] == v[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long s = v[i] + v[j];
                s += v[k];
                s += v[l];
                if (s > target)
                    l--;
                else if (s < target)
                    k++;
                else
                {
                    vector<int> temp = {v[i], v[j], v[k], v[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k < l && v[k] == v[k - 1])
                        k++;
                    while (k < l && v[l] == v[l + 1])
                        l--;
                }
            }
        }
        for (auto itr : ans)
        {
            for (auto it : itr)
                cout << it << " ";
            cout << endl;
        }
    }
}
