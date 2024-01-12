/*
5 5
0 1
1 2
1 4
4 3
2 3
*/

#include <iostream>
#include <vector>

using namespace std;

bool dfs(int u, vector<vector<int> > adjList, vector<int> &vis, int parent)
{
    vis[u] = 1;

    for (int i = 0; i < adjList[u].size(); i++)
    {
        int v = adjList[u][i];
        if (!vis[v])
        {
            if (dfs(v, adjList, vis, u))
            {
                return true;
            }
        }
        else if (v != parent)
        {
            return true;
        }
    }

    return false;
}

bool isCyclic(int n, vector<vector<int> > &adjList)
{
    vector<int> vis(n, 0);

    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            if (dfs(i, adjList, vis, -1))
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
        adjList[v].push_back(u); 
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
