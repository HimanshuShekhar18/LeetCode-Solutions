class Solution {
public:

/*
Fixed Size Sliding Window 
TC: O(n)
SC: O(n)
*/

    int minSwaps(vector<int>& nums) {
        int ones = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==1){
                ones++;
            }
        }

        for(int i = 0; i<ones; i++){
            nums.push_back(nums[i]);
        }

        int onecount = 0;

        int i = 0, j = 0;
        int n = nums.size();
        int ans = INT_MAX;
        while(i<n && j<nums.size()){
                
                if(nums[j]==1) onecount++;

                if(j-i+1==ones){
                    ans=min(ans,ones-onecount);
                    if(nums[i]==1) onecount--;
                    i++;
                }
            j++;
        }
        return ans==INT_MAX?0:ans;
    }
};





// <-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


class Solution {
public:

/*
Fixed Sized Sliding Window
Corner Case: if(ones==0) return 0;
TC: O(n)
SC: O(1)
*/
    int minSwaps(vector<int>& nums) {
        int ones = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==1){
                ones++;
            }
        }       

        if(ones==0) return 0;

        int onecount = 0;

        int i = 0, j = 0;
        int n = nums.size();
        int ans = INT_MAX;
        while(i<n){
                if(nums[j%n]==1) onecount++;

                if(j-i+1==ones){
                    ans=min(ans,ones-onecount);
                    if(ans==0) break;
                    if(nums[i]==1) onecount--;
                    i++;
                }
            j++;
        }
        return ans==INT_MAX?0:ans;
    }
};




