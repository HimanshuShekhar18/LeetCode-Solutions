class Solution {
public:

    bool isPossible(vector<int>&nums, int mid, int n, int k){

            int sumarr = 0;
            int subarraycount = 1;
            for(int i = 0; i<n; i++){
                if(sumarr+nums[i]<=mid){
                    sumarr+=nums[i];
                }
                else{
                        subarraycount++;
                        if(subarraycount>k || nums[i]>mid) return false;
                        sumarr=nums[i];
                }
            }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();
        int start = 0;
        int sumarr = 0;

        for(int i = 0; i<nums.size(); i++){
            sumarr+=nums[i];
        } 

        int end = sumarr;

        int ans = -1;

        while(start<=end){
            int mid = end-(end-start)/2;

            if(isPossible(nums,mid,n,k)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        } 
        return ans;      
    }
};


