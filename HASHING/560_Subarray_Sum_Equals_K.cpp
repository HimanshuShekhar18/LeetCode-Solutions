class Solution {
public:

/* 
Since here the sum is not monotonic increasing and decreasing, hence sliding window or two pointer cannot be used  

Hashmaps with Prefix Sum

TC: O(n)
SC: O(1)

*/

    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        int sum = 0, count = 0;

        mp[0]=1;

        for(int i = 0; i<nums.size(); i++){

            sum+=nums[i];

            int remove = sum-k;

            count+=mp[remove];

            mp[sum]++;

        }

        return count;
    }
};
