class Solution {
public:

// Counting and Sorting
// TC: O(n*log(n))
// SC: O(n)

    int mostFrequentEven(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int curr = -1;
        int mostcurr = -1;
        int count = 0;
        int mostcount = 0;

        for(int i = 0; i<nums.size(); i++){

            if(!(nums[i]&1)){

                if(nums[i]==curr) count++;
                else if(count>mostcount){
                    mostcurr=curr;
                    mostcount=count;
                    curr=nums[i];
                    count=1;
                }
                else {
                    curr = nums[i];
                    count=1;
                }
            }
        }

        if(count>mostcount){
            mostcurr = curr;
        }
        return mostcurr;
    }
};
