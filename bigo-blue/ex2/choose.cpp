#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        v.push_back(value);
    }

    int l = 0, r = n - 1, first = 0, sec = 0, i = 0;
    while (l <= r)
    {
        if (v[l] > v[r])
        {
            if (i % 2 == 0)
            {
                first += v[l];
            }
            else
            {
                sec += v[l];
            }

            l++;
        }
        else
        {
            if (i % 2 == 0)
            {
                first += v[r];
            }
            else
            {
                sec += v[r];
            }

            r--;
        }
        i++;
    }

    cout << first << " " << sec;

    return 0;
}
