class Solution {
public:

// TC: O(q*log(q)) + O (q*32 + n*32)
// SC: O(q*3) + O(32*n)

    struct Node {
    Node* links[2];

    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }

    Node* get(int bit){
        return links[bit];
    }

    void create(int bit, Node* node){
        links[bit] = node;
    }
};


// with respect to node you need a TRIE

class Trie{

    private: Node* root;

    public:

    Trie(){
        root = new Node();
    }


    void insert(int num){
        Node* node = root;
        for(int i = 31; i>=0; i--){
            int bit = (num>>i)&1;
            if(!(node->containsKey(bit))){
                node->create(bit,new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
         Node* node = root;
            int maxNum = 0;
         for(int i = 31; i>=0; i--){
                int bit = (num>>i)&1;
                if((node->containsKey(1-bit))){
                    maxNum = maxNum | (1<<i);
                    node = node->get(1-bit);
                }
                else {
                    node = node->get(bit);
                }
         }
         return maxNum;
    }    
};


vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries){
	// sorted in ascending order
	sort(nums.begin(),nums.end());

	vector<pair<int,pair<int,int>>> offlineQueries;
	int q = queries.size();
	for(int i = 0; i<q; i++){
          offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
    }

		// sorted in ascending order of ai;
            // O(q*log(q))
		sort(offlineQueries.begin(),offlineQueries.end());

		vector<int> ans(q,0);
		int ind = 0;
        int n = nums.size();
        Trie trie;
        // O(q*32 + q*32)  --> 32 in getMax and insert;
		for(int i = 0; i<q; i++){
			int ai = offlineQueries[i].first;
			int xi = offlineQueries[i].second.first;
			int queryindex = offlineQueries[i].second.second;

			while(ind<n && nums[ind]<=ai){
				trie.insert(nums[ind]);
				ind++;
			}

			if(ind==0) ans[queryindex]=-1;

            else ans[queryindex]=trie.getMax(xi);
		}

        return ans;
}
    
};

