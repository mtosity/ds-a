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
    int n, value;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        v.push_back(value);
    }

    int i = n - 1, count = 0;
    while (i >= 0)
    {
        if (v[i] == 0)
        {
            i--;
        }
        else
        {

            i -= (v[i] + 1);
        }
    }

    cout << (count + 1 > n ? n : count + 1);

    return 0;
}