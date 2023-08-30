class Solution {
public:
    /*

    GREEDY APPROACH

    
    Some Fact: 
    12 --> 3 3 3 3
    operations = parts-1 = 4-1 = 3 operations = 12/3 - 1 = 4 - 1 = 3 operations

    Fact-2:
    {1,2,11,3}
    nums[i]<=nums[i+1] should be
    11 --> 3 8 --> 3 3 5 --> 3 3 2 3 --> 2 3 3 3 = 3 operations

    parts = nums[i]/nums[i+1]
    if(nums[i]%nums[i+1]!=0) parts++

    operations = parts-1;

    {9,7,6} 
    here 7 can be broken into 3 ways --> {1,6}  {2,5}  {3,4}
    we will choose {3,4} so that 9 will be broken in mininum possible operation i.e 2 (3,3,3)

    how will you know to take {3,4} --> last value = 7/parts = 7/2 = 3
 . 
    {9,7,6}  -->  {3,3,3,3,4,6}  = 3 operations

    */
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int lastvalue = nums[n-1];
        long long operations = 0;
        long long parts = 0;
        for(int i = n-2; i>=0; i--){
            if(nums[i]>lastvalue){
                parts = nums[i]/lastvalue;
                if(nums[i]%lastvalue!=0) parts++;
                operations+=parts-1;
                lastvalue = nums[i]/parts;
            }
            else {
                lastvalue = nums[i];
            }
        }
        return operations;
    }
};

