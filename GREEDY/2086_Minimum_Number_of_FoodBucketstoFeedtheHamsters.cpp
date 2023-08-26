class Solution {
public:
    int minimumBuckets(string hamsters) {

        int n = hamsters.length();
       
        if(n==1) {
            if(hamsters[0]=='.') return 0;
            else return -1;
        }
       
        bool flag = false;
        for(int i = 0; i<n;i++){
            if(hamsters[i]=='H'){
                flag = false;
                if(i-1>=0){
                    if(hamsters[i-1]=='.') flag = true;
                }
                if(i+1<n){
                    if(hamsters[i+1]=='.') flag = true;
                }
                if(flag == false) return -1;
            }
        }

        int cnt = 0;

        for(int i = 0; i<n;i++){
            if(hamsters[i]=='H'){
                if(i-1>=0 && hamsters[i-1]=='B') continue;
                if(i+1<n){
                if(hamsters[i+1]=='.'){
                    hamsters[i+1] = 'B';
                    cnt++;
                }
                else{
                    hamsters[i-1] = 'B';
                    cnt++;
                }
                }
                else {
                    hamsters[i-1] = 'B';
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
