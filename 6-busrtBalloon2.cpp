/*

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.
Input: [3,1,5,8]
Output: 167 
*/

#include <iostream>
#include <vector>

using namespace std;

int dfs(int i,int j,vector<int>& nums,vector<vector<int> > &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        for(int k=i;k<=j;k++){
            int cost = nums[i-1]*nums[k]*nums[j+1] + dfs(i,k-1,nums,dp) + dfs(k+1,j,nums,dp);
            ans = max(ans,cost);
        }
        return dp[i][j] = ans;
    }

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
   
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    

    vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    cout<< dfs(1,n,nums,dp) <<endl;

}


/*
#include <iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

 

int main() {

    int n;
    cin>>n;
    vector<int>nums(n+2);
    nums[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i];
    }
    nums[n+1]=1;
    n = nums.size();
 
    
    vector<vector<int>>dp(n,vector<int>(n,0));
 
    for(int len=2;len<n;len++)
    {
        for(int left=0;left<n-len;left++)
        {
            int right = left+len;
            
            for(int k=left+1;k<right;k++)
            {
               
                dp[left][right] = max(nums[left]*nums[k]*nums[right]+dp[left][k]+dp[k][right],dp[left][right]);
                
            }
        }
    }
    
    cout<<dp[0][n-1]<<endl;
    
    
}
*/