/*

A binary matrix of nxm was given, you have to toggle any column k number of times so that you can get the maximum 
number of rows having all 1’s.

for eg, n=3, m=3,

            1 0 0

            1 0 1

            1 0 0

if k=2, then we will toggle column 2 and 3 once and we will get rows 1 and 3 with 1 1 1 and 1 1 1 i.e. all 1’s so 
answer is 2 as there are 2 rows with all 1’s.

if k=3, then we will toggle column 2 thrice and we will get row 2 with 1 1 1 i.e. all 1’s so answer is 1 as there 
is 1 row with all 1’s.
*/


#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main()
{
    int n,m,k,ans=INT_MIN;
    cin>>n>>m>>k;
    vector<vector<int> > mat(n,vector<int>(m,0));
    map<string,int>mp;
    string a;

    for(int i=0;i<n;i++)
    {
        a="";
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
            a+=to_string(mat[i][j]);
        }
        
        mp[a]++;
    }
    
    for(auto i: mp)
    {
        int zeros = 0;
        for(int j=0;j<i.first.size();j++)
        {
            if(i.first[j]=='0')
            {
                zeros++;
            }
        }
        if(zeros<=k && (zeros-k)%2==0)
        {
            ans = max(ans,i.second);
        }
    }


    cout<<ans<<endl;
    

}