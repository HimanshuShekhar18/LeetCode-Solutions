class Solution {
public:
/*
Recursion + Memoization 2-DP
TC: O(n*target*k)
SC: O(n*target)

*/
    const int mod = 1000000007;
    int dp[32][1010];
    int num;
    int solve(int index, int k, int target){
        if(index==num && target==0) return 1;
        if((index<num && target==0) || (index>=num && target>0)) return 0; 
        if(dp[index][target]!=-1) return dp[index][target];
        long long ans = 0;
        for(int i = 1; i<=k; i++){
            if(target-i>=0) ans+=solve(index+1,k,target-i);
        }
        return dp[index][target]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        num=n;
        memset(dp,-1,sizeof(dp));
        return solve(0,k,target);
    }
};



class Solution {
public:
/*
TABULATION + 2-DP
TC: O(n*target*k)
SC: O(n*target)
*/
    const int mod = 1000000007;
    int dp[32][1010];
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,0,sizeof(dp));
        dp[n+1][0]=1;
        for(int index = n; index>=1; index--){
            for(int tar = 0; tar<=target; tar++){
                long long ans = 0;
                for(int i = 1; i<=k; i++){
            if(tar-i>=0) ans+=dp[index+1][tar-i];
            }
            dp[index][tar]=ans%mod;
            }
        }
        return dp[1][target];
    }
};




class Solution {
public:
/*
Slight Modified TABULATION + 2-DP
TC: O(n*target*k)
SC: O(n*target)
*/
    const int mod = 1000000007;
    int dp[32][1010];
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int index = 1; index<=n; index++){
            for(int tar = 0; tar<=target; tar++){
                long long ans = 0;
                for(int i = 1; i<=k; i++){
            if(tar-i>=0) ans+=dp[index-1][tar-i];
            }
            dp[index][tar]=ans%mod;
            }
        }
        return dp[n][target];
    }
};




class Solution {
public:
/*
SPACE-OPTIMIZED TABULATION 
TC: O(n*target*k)
SC: O(target)
*/
    const int mod = 1000000007;
    int numRollsToTarget(int n, int k, int target) {
        vector<int> curr(target+1,0), prev(target+1,0);
        prev[0]=1;
        for(int index = 1; index<=n; index++){
            for(int tar = 0; tar<=target; tar++){
                long long ans = 0;
                for(int i = 1; i<=k; i++){
            if(tar-i>=0) ans+=prev[tar-i];
            }
            curr[tar]=ans%mod;
            }
            prev=curr;
        }
        return prev[target];
    }
};



