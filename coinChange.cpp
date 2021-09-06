/*
For Coin Sum problems use bottom up DP with 2 for loops
Sum loop outside to get all possible ways to get the sum
Coin loop outside to get all possible ordered ways to get the sum
Coin loop outside and inner loop reversed to use a coin once
*/

#include<iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    int change(int target, vector<int>& coins) {
        int n=coins.size();
        vector<int> dp(target+1);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=1;j<=target;j++){
                if(j>=coins[i]) dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[target];
    }
};
