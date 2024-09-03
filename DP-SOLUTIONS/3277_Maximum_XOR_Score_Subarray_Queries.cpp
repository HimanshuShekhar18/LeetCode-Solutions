class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n,0));

        for(int i = 0; i<n; i++){
            dp[i][i]=nums[i];
        }

        // Precompute the XOR score of every subarray.
        // TC: O(n^2)
        // form "len" size subarray from "len-1" size subarray 
        for(int len = 1; len<n; len++){
            for(int i = 0; i+len<n; i++){
               dp[i][i+len] = dp[i][i+len-1]^dp[i+1][i+len];
            }
        }

        // Now PreCompute Maximum Xor Value for each row 'i' of each length "1" to "n"
        // TC: O(n^2)
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
               
               dp[i][j] = max(dp[i][j],dp[i][j-1]);

            }
        }


        /*
            * * * * *
            0 * * * *
            0 0 * * *
            0 0 0 * *
            0 0 0 0 *

            Go From DOWN To UP
        */
        // Pre-Compute the Maximum Xor Value of Columns  Start from Down and Going UP
        for(int j = n-1; j>=0; j--){
            for(int i  = j-1; i>=0; i--){
                dp[i][j]=max(dp[i][j],dp[i+1][j]);
            }
        }

        int m = queries.size();
        vector<int> ans;

        // Now Max Xor Score of all Every Subarray of all length and starting at any index in Queries Range [l,r]
        for(int q = 0; q<m; q++){

            int l = queries[q][0];
            int r = queries[q][1];

            ans.push_back(dp[l][r]);
        }

        return ans;
    }
};


