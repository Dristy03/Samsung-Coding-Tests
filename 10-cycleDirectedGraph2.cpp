/*
6 7
0 1
1 2
1 5
2 3
3 4
4 0
4 1
*/

#include <iostream>
#include <vector>

using namespace std;

bool dfs(int u, vector<vector<int> > adjList, vector<int> &vis, vector<int> &dfsVis)
{
    vis[u] = 1;
    dfsVis[u] = 1;

    for (int i = 0; i < adjList[u].size(); i++)
    {
        int v = adjList[u][i];
        if (!vis[v])
        {
            if (dfs(v, adjList, vis, dfsVis))
            {
                return true;
            }
        }
        else if (dfsVis[v])
        {
            return true;
        }
    }

    dfsVis[u] = 0;
    return false;
}

bool isCyclic(int n, vector<vector<int> > &adjList)
{
    vector<int> vis(n, 0);
    vector<int> dfsVis(n, 0);

    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            if (dfs(i, adjList, vis, dfsVis))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adjList(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    if (isCyclic(n, adjList))
    {
        cout << "Cycle found" << endl;
    }
    else
    {
        cout << "No cycle found." << endl;
    }

    return 0;
}
