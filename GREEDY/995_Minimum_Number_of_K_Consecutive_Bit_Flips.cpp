class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        vector<int> mp(nums.size(),0);
        int flipcount = 0;
        int result = 0;

        for(int i = 0; i<nums.size(); i++){

            if(i-k>=0 && mp[i-k]==1){
                flipcount--;
                flipcount=max(0,flipcount);
            }

            if(flipcount%2==nums[i]){
                if(i+k>nums.size()) return -1;
                mp[i]=1;
                flipcount++;
                result++;
            }
        }
        return result;
    }
};
