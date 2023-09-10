class Solution {
public:
// LIS + BINARY SEARCH
// TC: O(n*log(n))
// SC: O(n)
/*
You can't put envelopes with the same widths into each other. If our sorted list looked like this: [[4,6], [4,8]], the length of LIS would be 2, however the expected answer is 1 (same widths). The trick protects us from such a situation (for [[4,8],[4,6]] the length of LIS=1).
Hence, we sort width in ascending order while height in descending order.
*/
static bool comp(vector<int> &a, vector<int> &b){
      if(a[0]<b[0]) return true;
      else if(a[0]>b[0]) return false;
      else return a[1]>b[1];
}
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
         vector<int> temp;
         temp.push_back(envelopes[0][1]);

      for (int i = 1; i < n; i++)
      {
            if (envelopes[i][1] > temp.back())
                  temp.push_back(envelopes[i][1]);
            else
            {
                  // binary search
                  int ind = lower_bound(temp.begin(), temp.end(), envelopes[i][1]) - temp.begin();
                  temp[ind] = envelopes[i][1]; 
            }
      }

      return temp.size();
    }
};

