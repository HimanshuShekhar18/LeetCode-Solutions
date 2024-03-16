class Solution {
public:

// TC: O(n)
// SC: O(n)


    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<long long> prefix(nums.size(),1);
        vector<long long> suffix(nums.size(),1);
        vector<int> ans(nums.size(),1);
        prefix[0]=nums[0];
        suffix[nums.size()-1]=nums[nums.size()-1];

        for(int i = 1; i<nums.size(); i++){
            prefix[i]=prefix[i-1]*nums[i];
        }

        for(int i = nums.size()-2; i>=0; i--){
            suffix[i]=suffix[i+1]*nums[i];
        }

        ans[0]=suffix[1];
        ans[nums.size()-1]=prefix[nums.size()-2];
        for(int i = 1; i<nums.size()-1; i++){
            ans[i]=prefix[i-1]*suffix[i+1];
        }
        return ans;
    }
};


// <----------------------------------------------------------------------------------------------------------------------------------------->



class Solution {
public:

// TC: O(n)
// SC: O(1)

    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0;
        long long index = 0, product = 1;

        vector<int> ans(nums.size(),0);

        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==0) zero++, index = i;
            else product*=nums[i];
        }

        if(zero>1){
            return ans;
        }
        else if(zero==1){
            ans[index]=product;
            return ans;
        }
        else {
            for(int i = 0; i<nums.size(); i++){
                ans[i]=product/nums[i];
            }
        }
        
        return ans;
    }
};



