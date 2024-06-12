class Solution {
public:
/*
Using Two Pointers
TC: O(n)
SC: O(1)
*/
    void sortColors(vector<int>& nums) {

        int low = 0, high = nums.size()-1;


        for(int i = 0; i<nums.size(); i++){
            
                if(nums[i]==0) {
                    swap(nums[i],nums[low]);
                    low++;
                }
                else if(nums[i]==1){
                    continue;
                }
                else{
                    if(i<=high) {
                    swap(nums[i],nums[high]);
                    high--;
                    i--;
                    }
                }
        }
        
       
    }
};



// <----------------------------------------------------------------------------------COUNTING------------------------------------------------------------------------------------------>


class Solution {
public:
/*
Using Count Sort
TC: O(n)
SC: O(1)
*/
    void sortColors(vector<int>& nums) {

        int count0 = 0, count1 = 0, count2 = 0;

        for(int i = 0; i<nums.size(); i++){

                if(nums[i]==0) count0++;
                else if(nums[i]==1) count1++;
                else count2++;

        }
        
        int i = 0;
        while(count0--){
            nums[i] = 0;
            i++;
        }

        while(count1--){
            nums[i]=1;
            i++;
        }

        while(count2--){
            nums[i]=2;
            i++;
        }
    }
};


