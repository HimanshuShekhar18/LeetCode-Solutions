class Solution {
public:
// TC: O(tasks.length()+mp.size()+mp.size()*n)
// SC: O(2*mp.size()+mp.size())

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto ch: tasks){
            mp[ch]++;
        }
        priority_queue<int> pq;
        for(auto m: mp){
            pq.push(m.second);
        }
        long long ans = 0;

        vector<int> temp;

        while(!pq.empty()){
            
            for(int i = 0; i<=n; i++){
                temp.push_back(pq.top());
                pq.pop();
                if(pq.empty()) break;                
            }
            for(int i = 0; i<temp.size(); i++){
                if(--temp[i]>0) pq.push(temp[i]);
            }
            ans+=pq.empty()?temp.size():n+1;
            temp.clear();
        }
        return ans;
    }
};
