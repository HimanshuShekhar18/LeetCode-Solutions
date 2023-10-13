class Solution {
public:
    // Memoization and Recursion 
    int dp[1010];
    int solve(int index, vector<int>&cost){
        if(index<0) return 0 ;
        if(dp[index]!=-1) return dp[index];
        return dp[index] = min(solve(index-1,cost),solve(index-2,cost)) + cost[index];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);
        memset(dp,-1,sizeof(dp));
        return solve(n,cost);
        
    }
};
