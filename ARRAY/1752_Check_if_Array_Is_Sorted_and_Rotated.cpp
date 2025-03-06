// Problem Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

// 'non-decreasing' i.e. not strictly increasing eg: [ 6,10,6 ],  [10,1,1,10] 


class Solution {
      public:
      
      /*
      eg: [3,4,5,1,2]
      
                  5
                 /
                4
               /
              3
                        2
                       /
                      1
          
          i) If 0 rotation point, return true;
          i) only one rotation point possible for sorted and rotated and Make sure last element <= first element
          iii) If more than one rotation point, return false;
           
      */
      
          bool check(vector<int>& nums) {
      
              if(nums.size()==1 || nums.size()==2) return true;
      
              int n = nums.size();
              int rotationpoint = 0;
              for(int i = 0; i<nums.size()-1; i++){
                  if(nums[i] <= nums[i+1]){
                      continue;
                  }
                  else{
                      rotationpoint++;
                  }
              }
      
              if(rotationpoint==0) return true;
              else if(rotationpoint==1) {
                  if(nums[n-1]<=nums[0]) return true;
              }
              return false;
              
          }
      };

