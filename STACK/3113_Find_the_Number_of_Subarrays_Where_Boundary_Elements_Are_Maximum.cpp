class Solution {
public:

/*
Monotonic Stack and unordered_map for frequencies
TC: O(n)
SC: O(n)
*/
    long long numberOfSubarrays(vector<int>& nums) {

        unordered_map<long long,long long> mp;
        stack<int> st;

        long long count = 0;

        for(int i = 0; i<nums.size(); i++){
            while(!st.empty() && st.top()<nums[i]) {mp[st.top()] = 0; st.pop(); }

            if(!st.empty() && st.top()==nums[i]){
                mp[nums[i]]++;
            }
            else {
                st.push(nums[i]);
                mp[nums[i]]++;
            }

            count+=mp[nums[i]];
            cout << count << endl;
        }
        return count;
    }
};
