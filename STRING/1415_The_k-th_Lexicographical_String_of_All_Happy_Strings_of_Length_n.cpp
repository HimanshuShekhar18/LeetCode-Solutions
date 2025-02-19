class Solution {
public:
/*
sTRING and GREEDY
TC: O(n)
SC: O(1)
*/
    string getHappyString(int n, int k) {
        if(k>(3*(1<<(n-1)))) return "";

        string s = "";
        if(k<=(1<<(n-1))) s+='a';
        else if(k<=(1<<n)) {
            k = k-(1<<(n-1));
            s+='b';
        }
        else {
            s+='c';
            k = k-(1<<n);
        }
        n = n - 1;
        int index = 0;
        while(n>0){
             if(k<=(1<<(n-1))){
                if(s[index]=='a') s+='b';
                else if(s[index]=='b') s+='a';
                else s+='a';
             } 
             else{
                k=k-(1<<(n-1));
                if(s[index]=='a') s+='c';
                else if(s[index]=='b') s+='c';
                else s+='b';
             }
             index=index+1;
             n=n-1; 
        }
        return s;
    }
};

