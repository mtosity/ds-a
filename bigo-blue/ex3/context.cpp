#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> v, v_sorted;
    for (int i = 0; i < n; i++)
    {
        long long value;
        cin >> value;
        v.push_back(value);
        v_sorted.push_back(value);
    }

    unordered_map<int, int> m_ratings;
    sort(v_sorted.begin(), v_sorted.end(), greater<long long>());
    int rank = 1;
    for (int i = 0; i < n; i++)
    {
        if (!m_ratings[v_sorted[i]])
        {
            m_ratings[v_sorted[i]] = rank;
        }

        rank++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << m_ratings[v[i]] << " ";
    }

    return 0;
}