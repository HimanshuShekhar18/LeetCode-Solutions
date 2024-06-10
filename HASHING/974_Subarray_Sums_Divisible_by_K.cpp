class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        int n = nums.size();
        int i = 0;
        int sum = 0;
        int count = 0;

        mp[0]=1;

            while(i<n){

                sum+=(nums[i]%k)+k;

                count+=mp[sum%k];

                mp[sum%k]++;

                i++;
            }

        return count;
    }
};


// <------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        int n = nums.size();
        int i = 0;
        int sum = 0;
        int count = 0;

        mp[0]=1;

            while(i<n){

                sum+=nums[i];

                count+=mp[(((sum+k)%k + k)%k)];

                mp[(((sum+k)%k + k)%k)]++;

                i++;
            }
            
        return count;
    }
};
