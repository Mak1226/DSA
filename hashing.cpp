// Hashing

#include <bits/stdc++.h>
using namespace std;
void integer_hash(int n);
void character_hash(char ch);
void letter_hash(char ch);
void hash_map(int n);
int main()
{
    integer_hash(67);
    character_hash('%');
    letter_hash('k');
    hash_map(34);
    return 0;
}
void integer_hash(int n)
{
    int hash[100000] = {0};
    int arr[] = {1, 2, 4, 67, 4, 2, 45, 67, 34, 5663, 567, 453, 5, 67, 23, 65, 34, 756, 34565, 743};
    for (auto it : arr)
        hash[it]++;
    cout << hash[n] << endl;
}
void character_hash(char ch)
{
    string s = "aAb%%569sK";
    int n = ch;
    int hash[256] = {0};
    for (auto it : s)
        hash[it]++;
    cout << hash[n] << endl;
}
void letter_hash(char ch)
{
    string s = "sldkjobiowesdflsakdwerhjsksk";
    int n = ch;
    int hash[26] = {0};
    for (auto it : s)
        hash[it - 'a']++;
    cout << hash[n - 'a'] << endl;
}
void hash_map(int n)
{
    map<int,int> mp;
    int arr[] = {1, 2, 4, 67, 4, 2, 45, 67, 34, 5663, 567, 453, 5, 67, 23, 65, 34, 756, 34565, 743};
    for(auto it: arr)
        mp[it]++;
    cout << mp[n] << endl;
}