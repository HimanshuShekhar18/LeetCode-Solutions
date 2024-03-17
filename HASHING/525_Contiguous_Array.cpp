class Solution {
public:

// Maximum Size Subarray equals 0
// Hashmaps with Prefix Sum
// TC: O(n)
// SC: O(n)

    int findMaxLength(vector<int>& nums) {
    
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        unordered_map<long long, long long> mp;
        long long sum = 0;
        int maxlength = 0;

    for(int i = 0; i<nums.size(); i++){
        sum+=nums[i];
        if(sum==0){
            maxlength=max(i+1,maxlength);
        }
        long long remain = sum;
        if(mp.find(remain)!=mp.end()){
            int len = i - mp[remain];
            maxlength=max(maxlength,len);
        }
        // check for if array consists of zero(0) 
        // So eventually if we are looking for (x-k) we look for as left as possible
        if(mp.find(sum)==mp.end()) mp[sum]=i;
    }
    return maxlength;
    }
};



  
    
