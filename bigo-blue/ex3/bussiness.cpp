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
    int k, total(0);
    vector<int> a(12);
    cin >> k;
    for (size_t i = 0; i < 12; ++i)
    {
        cin >> a[i];
        total += a[i];
    }

    if (total < k)
    {
        cout << -1 << endl;
    }
    else
    {
        sort(a.begin(), a.end(), greater<int>());
        int sum = 0;
        int month = 0;
        while (sum < k)
        {
            sum += a[month];
            month += 1;
        }
        cout << month << endl;
    }

    return 0;
}
