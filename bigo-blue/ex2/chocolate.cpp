#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

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

    int l = 0, r = n - 1, diff = 0, cl = 0, cr = 0;
    //diff=l-r, diff > 0 -> r ăn tiếp, diff < 0 -> l ăn tiếp, diff == 0 -> cả 2 ăn
    while (l <= r)
    {
        if (diff == 0 && l < r)
        {
            diff += (v[l] - v[r]);
            l++;
            r--;
            cl++;
            cr++;
        }
        else if (diff > 0)
        {
            diff -= v[r];
            r--;
            cr++;
        }
        else
        {
            diff += v[l];
            l++;
            cl++;
        }
    }

    cout << cl << " " << cr;

    return 0;
}