#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

string readString()
{
    string s;
    cin >> s;
    return s;
}

unordered_map<char, int> getStringMap(string a)
{
    unordered_map<char, int> m;
    for (int i = 0; i < a.size(); i++)
    {
        if (m.find(a[i]) == m.end())
        {
            m[a[i]] = 1;
        }
        else
        {
            m[a[i]] += 1;
        }
    }
    return m;
}

int main()
{
    string s = readString();
    string t = readString();

    string t_sorted = t, s_sorted = s;
    sort(t_sorted.begin(), t_sorted.end());
    sort(s_sorted.begin(), s_sorted.end());

    if (s.size() == t.size() && t_sorted == s_sorted)
    {
        cout << "array";
        return 0;
    }

    for (int i = 0; i <= s.size() - t.size(); i++)
    {
        string sub = s.substr(i, t.size());
        if (t == sub)
        {
            cout << "automaton";
            return 0;
        }

        int is = i, it = 0, count = 0, count_miss = 0;
        while (is < s.size() && it < t.size())
        {
            if (s[is] == t[it])
            {
                count++;
                is += 1;
                it += 1;
            }
            else
            {
                count_miss++;
                is += 1;
            }
        }

        if (count >= t.size())
        {
            cout << "automaton";
            return 0;
        }
    }

    unordered_map<char, int> ms = getStringMap(s);
    unordered_map<char, int> mt = getStringMap(t);

    for (auto const &[key, value] : mt)
    {
        if (ms[key] < mt[key])
        {
            cout << "need tree";

            return 0;
        }
    }

    cout << "both";

    return 0;
}