/*
Raka wants to climb a rock from a starting point to the destination point. Given a map of the rock mountain which N = height, M = width. 
In the map, character '-' is the possible foot place spot (where he can climb). He can freely move up/down at vertical spots which '-' exists 
sequentially. It's impossible to move horizontally in case '-' is not consecutive in the same height level. The maximum height of moving from 
the starting point to the destination point is the level of difficulty of rock climbing . The total distance of movement is not important. There 
is more than one path from the starting point to the destination point. Output: The minimum level of difficulty of all rock climbing paths level.

Hint: Start with difficulty level 0 and then keep increasing it one by one. Raka always starts from bottom left position.

Input
5 8
1 1 1 1 0 0 0 0
0 0 0 3 0 1 1 1
1 1 1 0 0 1 0 0
0 0 0 0 0 0 1 0
1 1 1 1 1 1 1 1

Output
2
*/


#include <iostream>
#include<vector>
#include<climits>
#include<queue>
#include<string>
#include <iomanip>
#include<map>
using namespace std;
int c,n,m,k,ans=INT_MAX;
int xs,ys,xe,ye;

void solve(vector<vector<int> >& a,vector<vector<bool> >& vis, int curRow, int curCol, int dif)
{
    if(curRow<0 || curRow>=n || curCol<0 || curCol>=m)
    {
        return;
    }
    
    if(a[curRow][curCol]==3)
    {
         ans = min(ans,dif);
    }
    
    vis[curRow][curCol]=1;
    
    int up = curRow-1;
    
    while(up>=0 && !a[up][curCol])
    {
        up--;
    }
    
    if(up>=0 && !vis[up][curCol])
    {
        solve(a,vis,up,curCol,max(dif,curRow-up));
    }
    
    int down = curRow+1;
    
    while(down<n && !a[down][curCol])
    {
        down++;
    }
    
    if(down<n && !vis[down][curCol])
    {
        solve(a,vis,down,curCol,max(dif,down-curRow));
    }
    
    if(curCol+1<m && !vis[curRow][curCol+1] && a[curRow][curCol+1])
    {
        solve(a,vis,curRow,curCol+1,dif);
    }
    
    if(curCol-1>=0 && !vis[curRow][curCol-1] && a[curRow][curCol-1])
    {
        solve(a,vis,curRow,curCol-1,dif);
    }
    
    vis[curRow][curCol]=0;
}


int main() {
      
    cin>>n>>m;
    
    vector<vector<int> >a(n,vector<int>(m,0));
    vector<vector<bool> >vis(n,vector<bool>(m,0));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    
    solve(a,vis,n-1,0,0);
    
    cout<<ans<<endl;
      
      
    
}