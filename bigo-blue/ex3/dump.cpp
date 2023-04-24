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
    int n, value, x;
    cin >> n >> x;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        time += (x * v[i]);
        if (x > 1)
        {
            x -= 1;
        }
    }

    cout << time;

    return 0;
}