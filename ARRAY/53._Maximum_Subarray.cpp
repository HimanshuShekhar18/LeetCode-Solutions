class Solution {
public:

/*
Kadane's Algorithm
TC: O(n)
SC: O(1)
*/

    int maxSubArray(vector<int>& nums) {
        int maxi_so_far = INT_MIN, maxi_current = 0, start = 0, end = 0, s = 0;

        for(int i = 0; i<nums.size(); i++){
            
            maxi_current+=nums[i];

            

            if(maxi_current>maxi_so_far){
                maxi_so_far = maxi_current;
                start = s;
                end = i;
            }

            if(maxi_current<0){
                maxi_current = 0;
                s=i+1;
            }
        }

        return maxi_so_far;
    }
};


// <-----------------------------------------------------------------DP------------------------------------------------------------------------------------->


class Solution {
public:

/*
DP
TC: O(n)
SC: O(n)

For each index i, DP[i] stores the maximum possible Largest Sum Contiguous Subarray ending at index i,

[-2,1,-3,4,-1,2,1,-5,4]

*/

    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        dp[0]=nums[0];
        int ans = dp[0];

        for(int i = 1; i<nums.size(); i++){
            
           dp[i]=max(nums[i],dp[i-1]+nums[i]);
           ans=max(ans,dp[i]);
        }

        return ans;
    }
};




<----------------------------------------------------------------DIVIDE AND CONQUER------------------------------------------------------------------------>



class Solution {
public:

/*

Divide and Conquer Approach 
TC:O(n*(log(n))
SC:O(n)

*/

    int solve(vector<int> &nums, int  left, int right){
        if(left==right) return nums[left];

        int mid = (left+right)/2;

        int leftsum = solve(nums,left,mid);
        int rightsum = solve(nums,mid+1,right);

        int leftysum = INT_MIN, rightysum = INT_MIN, sum = 0;


        for(int i = mid; i>=left; i--){
            sum+=nums[i];
            leftysum=max(leftysum,sum);
        }
        sum=0;
        for(int i = mid+1; i<=right; i++){
            sum+=nums[i];
            rightysum=max(rightysum,sum);
        } 

        return max({leftsum,rightsum,leftysum+rightysum});
    }


    int maxSubArray(vector<int>& nums) {
       return solve(nums,0,nums.size()-1);
    }
};








