class Solution {
public:
// BIT-MANIPULATION
// TC: O(32*n)
// SC: O(1)

/* Take Example 
  2 2 5 2
                                     2 --> 0 1 0
                                     2 --> 0 1 0
                                     5 --> 1 0 1
                                     2 --> 0 1 0
count SetBit at each i'th bit position  =  1 3 1
count%3 at each i'th bit position = --> =  1 0 1  = 5 --> ans  

  2 2 7 2
                                     2 --> 0 1 0
                                     2 --> 0 1 0
                                     5 --> 1 1 1
                                     2 --> 0 1 0
count SetBit at each i'th bit position  =  1 4 1
count%3 at each i'th bit position = --> =  1 1 1  = 7 --> ans 
*/
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<32; i++){
            int count = 0;
            for(auto num: nums){
                count+= (num>>i)&1;
            }
            count%=3;
            ans|=count<<i;       
      }
    return ans;
   }  
};



// <-------------------------------------------------------------------- SORTING -------------------------------------------------------------------------->




class Solution {
public:
    // SORTING
    // TC: O(n*log(n))
    // SC: O(1)
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    
        int n = nums.size();

        if(n==1) return nums[0];

        if(nums[0]!=nums[1]) return nums[0];

        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        for(int i = 1; i<n-1; i++){
            if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]) return nums[i];
        }
        
        return 0;

    }
};



// <-----------------------------------------------------------BIT MAGIC--------------------------------------------------------------------------------->

class Solution {
public:
// FAST BITMAGIC --> XOR Operations
// TC: O(n)
// SC: O(1)
/*
add in ones only when not present in twos
add in twos only when not present in ones
*/
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for(int i = 0; i<nums.size(); i++){
                ones = (ones^nums[i])&(~twos);
                twos = (twos^nums[i])&(~ones);
        }
        return ones;
    }
};






