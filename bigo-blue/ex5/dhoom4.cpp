#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

typedef long long ll;

using namespace std;
const long mod = 100000;

int main()
{
    long n, key, num, a;
    cin >> n >> key;
    cin >> num;
    vector<long> keylist;
    while (num--)
    {
        cin >> a;
        keylist.push_back(a);
    }
    queue<long> q;
    q.push(n);
    long count[100001];
    for (int i = 0; i <= 100000; i++)
    {
        count[i] = -1; // nonvisited mean -1,it's not possible to make i
    }
    count[n] = 0;
    while (!q.empty())
    {
        long next = q.front();
        if (next == key)
        {
            break;
        }
        q.pop();

        for (int i = 0; i < keylist.size(); i++)
        {
            long transformed = (next * keylist[i]) % mod;
            if (count[transformed] == -1)
            {
                q.push(transformed);
                count[transformed] = count[next] + 1;
            }
        }
    }

    cout << count[key] << endl;
    return 0;
}