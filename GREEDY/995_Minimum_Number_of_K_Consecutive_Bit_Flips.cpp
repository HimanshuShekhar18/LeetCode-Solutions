
// <----------------------------------------------------------------------------------------Same Greedy Approach and vector for prefix-------------------------------------------------------------------------------------------------->

/*
TC: O(n)
SC: O(n)
*/


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


// <------------------------------------------------------------------------------------INPUT ARRAY MODIFICATION for prefix-------------------------------------------------------------------------------------------------------------------------->

/*
TC: O(n)
SC: O(1)
*/

using namespace std::chrono;
class Solution {
public:

    int minKBitFlips(vector<int>& nums, int k) {

       
        int flipcount = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (i - k >= 0 && nums[i - k] == 2) {
                flipcount--;
                flipcount = max(0, flipcount);
            }

            if (flipcount % 2 == nums[i]) {
                if (i + k > nums.size())
                    return -1;
                nums[i] = 2;
                flipcount++;
                result++;
            }
        }
        return result;
    }
};



// <-------------------------------------------------------------------------------------Same Greedy Approach and Deque for prefix------------------------------------------------------------------------------------------->



/*
TC: O(n)
SC: O(k)
*/


using namespace std::chrono;
class Solution {
public:

    int minKBitFlips(vector<int>& nums, int k) {
       
        int flipcount = 0;
        int result = 0;

        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {

            if (i - k >= 0) {
                
                flipcount-=dq.front();
                flipcount = max(0, flipcount);
                dq.pop_front();
            }

            if (flipcount % 2 == nums[i]) {
                if (i + k > nums.size()) return -1;
                dq.push_back(1);
                flipcount++;
                result++;
                continue;
            }

            dq.push_back(0);

        }
        return result;
    }
};










