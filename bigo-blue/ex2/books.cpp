#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>

using namespace std;

template <typename T>
vector<T> readArray()
{
    int n, value;
    cin >> n;
    vector<T> v;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        v.push_back(value);
    }

    return v;
}

string readString()
{
    string s;
    getline(cin, s);
    return s;
}

int main()
{
    int n, t;
    cin >> n >> t;
    if (t == 0 || n == 0)
    {
        cout << 0;
        return 0;
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        v.push_back(value);
    }

    int l = 0, r = 0, sum = 0, max = 0;
    while (r < n)
    {
        sum += v[r];
        if (sum > t && l < r)
        {
            sum -= v[l];
            l++;
        }
        if (sum <= t && r - l + 1 > max)
        {
            max = r - l + 1;
        }
        r++;
    }

    cout << max;

    return 0;
}