#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool option_x(vector<long long> p1, vector<long long> p2)
{
    return p1[0] < p2[0];
}

bool option_y(vector<long long> p1, vector<long long> p2)
{
    return p1[1] < p2[1];
}

int main()
{
    long long n = 8;
    vector<vector<long long> > v, vx, vy;
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        vector<long long> p;
        p.push_back(x);
        p.push_back(y);
        v.push_back(p);
        vx.push_back(p);
        vy.push_back(p);
    }

    sort(vx.begin(), vx.end(), option_x);
    sort(vy.begin(), vy.end(), option_y);

    if (vx[0][0] != vx[1][0] || vx[1][0] != vx[2][0] ||
        vy[0][1] != vy[1][1] || vy[1][1] != vy[2][1] ||
        vx[5][0] != vx[6][0] || vx[6][0] != vx[7][0] ||
        vy[5][1] != vy[6][1] || vy[6][1] != vy[7][1])
    {
        cout << "ugly";
        return 0;
    }

    if (vx[3][0] != vx[4][0] || vx[3][0] <= vx[2][0] || vx[3][0] >= vx[5][0])
    {
        cout << "ugly";
        return 0;
    }

    if (vy[3][1] != vy[4][1] || vy[3][1] <= vy[2][1] || vy[3][1] >= vy[5][1])
    {
        cout << "ugly";
        return 0;
    }

    cout << "respectable";
    return 0;
}