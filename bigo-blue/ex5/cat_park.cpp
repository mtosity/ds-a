#include <iostream>
#include <vector>

using namespace std;

int v, mc, sol;
vector<vector<int> > road;
vector<int> cats;
bool vis[100005];

int dfs(int nod, int sum)
{

    if (vis[nod])
        return 0;

    vis[nod] = 1;

    if (sum > mc)
        return 0;

    if (road[nod].size() == 1 && nod != 1 && sum <= mc)
        sol++;

    for (int u : road[nod])
    {
        if (nod == u)
            continue;
        if (cats[u] == 0)
            dfs(u, 0);
        else
            dfs(u, sum + cats[u]);
    }

    vis[nod] = 0;
}

int main()

{

    cin >> v >> mc;
    cats.resize(v + 1);
    road.resize(v + 1);

    for (int i = 1; i <= v; i++)
        cin >> cats[i];

    for (int i = 1; i < v; i++)
    {
        int d1, d2;
        cin >> d1 >> d2;
        road[d1].push_back(d2);
        road[d2].push_back(d1);
    }

    dfs(1, cats[1]);
    cout << sol;

    return 0;
}
