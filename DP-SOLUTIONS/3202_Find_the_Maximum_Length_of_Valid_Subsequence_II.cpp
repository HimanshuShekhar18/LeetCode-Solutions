/*

Same as 1027. Longest Arithmetic Subsequence
1) Top-Down Recursion+Memoization TLE 3D-DP TC: O(n^3) SC: O(n^2) 
If Recursion+Memo Gives TLE Shift to TABULATION   
2) Bottom-Up Tabulation 2D-DP  TC: O(n^2)  SC: O(n^2)

*/


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {

        int ans = -1;

        unordered_map<int,int> dp[nums.size()+1];

        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<i; j++){
                int mod = (nums[i]+nums[j])%k;

                int cnt = 1;

                if(dp[j].count(mod)) cnt = dp[j][mod];

                dp[i][mod] = 1+cnt;
                ans=max(ans,dp[i][mod]);
            }
        }
        return ans;
    }
};



