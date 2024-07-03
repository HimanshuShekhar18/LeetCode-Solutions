

/*

Variable Size Sliding Window and Multiset
TC: O(n*log(n))
SC: O(n)

*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        multiset<int> st;
        int ans = 1;
        int i = 0, j = 0;

        while (j < nums.size()) {

            st.insert(nums[j]);

            int start = *(st.begin());
            int end = *(st.rbegin());

            while (abs(start-end)>limit) {
                st.erase(st.find(nums[i]));
                i++;
                start=*(st.begin());
                end=*(st.rbegin());
            }

            ans = max(ans, j - i + 1);

            j++;
        }

        return ans;
    }
};



// <------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


/*

Time Optimization Using Two Deque: MaxDeque and MinDeque
TC: O(n)
SC: O(n)

*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        deque<pair<int,int>> maxdeque;
        deque<pair<int,int>> mindeque;
        int ans = 1;
        int i = 0, j = 0;

        while (j < nums.size()) {

            while(!maxdeque.empty() && maxdeque.back().first <= nums[j]) maxdeque.pop_back();

            maxdeque.push_back({nums[j],j});

            while(!mindeque.empty() && mindeque.back().first >= nums[j] ) mindeque.pop_back();

            mindeque.push_back({nums[j],j});

            int difference = abs(maxdeque.front().first-mindeque.front().first);

            if(difference>limit){
                i = min(maxdeque.front().second,mindeque.front().second)+1;

                while(!maxdeque.empty() && maxdeque.front().second < i) maxdeque.pop_front();

                while(!mindeque.empty() && mindeque.front().second < i) mindeque.pop_front();
            }  

            ans = max(ans, j-i+1);

            j++;
        }

        return ans;
    }
};


