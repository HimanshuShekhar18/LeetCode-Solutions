class Solution {
public:

// LIS VARIANT
// TC: O(n^2)
// sc: o(n)

    vector<int> LIS(vector<int> &nums){

        int n = nums.size();
        vector<int> dp(n,1), hash(n,0);
        int lastindex = 0;
        int maxi = 1;

        sort(nums.begin(),nums.end());

        for(int ind = 0; ind<n; ind++){
            hash[ind]=ind;
            for(int prev_ind = 0; prev_ind<ind; prev_ind++){

                if(nums[ind]%nums[prev_ind]==0 && dp[prev_ind]+1>dp[ind])
                {
                    hash[ind]=prev_ind;
                    dp[ind]=1+dp[prev_ind];
                }
            }

            if(dp[ind]>maxi){
                lastindex = ind;
                maxi = dp[ind];
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastindex]);

        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            ans.push_back(nums[lastindex]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return LIS(nums);
    }
};


