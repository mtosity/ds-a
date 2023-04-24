#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        v.push_back(value);
    }

    if (n < k)
    {
        cout << "-1 -1";
        return 0;
    }

    unordered_map<int, bool> m;
    int l = 0, r = 0, count = 0;
    while (r < n)
    {
        if (count == k)
        {
            // cout << l + 1 << " " << r;
            // return 0;
            break;
        }
        if (!m[v[r]])
        {
            count += 1;
            m[v[r]] = true;
        }
        if (v[r] == v[l] && l != r)
        {
            l += 1;
        }
        // cout << l << " " << r << " " << m.size() << endl;
        r += 1;
    }

    // if (count == k)
    // {
    //     cout << l + 1 << " " << r;
    //     return 0;
    // }

    if (count == k)
    {
        r = r - 1;
        while (r - l > 0 && v[l] == v[l + 1])
        {
            l += 1;
        }
        while (r - l > 0 && v[r] == v[r - 1])
        {
            r -= 1;
        }
        cout << l + 1 << " " << r + 1;
        return 0;
    }

    cout << "-1 -1";
    return 0;
}