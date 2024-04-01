#include<string>
class Solution {
public:
    int lengthOfLastWord(string s) {

        char ch = ' ';

        if(s.find_last_of(ch)==string::npos) return s.length();

        int index = s.find_last_of(ch);

        if(index!=s.length()-1) return s.length()-1-index;


        for(int i = s.length()-1; i>=0; i--){
            if(s[i]==' ') continue;
            else {index = i; break;}
        }
        int space = -1;
        for(int i = index; i>=0; i--){
            if(s[i]==' ') {space = i; break;}
        }

        if(space == -1) return index+1;
        else return index-space;
    }
};
