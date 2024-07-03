/*

Sorting and Greedy
After Sorting Four Combination of Removing Elements from Left and Right
Left    Right
  0         3
  1         2 
  2         1
  3         0 
Take the differences of these four Combinations and the minimum of them will be ans.
TC: O(n*log(n))
SC: O(1)

*/


class Solution {
public:
    int minDifference(vector<int>& nums) {

        if(nums.size()<=4) return 0;

        sort(nums.begin(),nums.end());

        int n = nums.size();

        int right3left0 = abs(nums[0]-nums[n-4]);
        int left3right0 = abs(nums[3]-nums[n-1]);
        int right2left1 = abs(nums[1]-nums[n-3]);
        int right1left2 = abs(nums[2]-nums[n-2]);

        return min({right3left0,left3right0,right2left1,right1left2});
        
    }
};
