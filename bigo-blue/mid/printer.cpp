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
    int t, n, m, x, i, j, v, idx;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        queue<int> Qv, Qidx;
        int inQ[10] = {};
        for (i = 0; i < n; i++)
        {
            cin >> x;
            Qv.push(x);
            Qidx.push(i);
            inQ[x]++;
        }
        int time = 0;
        while (true)
        {
            v = Qv.front(), Qv.pop();
            idx = Qidx.front(), Qidx.pop();

            int canPop(1);
            for (i = v + 1; i < 10; i++)
                canPop &= inQ[i] == 0;
            if (canPop)
            {
                time++;
                if (idx == m)
                {
                    cout << time << endl;
                    break;
                }
                inQ[v]--;
            }
            else
            {
                Qv.push(v), Qidx.push(idx);
            }
        }
    }
    return 0;
}
