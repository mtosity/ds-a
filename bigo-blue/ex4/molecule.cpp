#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int getMass(char c)
{
    switch (c)
    {
    case 'H':
        return 1;
    case 'C':
        return 12;
    case 'O':
        return 16;
    case '(':
        return -1;
    case ')':
        return 0;
    default:
        return 0;
    }
}

int main()
{
    string s;
    getline(cin, s);
    int n = s.length();
    stack<int> st;
    stack<int> bracket;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(getMass(s[i]));
        }
        else if (s[i] == ')')
        {
            int v = getMass(s[i]), total = 0;
            while (v != getMass('('))
            {
                v = st.top();
                st.pop();
                if (v != getMass('('))
                {
                    total += v;
                }
            }
            st.push(total);
        }
        else if (s[i] == 'C' || s[i] == 'H' || s[i] == 'O')
        {
            st.push(getMass(s[i]));
        }
        else
        {
            int v = st.top();
            st.pop();
            st.push(v * (int)(s[i] - '0'));
        }
    }

    int res = 0;
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    cout << res << endl;

    return 0;
}