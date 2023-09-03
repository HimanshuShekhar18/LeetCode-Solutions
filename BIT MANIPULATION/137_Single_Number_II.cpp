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


