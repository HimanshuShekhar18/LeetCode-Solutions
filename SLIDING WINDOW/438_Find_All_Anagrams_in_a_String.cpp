class Solution {
public:

/* 
fixed size sliding window
TC: O(n)
SC: O(26)
*/

    vector<int> findAnagrams(string s, string p) {
        int k = p.length();
	    int n = s.length();
	    
	    vector<int> ans;
	   
	    map<char,int> mp;
	    
	    int j = 0;
	    int i = 0;
	    
	    for(int i = 0; i<k; i++) mp[p[i]]++;
	    
	    int count = mp.size();
	    
	    while(j<n){
	        
	        if(mp.find(s[j])!=mp.end()) {
	            mp[s[j]]--;
	            if(mp[s[j]]==0) count--;
	        }
	        
            if(j-i+1==k){
	            if(count==0) ans.push_back(i);
	            if(mp.find(s[i])!=mp.end()) {
	                mp[s[i]]++;
	                 if(mp[s[i]]==1) count++;
	            }
	            i++;
	        }
	        j++;
	    }
	    return ans;
    }
};
