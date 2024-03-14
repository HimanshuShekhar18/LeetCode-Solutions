class Solution {
public:

// Hashmap with Prefix Sum
// TC: O(n)
// SC: O(n)


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        unordered_map<int,int> mp;
        mp[0]=1;

        int prefix_sum = 0;

        for(int i = 0; i<nums.size(); i++){
            prefix_sum+=nums[i];

            int remove = prefix_sum-goal;

            count+=mp[remove];

            mp[prefix_sum]++;
        }

        return count;
    }
};
