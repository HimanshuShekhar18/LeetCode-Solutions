class Solution {
public:

/*

Sorting and STL upper bound
TC: O(n*log(n))
SC: O(n)

*/
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        vector<pair<int,int>> vect;
        vector<int> search;

        for(int i = 0; i<difficulty.size(); i++){
            search.push_back(difficulty[i]);
            vect.push_back({difficulty[i],profit[i]});
        }

        sort(vect.begin(),vect.end());
        sort(search.begin(),search.end());

        vector<int> maxi(difficulty.size());

        maxi[0]=vect[0].second;

        for(int i = 1; i<difficulty.size(); i++){
            maxi[i] = max(vect[i].second,maxi[i-1]);
        }

        long long sum = 0;
        for(int i = 0; i<worker.size(); i++){
            int index = upper_bound(search.begin(),search.end(),worker[i]) - search.begin();
            if(index==0) continue;
            sum+=maxi[index-1];
        }
        return sum;
    }
};



// <--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

/*

Memoization Approach Prefix Computation
TC: O(n)
SC: O(n)

*/



class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

            int maxiworker = *max_element(worker.begin(),worker.end());

            vector<int> job(maxiworker+1,0);

            for(int i = 0; i<difficulty.size(); i++){
                if(difficulty[i]<=maxiworker) job[difficulty[i]]=max(job[difficulty[i]],profit[i]);
            }

            for(int i = 1; i<=maxiworker; i++){
                job[i]=max(job[i],job[i-1]);
            }

            long long sum = 0;
            for(int i = 0; i<worker.size(); i++){
                sum+=job[worker[i]];
            }

            return sum;
        
    }
};



