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
    vector<int> vn;
    unordered_map<int, bool> mm;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        vn.push_back(value);
    }
    int max_m = 0;
    for (int i = 0; i < m; i++)
    {
        int value;
        cin >> value;
        if (value > max_m)
        {
            max_m = value;
        }
        mm[value] = true;
    }
    int count = 0;
    cout << max_m << endl;
    for (int i = 0; i < n; i++)
    {
        if (!mm[vn[i]] && vn[i] > max_m)
        {
            count += 1;
        }
    }
    cout << count;

    return 0;
}
