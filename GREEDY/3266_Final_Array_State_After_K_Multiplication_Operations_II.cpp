/*
Greedy and Min-Heap ( PQ)
i) Either 'k' finishes or all the elements of nums get multiplied by multiplier atleast once
ii) After that cyclicity of Operation begins and Greedly Distribute k/n multiplier to each element 
iii) After this Operation all the elements are in sorted ascending order itself.
iv) After that k%n multiplier to each minimum element.
TC: O(n * log(n))
SC: O(n)
*/

class Solution {
public:

/*

MIN-HEAP (PRIORITY QUEUE) and GREEDY
TC: O(n*log(n))
SC: O(n)

*/
    const int MOD = 1e9+7;

    long long expo(long long a, long long b){
        long long res = 1;
        while(b>0){
            if(b&1){
                res = (res * a)%MOD;
            }
            a = (a * a)%MOD;
            b=b>>1;
        }
        return res%MOD;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        if(multiplier==1) return nums;
        int n = nums.size();
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;

        for(int i = 0; i<nums.size(); i++){
            pq.push({nums[i],i});
        }
      
        unordered_map<long long, long long> mp;

        // Either 'k' finishes or all the elements of nums get multiplied by multiplier atleast once
        while(k>0){
            if(mp.size()==n) break;
            auto [value,index] = pq.top();
            pq.pop();

            long long minvalue = value*multiplier;
            pq.push({minvalue,index});
            k--;
            mp[index]++;
        }

        /*
        After that cyclicity of Operation begins and Greedly Distribute k/n multiplier to each element 
        */
        vector<pair<long long,long long>> number;
        long long distribute = k/n;
        long long numslength = n;   
        while(numslength>0){
            auto [value,index] = pq.top();
            pq.pop();
            long long fastexpo = expo(multiplier,distribute); 
            number.push_back({value%MOD*fastexpo,index});
            numslength--;
        }

        // and After that k%n multiplier to each minimum elements.
        long long leftout = k%n;
        int index = 0;
        while(index<leftout){
            number[index] = {((number[index].first)%MOD)*multiplier,number[index].second};
            index++;
        }

        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            ans[number[i].second]=number[i].first%MOD;
        }

        return ans;
    }
};


