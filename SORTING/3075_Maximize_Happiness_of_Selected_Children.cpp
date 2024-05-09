class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {


        long long ans = 0;

        int kstart = k;

        k--;

        ans+=*max_element(happiness.begin(),happiness.end());

        priority_queue<int> pq;

        for(int i = 0; i<happiness.size(); i++){
            pq.push(happiness[i]);
        }

        int n = happiness.size();

        pq.pop();

        while(k>0){
            int num = pq.top();
            if(num-(1*(kstart-k))>=0) ans+=num-(1*(kstart-k));
            else ans+=0;
            pq.pop();
            k--;
        }

        return ans;        
    }
};



// <------------------------------------------------------------------------SORITNG-------------------------------------------------------------------------------------------------->


class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        long long ans = 0;

        int n = happiness.size();

        sort(happiness.begin(),happiness.end());

        for(int i = 0; i<k; i++){
            ans+=(happiness[n-1-i]-i)>=0?happiness[n-1-i]-i:0;
        }

        return ans;        
    }
};


