class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int maxi = 1, currmaxi = 1;
        int number = nums[0];
        int i;

        for( i = 1; i<nums.size(); i++){
            if(nums[i]==number) currmaxi++;
            else{
                if(maxi<currmaxi){
                    maxi=currmaxi;
                    currmaxi=1;
                    number = nums[i];
                }
                else {
                    number = nums[i];
                    currmaxi=1;
                }
            }
        }

        if(maxi<currmaxi) maxi=currmaxi;
       
        currmaxi = 1;
        number = nums[0];
        int ans = 0;

        for(int i = 1; i<nums.size(); i++){
            if(nums[i]==number) currmaxi++;
            else{
                if(maxi==currmaxi){
                    ans+=currmaxi;
                    currmaxi=1;
                    number = nums[i];
                }
                else {
                    number = nums[i];
                    currmaxi=1;
                }
            }
        }

        if(maxi==currmaxi) ans+=currmaxi;

        return ans;
        
    }
};




// <---------------------------------------------------------------------------------------------------------------------------------------------------->


class Solution {
public:

// TC: O(n)
// SC: O(n)

    int maxFrequencyElements(vector<int>& nums) {

        map<int,int> frequencies;
        int maxi = 0;
        int ans = 0;

        for(int i = 0; i<nums.size(); i++){

            frequencies[nums[i]]++;
            maxi=max(maxi,frequencies[nums[i]]);

        }

        for(auto it: frequencies){
            if(maxi==it.second) ans+=maxi;
        }
        return ans;
    }
};



