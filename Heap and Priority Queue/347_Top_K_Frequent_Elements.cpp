class Solution {
public:

// Approach 1: MAX HEAP 
// TC: O(n*log(n))
// Space complexity : O(N+N) to store the hash map with not more NNN elements and a heap with N elements.
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int> mp;
        for(auto num: nums){
            mp[num]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto it: mp){
            pq.push({it.second,it.first});
        }

        vector<int> ans;
        int p;

        while(k--){
            p=pq.top().second;
            pq.pop();
            ans.push_back(p);
        }

        return ans;
    }
};



// <--------------------------------------------------------MIN-HEAP--------------------------------------------------------------------------------------->


map<int,int> mp;

class Comparator{
            public:
            bool operator()(int n1, int n2){
                return mp[n1]>mp[n2];
            }
 };

class Solution {
public:

// Approach 2: Optimized MIN HEAP 
// TC: O(n*log(k))
// Space complexity : O(N+N) to store the hash map with not more NNN elements and a heap with N elements.

    vector<int> topKFrequent(vector<int>& nums, int k) {

        mp.clear(); // little mistake, I have to clear the map for other testcase
       
        for(auto num: nums){
            mp[num]++;
        }     

        priority_queue<int, vector<int>,Comparator> pq;

        for(pair<int,int> it: mp){
            pq.push(it.first);
            if(pq.size()>k) pq.pop();
        }

        vector<int> ans;

        while(k--){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};



// <----------------------------------------------------------BUCKET SORT----------------------------------------------------------------------------------->


class Solution {
public:

    // BUCKET SORT 
    // unordered this time and some changes done for better TC
    // TC: O(n)
    // SC: O(n)+O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        int n = nums.size();

        for(auto &num: nums){
            mp[num]++;
        }

        vector<vector<int>> bucket(n+1,vector<int> {} );
        int maxi = -1;
        int mini = INT_MIN;
        for(auto &m: mp){
            bucket[m.second].push_back(m.first);
            maxi=max(maxi,m.second);
            mini = min(mini,m.second);
        }

        vector<int> ans;

        for(int i = maxi; i>=mini; i--){
            if(k==0) break;
                while(bucket[i].size()!=0 && k>0){
                        ans.push_back(bucket[i].back());
                        bucket[i].pop_back();
                        k--;
                }
        }
        return ans;        
    }
};
