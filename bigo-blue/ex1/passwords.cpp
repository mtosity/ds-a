#include <map>
#include <iostream>
#include <unordered_map>
#include <cassert>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>

using namespace std;

int main()
{
    int n, n_pen;
    cin >> n >> n_pen;
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int next_n = s.size();
        if (m.find(next_n) == m.end())
        {
            m[next_n] = 1;
        }
        else
        {
            m[next_n] += 1;
        }
    }

    string pass;
    cin >> pass;
    int pass_len = pass.size();
    int min = 0, max = 0;

    for (auto const &[key, value] : m)
    {
        if (key < pass_len)
        {
            min += value;
            max += value;
        }

        if (key == pass_len)
        {
            max += value;
        }
    }

    if (min != n_pen)
    {
        min += (min / n_pen) * 5;
    }

    if (max % n_pen == 0)
    {

        max += (max / n_pen - 1) * 5;
    }
    else
    {
        max += (max / n_pen) * 5;
    }

    cout << (min + 1) << " " << max;

    return 0;
}