class Solution {
public:

// Two Pointers or Variable Size Sliding Window
// TC: O(n)
// SC: O(1)


    long long countSubarrays(vector<int>& nums, long long k) {

        long long sum = 0, j = 0, i = 0, count = 0;
        
        while(j<nums.size()){

            sum+=nums[j];

            while(sum*(j-i+1)>k-1 && i<=j){
                sum-=nums[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }

        return count;
    }
};


