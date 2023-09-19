class Solution {
public:
// Simple MEX of an Array
// TC: O(n*log(n))
// SC: O(1)
    int firstMissingPositive(vector<int>& nums) {
        // sort the array
  sort(nums.begin(), nums.end());
 
  int mex = 1;
  for (int idx = 0; idx < nums.size(); idx++)
  {
    if (nums[idx] == mex)
    {
      // Increment mex
      mex++;
    }
  }
 
  // Return mex as answer
  return mex;
    }
};

