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
    long long first, have, num;
    cin >> first >> have >> num;

    long long m = 0;
    for (int i = 0; i < num; i++)
    {
        m += (i + 1) * first;
    }

    if (m <= have)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << m - have;
    }

    return 0;
}