/*
13 15
1 2
2 3
3 4
4 6
4 7
5 6
3 5
7 8
6 10
5 9
10 9
10 11
11 12
11 13
12 13
*/


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
const int N = 100000;

vector<int> graph[N];
vector<vector<int> > cycles;


void dfs_cycle(int u, int p, int color[], int par[], int& cyclenumber)
{
    if(color[u]==2)
    {
        return;
    }

    if(color[u]==1)
    {
        vector<int>v;
        cyclenumber++;

        int cur = p;
        v.push_back(cur);

        while (cur!=u)
        {
            cur = par[cur];
            v.push_back(cur);
        }

        cycles.push_back(v);
        return;
        
    }

    par[u]=p;
    color[u]=1;

    for(auto v: graph[u])
    {
        if(v==par[u])
        {
            continue;
        }
        dfs_cycle(v,u,color,par,cyclenumber);
    }

    color[u]=2;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  
    }

   int color[n+1];
   int par[n+1];

   int cyclenumber = 0;

   dfs_cycle(1,0,color,par,cyclenumber);


   for (int i = 0; i < cyclenumber; i++) {
        cout << "Cycle Number " << i + 1 << ": ";
        for (int x : cycles[i])
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
