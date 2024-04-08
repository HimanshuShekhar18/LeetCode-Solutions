class Solution {
public:

   
    int scores[15] = {0};

    bool possible(string word, unordered_map<char,int>&mp){
        unordered_map<char,int> mp1;
        for(auto id: word){
            mp1[id]++;
        }

        for(auto id: word){
            if(mp1[id]>mp[id]) return false;
        }

        for(auto x : mp1){
            mp[x.first]-=x.second;
        }
        mp1.clear();
        return true;
    }

    int solve(int index, vector<string>& words, unordered_map<char,int> &mp){
        if(index==words.size()) return 0;


        bool s = possible(words[index],mp);
        int pick = 0;
        if(s)
        {
            pick = scores[index]+solve(index+1,words,mp);
        
            for(auto id: words[index]){
                mp[id]++;
            }
        }

        int non_pick = 0+solve(index+1,words,mp);

        return max(pick,non_pick);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
         unordered_map<char,int>mp;
        for(int i = 0; i<words.size(); i++){
            int sum = 0;
            for(auto id: words[i]){
                sum+=score[id-'a'];
            }
            scores[i]=sum;
        }

        for(auto id: letters){
            mp[id]++;
        }

        return solve(0,words,mp);

    }
};
