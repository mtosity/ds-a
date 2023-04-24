#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>

using namespace std;

template <typename T>
vector<T> readArray(int n)
{
    int value;
    vector<T> v;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        v.push_back(value);
    }

    return v;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > a;
    for (int i = 0; i < n; i++)
    {
        int value;
        vector<int> cor;
        cin >> value;
        cor.push_back(value);
        cin >> value;
        cor.push_back(value);
        a.push_back(cor);
    }

    int min = INT_MAX, max = 0, k = -1;
    bool red = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] < min)
        {
            min = a[i][0];
            red = true;
        }

        if (a[i][1] > max)
        {
            max = a[i][1];
            red = true;
        }

        if (a[i][0] <= min && a[i][1] >= max)
        {
            k = i;
            red = false;
        }
    }

    cout << (red ? -1 : k + 1);

    return 0;
}