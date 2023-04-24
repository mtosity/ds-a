#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vn, vm;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        vn.push_back(value);
    }
    for (int i = 0; i < m; i++)
    {
        int value;
        cin >> value;
        vm.push_back(value);
    }

    int i = 0, j = 0, count = 0;
    while (i < n && j < m)
    {
        if (vm[j] >= vn[i])
        {
            count += 1;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    cout << n - count;

    return 0;
}
