#include <bits/stdc++.h>
using namespace std;

void prefix2Infix(string s);
void prefix2Postfix(string s);
void infix2Postfix(string s);
void infix2Prefix(string s);
void postfix2Prefix(string s);
void postfix2Infix(string s);

int main()
{
    int choice;
    cout << "1.Pre -> In\n"
            "2.Pre -> Post\n"
            "3.In -> Post\n"
            "4.In -> Pre\n"
            "5.Post -> Pre\n"
            "6.Post -> In"
         << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "Test Case 1" << endl;
        prefix2Infix("");
        cout << "Test Case 2" << endl;
        prefix2Infix("");
        break;
    }
    case 2:
    {
        cout << "Test Case 1" << endl;
        prefix2Postfix("");
        cout << "Test Case 2" << endl;
        prefix2Postfix("");
        break;
    }
    case 3:
    {
        cout << "Test Case 1" << endl;
        cout << "Expression: a+b*(c^d-e)^(f+g*h)-i\n"
                "Expected: abcd^e-fgh*+^*+i-"
             << endl;
        infix2Postfix("a+b*(c^d-e)^(f+g*h)-i");
        cout << "Test Case 2" << endl;
        cout << "Expression: (p+q)*(m-n)\n"
                "Expected: pq+mn-*"
             << endl;
        infix2Postfix("(p+q)*(m-n)");
        break;
    }
    case 4:
    {
        cout << "Test Case 1" << endl;
        cout << "Expression: x+y*z/w+u\n"
                "Expected: ++x/*yzwu"
             << endl;
        infix2Prefix("x+y*z/w+u");
        cout << "Test Case 2" << endl;
        cout << "Expression: a+b\n"
                "Expected: +ab"
             << endl;
        infix2Prefix("a+b");
        break;
    }
    case 5:
    {
        cout << "Test Case 1" << endl;
        postfix2Prefix("");
        cout << "Test Case 2" << endl;
        postfix2Prefix("");
        break;
    }
    case 6:
    {
        cout << "Test Case 1" << endl;
        postfix2Infix("");
        cout << "Test Case 2" << endl;
        postfix2Infix("");
        break;
    }
    default:
        break;
    }
    return 0;
}

bool isOperand(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return true;
    else if (ch >= 'a' && ch <= 'z')
        return true;
    else if (ch >= '0' && ch <= '9')
        return true;
    else
        return false;
}
int presidence(char ch)

{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}
string reverseString(string s)
{
    string ans = "";
    for (char ch : s)
    {
        if (ch == '(')
            ans = ')' + ans;
        else if (ch == ')')
            ans = '(' + ans;
        else
            ans = ch + ans;
    }
    return ans;
}

void prefix2Infix(string s)
{
    stack<string> st;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        char ch = s[i];
        if (isOperand(ch))
            st.push(string(1, ch));
        else
        {
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();
            st.push('(' + first + ch + second + ')');
        }
    }
    string top = st.top();
    st.pop();
    cout << top << endl;
}
void prefix2Postfix(string s)
{
    stack<string> st;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        char ch = s[i];
        if (isOperand(ch))
            st.push(string(1, ch));
        else
        {
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();
            st.push(first + second + ch);
        }
    }
    string top = st.top();
    st.pop();
    cout << top << endl;
}
void infix2Postfix(string s)
{
    stack<char> st;
    string ans = "";
    for (char ch : s)
    {
        if (isOperand(ch))
            ans += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && presidence(ch) <= presidence(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    cout << ans << endl;
}
void infix2Prefix(string s)
{
    stack<char> st;
    string ans = "";
    string str = reverseString(s);
    for (char ch : str)
    {
        if (isOperand(ch))
            ans += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (ch == '^')
                while (!st.empty() && presidence(ch) <= presidence(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            else
                while (!st.empty() && presidence(ch) < presidence(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
void postfix2Prefix(string s)
{
    stack<string> st;
    for (char ch : s)
    {
        if (isOperand(ch))
            st.push(string(1, ch));
        else
        {
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();
            st.push(ch + second + first);
        }
    }
    string top = st.top();
    st.pop();
    cout << top << endl;
}
void postfix2Infix(string s)
{
    stack<string> st;
    for (char ch : s)
    {
        if (isOperand(ch))
            st.push(string(1, ch));
        else
        {
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();
            st.push('(' + second + ch + first + ')');
        }
    }
    string top = st.top();
    st.pop();
    cout << top << endl;
}
