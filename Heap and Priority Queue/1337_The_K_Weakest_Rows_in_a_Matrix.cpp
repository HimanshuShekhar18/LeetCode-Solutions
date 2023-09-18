class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i<mat.size(); i++){
            int cnt = 0;
            for(int j = 0; j<mat[i].size(); j++){
                if(mat[i][j]==0) break;
                cnt++;
            }
            pq.push({cnt,i});

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// <---------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

class Solution {
public:

// Binary Search + Max-Heap
// TC: O(m*(log(n)+log(k)))
// SC: O(2*k)

    int findSoldierCount(vector<int> &row) {
        int left = 0, right = row.size() - 1;

        // Perform binary search to find the count of soldiers
        while (left <= right) {
            int mid = (left + right) / 2;
            if (row[mid] == 1)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i<mat.size(); i++){          
            pq.push({findSoldierCount(mat[i]),i});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


