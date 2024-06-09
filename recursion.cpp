// Recursive Sum Parametrized and Functional
// Recursive Factorial O(N)
// Reverse Array
// Palindrome string
// Fibonacci O(2^n)

#include <bits/stdc++.h>
using namespace std;
void parameter_sum(int n, int s);
int functional_sum(int s);
int factorial(int n);
void reverse_array(int arr[], int l, int r);
bool palindrome_string(string s, int i, int l);
int fibonacci(int k);

int main()
{
    int n = 5, p_sum = 0;
    int arr[] = {1, 2, 3, 4, 5};
    // cin >> n;
    parameter_sum(n, p_sum);
    cout << functional_sum(n) << endl;
    cout << factorial(n) << endl;
    reverse_array(arr, 0, 5);
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
    string s = "madam";
    cout << palindrome_string(s, 0, s.size()) << endl;
    cout << fibonacci(n) << endl;
    return 0;
}
void parameter_sum(int n, int s)
{
    if (n < 1)
    {
        cout << s << endl;
        return;
    }
    parameter_sum(n - 1, s + n);
}
int functional_sum(int n)
{
    if (n == 0)
        return 0;
    return n + functional_sum(n - 1);
}
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
void reverse_array(int arr[], int l, int r)
{
    if (l >= r / 2)
        return;
    swap(arr[l], arr[r - l - 1]);
    reverse_array(arr, l + 1, r);
}
bool palindrome_string(string s, int i, int l)
{
    if (i >= l / 2)
        return true;
    if (s[i] != s[l - i - 1])
        return false;
    return palindrome_string(s, i + 1, l);
}
int fibonacci(int k)
{
    if(k<=1)
        return k;
    return fibonacci(k-1) + fibonacci(k-2);
}