class Compare {
    public:
       bool operator()(pair<int,string> a, pair<int,string> b){
           if(a.first<b.first){
               return true;
           }
           else if(a.first==b.first) return a.second>b.second;
           else return false;
      }
};
class Solution {
public:
    // Priority Queue
    // TC: O(words.length())+O(n)+O(k)
    // SC: O(n)+O(n)
    vector<string> topKFrequent(vector<string>& words, int k) {

        vector<string> ans;

        unordered_map<string,int>mp;

        for(auto word: words){
            mp[word]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare> pq;
        for(auto m: mp){
            pq.push({m.second,m.first});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


// <---------------------------------------------------------MIN HEAP-------------------------------------------------------------------------------->
class Compare {
    public:
       bool operator()(pair<int,string> a, pair<int,string> b){
           if(a.first>b.first){
               return true;
           }
           else if(a.first==b.first) return a.second<b.second;
           else return false;
      }
};
class Solution {
public:
    // Priority Queue --> MIN HEAP 
    // TC: O(words.length())+O(n)+O(k)
    // SC: O(n)+O(k)
    vector<string> topKFrequent(vector<string>& words, int k) {

        vector<string> ans;

        unordered_map<string,int>mp;

        for(auto word: words){
            mp[word]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare> pq;
        for(auto m: mp){
            pq.push({m.second,m.first});
            if(pq.size()>k) pq.pop();
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


