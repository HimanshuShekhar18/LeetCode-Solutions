class Solution {
public:

// Two Pointers or Variable Size Sliding Window
// TC: O(n)
// SC: O(1)

int window(vector<int>&nums, int goal){
    int j = 0, i = 0, count = 0, sum = 0;

    while(j<nums.size()){

        sum+=nums[j];

        // shrinking the window
        while(sum>goal && i<=j ){
            sum-=nums[i];
            i++;
        }

        j++; // expanding the windo

        count+=j-i+1; 
    }

    return count;
}


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // sum<=goal - sum<goal
        // sum<=goal - sum<=goal-1
        return window(nums,goal)-window(nums,goal-1);
    }
};


