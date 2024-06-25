class Solution {
public:
    int n;
    long long bit[100005];
    
    void update(long long i, long long val){

        while(i<=n){
            bit[i]+=val;
            i+=(i&(~i+1));
        }
    }

    long long query(int i){
        long long res = 0;
        while(i>0){
            res+=bit[i];
            i-=(i&(~i+1));
        }

        return res;
    }

    int minKBitFlips(vector<int>& nums, int k) {

        n = nums.size();
        memset(bit,0,sizeof(bit));
        for(int i = 1; i<=n; i++){
            update(i,0);
        }

        
        int start = 0;
        int end = k-1;

        int count = 0;

        while(start+k-1<n){

            if(nums[start]==0  && query(start+1)%2==0){
                count++;
                update(start+1,1);
                update(end+2,-1);
            }
            else if(nums[start]==1 && query(start+1)%2!=0){
                    count++;
                    update(start+1,1);
                    update(end+2,-1);
            }
            start++;
            end++;
        }

        for(int i = n-k+1; i<n; i++){
            if(nums[i]==0 && query(i+1)%2==0) return -1;
            if(nums[i]==1 && query(i+1)%2!=0) return -1;
        }

      return count;  
    }
};

