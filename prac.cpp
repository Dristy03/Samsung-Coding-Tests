#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include<queue>
#include <climits>
#include <iomanip>
#include<algorithm>
using namespace std;

int n,k,m;


bool dfs(int u,vector<vector<int> >graph,vector<bool>& vis, vector<bool>& dfsVis)
{
    vis[u]=1;
    dfsVis[u]=1;
    
    for(auto v: graph[u])
    {
        if(!vis[v])
        {
            if(dfs(v,graph,vis,dfsVis))
            {
              return true;
            }
            
        }
        else if(dfsVis[v])
        {
            return true;
        }
    }
    dfsVis[u]=0;
    return false;
}



bool isCyclic(vector<vector<int> >graph)
{
   vector<bool>vis(n,0);
   vector<bool>dfsVis(n,0);

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,graph,vis,dfsVis))
            {
                return true;
            }
        }
    }
    
    return false;
}

int main ()
{

    cin>>n>>m;
    
    vector<vector<int> >graph(n);
   
    
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
       
    }
    
    
    if(isCyclic(graph))
    {
        cout<<"Cyclic"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
   
    
}
