/*
There are n balloons and n bullets and each balloon is assigned with a particular number (point).
Whenever a particular balloon is shot the no of points increases by
1.the multiplication of point assigned to balloon on left and that of right side.
2.point assigned to left if no right exists
3.point assigned to right if no left exists.
4.the point assigned to itself if no other balloon exists.
 
You have to output the maximum no of points possible.
 
Input
1 2 3 4
 
Output
20
*/


#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> balloons(n);
   
    for (int i = 0; i < n; ++i) {
        cin >> balloons[i];
    }
    
    vector<int> nums;
    nums.push_back(1);

    for (int i = 0; i < n; ++i) {
        nums.push_back(balloons[i]);
    }

    nums.push_back(1);
    n = nums.size();

    vector<vector<int> > dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int left = 0; left < n - len; left++) {
            int right = left + len;
            for(int i = left+1;i<right;i++)
            {
                if(left==0 && right==n-1)
                    dp[left][right] = max(nums[left]*nums[i]*nums[right] + dp[left][i] + dp[i][right],dp[left][right]);
                else
                    dp[left][right] = max(nums[left]*nums[right] + dp[left][i] + dp[i][right],dp[left][right]);
            }
        }
    }
 


    cout << dp[0][n - 1]<< endl;

}
