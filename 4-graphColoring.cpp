/*
Given a graph print either of the set of the vertices that are colored with the same color. And if the graph
is not bipartite print “-1”. Test cases also included the cases when a graph is not connected.
*/


#include <iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

int n;

bool isBipartite( vector<vector<int>>arr, vector<int>& color)
{
    queue<int>q;
    q.push(0);
    color[0]=1;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for(int i=0;i<n;i++)
        {
            if(arr[u][i] && color[i]==-1)
            {
                color[i] = 1-color[u];
                q.push(i);
            }
            else if(arr[u][i] && color[i]==color[u])
            {
                return false;
            }
        }
        
    }
    
    return true;
}


int main() {


    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    vector<int>color(n,-1);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    if(isBipartite(arr,color))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    
    
}
