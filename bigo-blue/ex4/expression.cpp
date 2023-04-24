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

int main()
{
    int total;
    cin >> total;
    vector<string> inp;
    for (int j = 0; j < total; j++)
    {
        string s;
        cin.ignore();
        getline(cin, s);
        inp.push_back(s);
    }

    for (int j = 0; j < total; j++)
    {
        string s = inp[j];
        cout << s << endl;
        int n = s.length();
        string result;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                result.push_back(s[i]);
            }

            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            {
                st.push(s[i]);
            }

            if (s[i] == ')')
            {
                char ch = st.top();
                st.pop();
                result += ch;
            }
        }

        while (st.empty())
        {
            char ch = st.top();
            st.pop();
            result += ch;
        }

        cout << result << endl;
    }

    return 0;
}