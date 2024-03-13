class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Observation is atmost 2 elements exist which appear more than n/3 times

        // these two potential majority elements and their counts
        int element1 = 0, element2 = 0, count1 = 0, count2 = 0;
    
        int n = nums.size();

        vector<int> ans;

        // so in first pass take out those two potential majority elements jo jyada occur karte hain
        for(int i = 0; i<nums.size(); i++){

            if(count1==0 && nums[i]!=element2){
                element1 = nums[i];
                count1=1;
            }
            else if(count2==0 && nums[i]!=element1){
                element2 = nums[i];
                count2=1;
            }
            else if(element1==nums[i]) count1++;
            else if(element2==nums[i]) count2++;

            else {
                count1--;
                count2--;
            }
        }

        // now in second pass check whether these two potential elements exceeds the threshold value;

        int threshold = n/3;

        count1=0,count2=0;

        for(int i = 0; i<n; i++){
            if(nums[i]==element1) count1++;
            else if(nums[i]==element2) count2++;
        }

        if(count1>threshold) ans.push_back(element1);
        if(count2>threshold) ans.push_back(element2);

        return ans;
    }
};

