
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



class Solution {
public:
// CYCLIC SORITNG
// TC: O(n))
// SC: O(1)
    int firstMissingPositive(vector<int>& nums) {
      // cycle sorting --> 1 to N wala
        for(int i = 0; i<nums.size(); i++){
          // Here in 1 to N sorting --> nums[i] == position(i)+1 hota hain
          // replace nums[i] uske position se i.e. nums[i]-1;
           while(nums[i]<=nums.size() && nums[i]>0 && nums[i]!=nums[nums[i]-1]) swap(nums[i],nums[nums[i]-1]);
        }

        int index = 0;

        // printing the array after operations
        for(int i = 0; i<nums.size(); i++){
          cout << nums[i] << endl;
        }

        cout << endl;

        for(index = 0; index<nums.size(); index++){
           if(nums[index]!=index+1) break;
        }
        return index+1;
    }
};



class Solution {
public:
// CYCLIC SORITNG
// TC: O(n))
// SC: O(1)
    int firstMissingPositive(vector<int>& nums) {
      // cycle sorting --> 1 to N wala
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
        for (i = 0; i < n; ++i){ if (nums[i] != (i+1)) break;}
        return i+1;
    }
};


