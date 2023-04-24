#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
using namespace std;

#define ll long long

int main()
{
    long long n = 8;
    cin >> n;
    vector<long long> v;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        v.push_back(value);
    }
    sort(v.begin(), v.end());

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    if (n % 2 == 0)
    {
        float m = (v[n / 2] + v[n / 2 + 1]) / 2;
        cout << m;
    }
    else
    {
        cout << v[n / 2];
    }

    return 0;
}