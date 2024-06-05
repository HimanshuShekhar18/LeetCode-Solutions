class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        unordered_map<int,int> mp;

        string str = words[0];

        for(int  j = 0; j<str.length(); j++){

                mp[str[j]-'a']++;

        }

        unordered_map<int,int> mpp;

        for(int  i = 1; i<words.size(); i++){

            str = words[i];

            for(int  j = 0; j<str.length(); j++){

                    if(mp[str[j]-'a']>0){
                        mpp[str[j]-'a']++;
                    }
                    else{
                        mp[str[j]-'a'] = 0;
                        continue;
                    }
            }

            for(int i = 0; i<26; i++){

                    if(mpp[i]>0) mp[i]=min(mp[i],mpp[i]);
                    else mp[i] = 0;
            }

            mpp.clear();
        }

        vector<string> ans;


        for(auto it: mp){
            if(it.second>0) {
                while(it.second>0){
                    ans.push_back(string(1,it.first+'a'));
                    it.second--;
                }
            }    
        }

        return ans;   
    }
};
