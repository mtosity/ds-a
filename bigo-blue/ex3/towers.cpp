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
    long long n;
    cin >> n;
    vector<long long> v;
    for (int i = 0; i < n; i++)
    {
        long long value;
        cin >> value;
        v.push_back(value);
    }

    sort(v.begin(), v.end());

    int last = -1, last_tall = 0, tall = 0, num = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != last)
        {
            if (last_tall > tall)
            {
                tall = last_tall;
                last_tall = 0;
            }
            num += 1;
            last = v[i];
            last_tall = 1;
        }
        else
        {
            last_tall += 1;
        }

        if (i == n - 1)
        {
            if (last_tall > tall)
            {
                tall = last_tall;
            }
        }
    }

    cout << tall << " " << num;

    return 0;
}