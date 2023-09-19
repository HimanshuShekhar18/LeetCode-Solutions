class Solution {
public:
// Otpimized Approach 1: Marked Visited
// TC: O(n)
// SC: O(1)
 
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i<nums.size();i++){
            int val = abs(nums[i]);
            if(nums[val]<0) return val;
            nums[val]=-nums[val];
        }
        return 0;
    }
};
