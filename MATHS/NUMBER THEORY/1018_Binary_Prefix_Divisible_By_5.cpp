class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long prenum = 0;
        vector<bool> answer;
        for( auto i: nums){
            long long num = (2*prenum+i)%5; // modulo 5 to get rid of extra multiples of 5
            if(num%5==0) answer.push_back(true);
            else answer.push_back(false);
            prenum=num;
        }
        return answer;
    }
};
