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
    vector<long long> v;
    long long value = 999;
    do
    {
        cin >> value;
        if (value != 0)
        {
            v.push_back(value);
        }
    } while (value != 0);

    for (size_t i = 0; i < v.size(); i++)
    {
        int x;
        queue<int> s;
        for (int j = 1; j <= v[i]; j++)
        {
            s.push(j);
        }
        cout << "Discarded cards: ";
        while (s.size() > 1)
        {
            cout << s.front();
            s.pop();
            x = s.front();
            s.pop();
            if (!s.empty())
                cout << ", ";
            s.push(x);
        }

        cout << endl
             << "Remaining card: " << s.front() << endl;
    }

    return 0;
}