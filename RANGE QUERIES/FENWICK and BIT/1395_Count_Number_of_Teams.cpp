class Solution {
public:
    int maxRating;
    void update(vector<long long>& bit, int index, int val) {
        while (index <= maxRating) {
            bit[index] += val;
            index += (index & (~index + 1));
        }
    }

    int query(vector<long long>& bit, int index) {
        int res = 0;
        while (index > 0) {
            res += bit[index];
            index -= (index & (~index + 1));
        }

        return res;
    }

    int numTeams(vector<int>& rating) {

        int ans = 0;
        int n = rating.size();

        maxRating = *max_element(rating.begin(), rating.end());

        vector<long long> LeftBit(maxRating + 1, 0);
        vector<long long> RightBit(maxRating + 1, 0);

        for (auto r : rating) {
            update(RightBit, r, 1);
        }

        for (int i = 0; i < n; i++) {

            // removing the contribution of current rating bcoz
            // only want stricly greater and strictly smaller
            update(RightBit,rating[i], -1);  

            int smallerright = query(RightBit, rating[i]-1);
            int smallerleft = query(LeftBit, rating[i]-1);
            int greaterright = n-(i+1)-smallerright;;
            int greaterleft = i-smallerleft;
            ans += greaterright * smallerleft + smallerright * greaterleft;

            update(LeftBit, rating[i],1);

        }

        return ans;
    }
};

