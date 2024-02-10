// <-------------------------------------------------------------NAIVE APPROACH------------------------------------------------------------------------->

class Solution {
public:

    bool solve(int i, int j, string &s){
        string str = s.substr(i,j-i+1);
        string strr = str;
        reverse(strr.begin(),strr.end());
        if(str==strr) return true;
        else return false;
    }

    int countSubstrings(string s) {
        int count = s.size();
        for(int i = 0; i<s.size(); i++){
            for(int j = i+1; j<s.size(); j++){
                if(solve(i,j,s)) count++;
            }
        }
        return count;
    }
};




