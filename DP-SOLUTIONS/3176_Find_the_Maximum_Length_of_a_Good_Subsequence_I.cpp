class Solution {
public:

/*
LIS Variant 
TC: O(n*n*k)
SC: O(n*n*k)
*/

int dp[502][502][28];

    int solve(int index, int prev, vector<int>&nums, int k, int inc){
       
        if(inc>k){
            return 0;
        }

        if(index==nums.size()) return 0;

        if(dp[index][prev+1][inc]!=-1) return dp[index][prev+1][inc];

        int len = 0;

        if(prev==-1 || nums[index]==nums[prev]){
                len=max(len,1+solve(index+1,index,nums,k,inc));
        }
        else if(nums[index]!=nums[prev]){
            if(inc+1<=k) len=max(len,1+solve(index+1,index,nums,k,inc+1));
        }

        len = max(len,solve(index+1,prev,nums,k,inc));

        return dp[index][prev+1][inc]=len;
    }

    int maximumLength(vector<int>& nums, int k) {

        memset(dp,-1,sizeof(dp));

       return solve(0,-1,nums,k,0);
        
    }
};




// <--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

/*
LIS Variant 
TC: O(n*n*k)
SC: O(n*k)
*/

class Solution {
public:
    int dp[502][28];

    int solve(int index,vector<int>& nums, int k, int inc) {

        if (dp[index][inc] != -1)
            return dp[index][inc];

        int len = 1;

        for (int j = index - 1; j >= 0; j--) {
            if (nums[index] == nums[j]) {
                len = max(len, 1 + solve(j, nums, k, inc));
            } else if (nums[index] != nums[j]) {
                if (inc + 1 <= k)
                    len = max(len, 1 + solve(j,nums, k, inc + 1));
            }
        }

        return dp[index][inc] = len;
    }

    int maximumLength(vector<int>& nums, int k) {

        memset(dp, -1, sizeof(dp));

        int maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, solve(i, nums, k,0));
        }

        return maxi;
    }
};


