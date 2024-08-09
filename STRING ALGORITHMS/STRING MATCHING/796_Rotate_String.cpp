class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = goal.length();
        int s_length = s.length();
        if(s_length!=n) return false;
        string new_string = goal+"#"+s+s;
        int new_length = new_string.length();
        vector<int> lps(new_length,0);
        
        int i = 1; 
        int len = 0;

        while(i<new_length){
            if(new_string[i]==new_string[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len>0){
                    len = lps[len-1];
                }
                else{
                    i++;
                }
            }
        }

        for(int j = n+1; j<new_length; j++){
            if(lps[j]==n){
                return true;
            }
        }
        return false;
    }
};
