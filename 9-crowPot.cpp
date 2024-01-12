
/*
There are N pots. Every pots has some water in it. They may be partially filled. 
Every pot is associated with overflow number O which tell how many minimum no. of stones required 
for that pot to overflow. The crow know O1 to On(overflow no. for all the pots). Crow wants some K 
pots to be overflow. So the task is minimum number of stones he can make K pots overflow in worst case.

Array of overflow no--. {1,...,On}
Number of pots--n
No of pots to overflow-- k

Let say two pots are there with overflow no.s {5,58}, and crow has to overflow one pot(k=1). 
So crow will put 5 stones in pot with overflow no.(58), it will not overflow, then he will put in 
pot with overflow no.(5), hence the total no. of stones to make overflow one pot is=10.

2 1
5 58
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,k,ans=INT_MAX;
    cin>>n>>k;
    vector<int>overflow(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>overflow[i];
    }

    sort(overflow.begin(),overflow.end());

    vector<vector<int> >dp(n+1,vector<int>(k+1,0));

     for(int i=1; i<=n; i++)
     {
        dp[i][1] = overflow[i]*(n-i+1);
     }

     for(int i=n; i>0; i--)
     {
        for(int j=2; j<=k; j++)
        {
            for(int l=i+1; l<=n; l++)
            {
                dp[i][j] = min(dp[i][j] , dp[l][j-1] + (l-i)*overflow[i]);
            }
        }
     }
        
            
 for(int i=1; i<=n; i++)
 {
    ans = min(ans,dp[i][k]);
 }
    
            
 

    cout<<ans<<endl;
    

}