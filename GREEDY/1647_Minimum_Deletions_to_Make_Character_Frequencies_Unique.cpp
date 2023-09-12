class Solution {
public:

// Previous RE; bcoz I forgot "newfreq>0" condition to avoid index out of bound
// Approach : Hashing + Sorting + Greedy 
// TC: O(n*log(n))
// SC: O(n)

    int minDeletions(string s) {
        
     map<char,int> mp;
       for(int i = 0; i<s.length(); i++){
           mp[s[i]]++;
       }
       vector<pair<int,char>> vect;
       for(auto m : mp){
           vect.push_back({m.second,m.first});
       }

       sort(vect.begin(),vect.end());
       reverse(vect.begin(),vect.end());

       int vis[100005];
       memset(vis,0,sizeof(vis));
      
       int cnt = 0;
       for(auto vec: vect){
           int freq = vec.first;
           int newfreq = freq;
           if(vis[newfreq]!=0){
           while(vis[newfreq]!=0 && newfreq>0) newfreq--, cnt++;  // changes done here --> newfreq > 0, to avoid index out of bound
           }
           vis[newfreq]=1;           
       }
        return cnt;
    }
};

