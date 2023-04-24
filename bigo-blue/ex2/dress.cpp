#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>

using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
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

    int i = 0, j = 0;
    vector<vector<int> > results;
    while (i < n && j < m)
    {
        if (vm[j] >= vn[i] - x && vm[j] <= vn[i] + y)
        {
            vector<int> result;
            result.push_back(i + 1);
            result.push_back(j + 1);
            results.push_back(result);
            i++;
            j++;
        }
        else if (vm[j] < vn[i] - x)
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    cout << results.size() << endl;
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i][0] << " " << results[i][1] << endl;
    }

    return 0;
}