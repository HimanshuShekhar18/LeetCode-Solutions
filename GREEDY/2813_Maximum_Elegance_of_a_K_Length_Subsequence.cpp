class Solution {
public:

    /*
        Here the exprsession is total_profit + (distinct_categories)^2
        
        So here square part has more weightage

        Hence we will try to matain maximum unique categories 
    */

    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        
        // sort by descending order of profits
        sort(items.begin(),items.end());
        reverse(items.begin(),items.end());

        unsigned long long  maxi = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        unordered_map<int,int> mp;

        // take out first most k profits
        for(int i = 0; i<k; i++){
            maxi+=items[i][0];
            mp[items[i][1]]++;
            pq.push({items[i][0],items[i][1]});
        }

        long long profitsum = maxi;
        maxi+=mp.size()*1LL*mp.size();
        
        for(int i = k; i<items.size(); i++){

                // if the category is already present then continue
                if(mp.count(items[i][1])) continue;

                auto it = pq.top();
                pq.pop();
                
                // we will not substract profits at the top having category with frequencies = 1;
                while(!pq.empty() && mp[it.second]==1){
                    it = pq.top();
                    pq.pop();
                }

                if(pq.empty()) break;

                mp[it.second]--; // decrease the frequency of category taken out 
                mp[items[i][1]]++; // increase the frequency of newly add category
                profitsum-=it.first; // exclude the minimum profit
                profitsum+=items[i][0]; // include the profit of newly added category
                maxi=max(maxi, (profitsum+ mp.size()*1LL*mp.size()));
        }

        return maxi;
    }
};

