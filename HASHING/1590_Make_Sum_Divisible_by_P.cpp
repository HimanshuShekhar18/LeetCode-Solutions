class Solution {
public:

/*

CONCEPT 
 - if (a-b)%p=0 then a%p=b%p;

Explanation:

    _ _ _ _ _ _ _ _ _ 
        i       j

    According to Question we need to find minimum size subarray [i,j] such that sum of all other elements is divisible by p

    Mathematical Expression
    i.e (totalsum - (prefixsum[j]-prefixsum[i]))%p = 0;
        (totalsum - prefixsum[j] + prefixsum[i])%p = 0;

        prefixsum[i]%p = (prefixsum[j]-totalsum)%p

        but break it more 

        prefixsum[i]%p = (prefixsum[j]%p-totalsum%p)%p

        for avoiding negative number

        prefixsum[i]%p = (prefixsum[j]%p-totalsum%p + p)%p;

*/


    int minSubarray(vector<int>& nums, int p) {

            long long sum = 0;

            for(long long i = 0; i<nums.size(); i++){
                    sum+=nums[i];
            }

            long long to_find = sum%p;

            if(to_find==0) return 0;

            long long total_sum = sum;

            sum = 0;
            long long i = 0;

            unordered_map<long long,long long> mp;
            mp[0]=-1;
            long long mini = LONG_MAX;

            while(i<nums.size()){

                sum+=nums[i];

                long long to_findy = (sum%p-total_sum%p+p)%p;

                if(mp.count(to_findy)){
                    mini=min(mini,i-mp[to_findy]);
                }

                mp[sum%p] = i;

                i++;
            }

            if(mini==LONG_MAX) return -1;
            else {
                if(mini==nums.size()) return -1;
                else return mini;
            }
    }
};
