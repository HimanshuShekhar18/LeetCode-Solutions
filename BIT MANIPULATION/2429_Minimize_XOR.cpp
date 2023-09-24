class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int num1set = __builtin_popcount(num1);
        int num2set = __builtin_popcount(num2);
        cout << num1set << endl;
        cout << num2set << endl;
        int ans = 0;
        if(num2set==num1set) return num1;
        else if(num1set>num2set){
            int extra = num2set;
            for(int i = 31; i>=0; i--){
                if(extra==0) break;    // changes done here 
                if((num1>>i)&1) ans = ans | (1<<i) , extra--;  // changes done here
            }
            return ans;
        }
        else {
            int extra = num2set-num1set;
            ans = num1;
            for(int i = 0; i<=31; i++){
                if(extra==0) break;
                if(!((ans>>i)&1)) {
                    ans = ans | (1<<i);
                    extra--;
                }
            }
        }
        return ans;
    }
};

