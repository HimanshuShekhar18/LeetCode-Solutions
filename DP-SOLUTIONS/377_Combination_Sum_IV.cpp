class Solution {
public:

// Simple Coin Change-I Problem
// RECURSION + MEMOIZATION
// TC: O(n*target)
// SC: O(n) + O(n)

    int dp[1010];
    int func(vector<int>&nums, int target ){

	if(target==0) return 1;
	if(dp[target]!=-1) return dp[target];
	int ways = 0;

	for (auto num: nums)
	{
		if(target-num>=0){
			ways+=func(nums,target-num);
		}
	}

	return dp[target]=ways;
}
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ways = func(nums,target);   // 0-based indexing
        return ways;
    }
};


//<--------------------------------------------------------- TABULATION -------------------------------------------------------------------------------------->


class Solution {
public:
// Simple Coin Change-I Problem
// TABULATION
// TC: O(n*target)
// SC: O(n)
unsigned long long dp[1010];   // changes done here  "unsigned long long" instead of long long
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,0,sizeof(dp));
				dp[0]=1;
				for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i - num >= 0)
                    dp[i] += dp[i - num];
          }
        }
        return dp[target];
      }
};




