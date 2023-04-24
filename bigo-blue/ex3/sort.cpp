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

    vector<long long> v_sorted(v);
    sort(v_sorted.begin(), v_sorted.end());
    int l = 0, r = n - 1;
    while (l < n)
    {
        if (v[l] == v_sorted[l])
        {
            l++;
        }
        else
        {
            break;
        }
    }
    while (r >= 0)
    {
        if (v[r] == v_sorted[r])
        {
            r--;
        }
        else
        {
            break;
        }
    }

    if (l >= n || r <= 0)
    {
        cout << "yes" << endl;
        cout << 1 << " " << 1;
        return 0;
    }

    reverse(v.begin() + l, v.begin() + r + 1);

    for (int i = 0; i < n; i++)
    {
        if (v[i] != v_sorted[i])
        {
            cout << "no";
            return 0;
        }
    }

    cout << "yes" << endl;
    cout << l + 1 << " " << r + 1;

    return 0;
}