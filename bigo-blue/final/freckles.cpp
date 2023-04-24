#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Edge
{
    int n1;
    int n2;
    long double dist;
};

long double dist(pair<long double, long double> p1, pair<long double, long double> p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

bool cmp(Edge lhs, Edge rhs)
{
    return lhs.dist < rhs.dist;
}

int find(vector<int> &disjoint, int a)
{
    if (disjoint[a] == -1)
    {
        return a;
    }

    disjoint[a] = find(disjoint, disjoint[a]);
    return disjoint[a];
}

void join(vector<int> &disjoint, int a, int b)
{
    a = find(disjoint, a);
    b = find(disjoint, b);

    if (a == b)
    {
        return;
    }

    disjoint[a] = b;
}

int main()
{
    int cases;
    cin >> cases;

    bool first = true;
    while (cases--)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            cout << endl;
        }

        int n;
        cin >> n;
        vector<pair<long double, long double>> v(n);
        for (auto &i : v)
        {
            cin >> i.first >> i.second;
        }

        vector<Edge> edges;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                Edge e = {i, j, dist(v[i], v[j])};
                edges.push_back(e);
            }
        }

        sort(edges.begin(), edges.end(), cmp);

        long double total = 0;
        vector<int> disjoint(n, -1);

        for (auto &i : edges)
        {
            if (find(disjoint, i.n1) != find(disjoint, i.n2))
            {
                total += i.dist;
                join(disjoint, i.n1, i.n2);
            }
        }

        cout << fixed;
        cout.precision(2);
        cout << total << endl;
    }
}
