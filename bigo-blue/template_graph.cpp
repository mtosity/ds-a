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

int main()
{
    int num_of_tests;
    cin >> num_of_tests;

    for (int i = 0; i < num_of_tests; i++)
    {
        int num_of_nodes, num_of_edges;
        cin >> num_of_nodes;
        cin >> num_of_edges;
        vector<list<int> > edges(num_of_nodes + 1);
        for (int j = 0; j < num_of_edges; j++)
        {
            int node_1, node_2;
            cin >> node_1 >> node_2;
            edges[node_1].push_back(node_2);
            edges[node_2].push_back(node_1);
        }

        int start_node;
        cin >> start_node;
        solve(num_of_nodes, start_node, edges);
    }

    return 0;
}