void dfs(vector<int> v[], bool visited[], int root)
{
    visited[root] = true;
    for (int i = 0; i < v[root].size(); ++i)
    {
        int adj = v[root][i];
        if (!visited[adj])
        {
            dfs(v, visited, adj);
        }
    }
}

vector<int> graph[MAX];
void BFS(int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int &v : graph[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
