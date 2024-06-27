
/*

Variable Sliding Window in Two Pass and unordered_map;
( <=k - <=k-1 ) works for ( == k ) 
TC: O(2*n)  SC: O(n) 

*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        int result1 = 0;
        int result2 = 0;

        int i = 0, j = 0, n = nums.size();

        while (j < n) {

            mp[nums[j]]++;

            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            result1 += (j - i + 1);

            j++;
        }

        i = 0, j = 0;
        k--;
        mp.clear();

        while (j < n) {

            mp[nums[j]]++;

            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            result2 += (j - i + 1);

            j++;
        }

        return result1 - result2;
    }
};





// <---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

/*

Variable Sliding Window in Two Pass and unordered_map;
( <=k - <=k-1 ) works for ( == k ) 
TC: O(2*n)  SC: O(n) 

*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        int result = 0;

        int i = 0, ibada = 0, j = 0, n = nums.size();

        while (j < n) {

            mp[nums[j]]++;

            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
                ibada = i;
            }

            if (mp.size() == k) {
                while (mp[nums[i]] > 1) {
                    mp[nums[i]]--;
                    i++;
                }
                result += (i - ibada + 1);
            }

            j++;
        }

        return result;
    }
};






