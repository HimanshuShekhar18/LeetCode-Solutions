class Solution {
public:
    const int mod = 1000000007;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>,  greater<long long>> pq;
        int n = nums.size();
        int i = 0;
        while(i<n){
            pq.push(nums[i]);
            i++;
        }
        while(k--){
            long long num = pq.top();
            pq.pop();
            num++;
            pq.push(num);
        }
        long long ans = 1;
        while(!pq.empty()){
            ans=(ans%mod*pq.top()%mod)%mod;
            pq.pop();
        }
        return ans%mod;
    }
};
