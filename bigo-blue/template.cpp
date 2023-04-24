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

bool option_x(vector<long long> p1, vector<long long> p2)
{
    return p1[0] > p2[0];
}

bool option_y(vector<long long> p1, vector<long long> p2)
{
    return p1[1] > p2[1];
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

    return 0;
}