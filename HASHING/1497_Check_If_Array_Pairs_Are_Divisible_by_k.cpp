class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

            int sum = 0;

            map<int,int> mp;

            for( int i = 0; i<arr.size(); i++){
                sum+= arr[i]%k;
                mp[(arr[i]%k + k)%k]++;
            }

            if(sum%k!=0) return false;
            else {
                for(int i = 0; i<k; i++){
                    if(i==0){
                        if(mp[i]%2!=0) return false;
                    }
                    else if(i == k-i){
                        if(mp[i]%2!=0) return false;
                    }
                    else {
                        if(mp[i]!=mp[k-i]) return false;
                    }
                }
                return true;
            }   
    }
};
