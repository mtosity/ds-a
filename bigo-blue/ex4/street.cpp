#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    vector<queue<long long> > vv;
    vector<long long> vn;

    while (true)
    {
        long long value;
        cin >> value;
        if (value == 0)
        {
            break;
        }
        vn.push_back(value);

        queue<long long> q;
        int n = value;
        for (int i = 0; i < n; i++)
        {
            cin >> value;
            q.push(value);
        }
        vv.push_back(q);
    }

    int total = vv.size();
    for (int i = 0; i < total; i++)
    {
        int k = 1;
        int n = vn[i];
        queue<long long> q = vv[i];
        stack<long long> temp;
        bool can = true;

        while (!q.empty())
        {
            while (!temp.empty() && temp.top() == k)
            {
                temp.pop();
                k++;
            }

            long long head = q.front();
            q.pop();
            // cout << head << endl;
            if (head == k)
            {
                k++;
            }
            else if (!temp.empty() && temp.top() < head)
            {
                can = false;
                break;
            }
            else
            {
                // cout << head << endl;
                temp.push(head);
            }
        }

        if (can)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}