class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minsum = 0;
        int sum = 0;
        int start = 0, end = 0;
        int maxlength = INT_MAX;

        while(end<nums.size()){
            sum+=nums[end];
            while(start<=end && sum>=target){
                maxlength=min(maxlength,end-start+1);
                sum-=nums[start];
                start++;
            }
            end++;
        }
        return maxlength==INT_MAX?0:maxlength;
    }
};


// <--------------------------------------------------------------------BINARY SEARCH------------------------------------------------------------------------------->

class Solution {
public:

/*
Binary Search - bcoz the prefix sum is monotonic increasing
here nums consists of only positive numbers only
TC: O(n*log(n))
SC: O(n)
*/

    int minSubArrayLen(int target, vector<int>& nums) {
        
        vector<int> sum(nums.size()+1,0);

        int start = 0, end = 0;
        int maxlength = INT_MAX;

        for(int i = 1; i<=nums.size(); i++){
              sum[i]=sum[i-1]+nums[i-1];
        }

        for(int i = 1; i<=nums.size(); i++){
            auto tofind = lower_bound(sum.begin()+i-1,sum.end(),target+sum[i-1]);
            
           if(tofind!=sum.end()) {
                // cout << "hello" << " " << i <<  endl;
                // cout << tofind-sum.begin() << endl;
                int ans = tofind-(sum.begin()+i)+1;
                maxlength=min(maxlength,ans);
           }
        }
        return maxlength==INT_MAX?0:maxlength;
    }
};


