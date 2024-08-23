
/*
0/1 Knapsack Pick or Non-Pick DP and unordered_map for Counting/Hashing
TC: O(n^2)
SC: O(n)
*/

class Solution {
public:

    int solve(int index, int n, vector<int>&dp, vector<int>&nums, int k){
        
        if(index==n) return 0;

        if(dp[index]!=-1) return dp[index];

        unordered_map<int,int> mp;
        mp[nums[index]]++;
        int value = 0;
        int ans = INT_MAX;
        for(int j = index+1; j<=n; j++){
            ans=min(ans,k+value+solve(j,n,dp,nums,k));
            if(j==n) break;
            mp[nums[j]]++;
            if(mp[nums[j]]==2){
                value+=2;
            }
            else if(mp[nums[j]]>2){
                value+=1;
            }
        }
        mp.clear();
        return dp[index]=ans;
    }

    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,dp,nums,k);
    }
};


