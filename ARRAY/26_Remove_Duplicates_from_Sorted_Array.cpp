class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;

        int startindex = 0;
        int endindex = 0;
        int unique = 1;
        int n = nums.size();
        while(endindex<n){
            if(nums[startindex]!=nums[endindex]){
                swap(nums[startindex+1],nums[endindex]);
                startindex=startindex+1;
                endindex=endindex+1;
                unique++;
            }
            else{
                endindex=endindex+1;
            }
        }
        return unique;
    }
};
