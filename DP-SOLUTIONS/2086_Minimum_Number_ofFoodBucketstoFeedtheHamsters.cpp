// <------------------------------------------------ DP TABULATION ---------------------------------------------------------->


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


        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;

        for(int i = 0; i<n;i++){
            if(hamsters[i]=='H'){
                if(i-1>=0 && hamsters[i-1]=='B'){
                    dp[i]=dp[i-1];
                    continue;
                } 
                if(i+1<n){
                if(hamsters[i+1]=='.'){
                    hamsters[i+1] = 'B';
                    dp[i]=i-1>=0?dp[i-1]+1:dp[0]+1;
                }
                else{
                    hamsters[i-1] = 'B';
                    dp[i]=dp[i-1]+1;
                }
                }
                else {
                    hamsters[i-1] = 'B';
                    dp[i]=dp[i-1]+1;
                }
            }
            else dp[i]=(i-1)>=0?dp[i-1]:dp[0];
        }

        return dp[n-1];
    }
};



// <----------------------------------------------------------- SPACE OPTIMIZED ---------------------------------------------------------------------->


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
        
        int curr , prev=0;

        for(int i = 0; i<n;i++){
            if(hamsters[i]=='H'){
                if(i-1>=0 && hamsters[i-1]=='B'){
                    curr=prev;
                    continue;
                } 
                if(i+1<n){
                if(hamsters[i+1]=='.'){
                    hamsters[i+1] = 'B';
                    curr=i-1>=0?prev+1:1;
                }
                else{
                    hamsters[i-1] = 'B';
                    curr=prev+1;
                }
                }
                else {
                    hamsters[i-1] = 'B';
                    curr=prev+1;
                }
            }
            else curr=(i-1)>=0?prev:0;

            prev = curr;
        }

        return prev;
    }
};






