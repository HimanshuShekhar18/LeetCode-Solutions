class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());  // for comparison
        vector<int>vis(s.length()+1,0);    // to avoid repeated visits
        priority_queue<int> q;             // to get maximum index first
     
        q.push(0);
        
        while (!q.empty()) {
            int start = q.top();
            q.pop();
            
            if (start == s.length()) {
                return true;
            }          
                for (int end = start + 1; end <= s.length(); end++) {
                if(!vis[end]){
                if (words.find(s.substr(start, end - start)) != words.end()) {
                    q.push(end);  
                    vis[end]=1; 
                }
              }
            }           
        }
        
        return false;
    }
};
