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


// <------------------------------------------------------------------------------------------------------------------------------------------------------------------->


class Solution {
public:
// Otpimized Approach 2: Floyd Hare's - Tortoise Algorithm
// TC: O(n)
// SC: O(1)
 
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            cout << slow << " " << fast << endl;
            if(slow==fast) break;
        }
        cout << endl;
        int find = 0;
        while(true){
            slow=nums[slow];
            find=nums[find];
            cout << slow << " " << find << endl;
            if(slow==find) return find;
        }
        return 0;
    }
};

