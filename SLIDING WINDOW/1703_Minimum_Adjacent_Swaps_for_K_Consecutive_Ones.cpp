/*
i) Maintain a Fixed Size Sliding Window of 'K' 1s  
ii) Find the Median/Middle '1'  
iii) Calculate moves to collect all 1s at Mid using Prefix Computation of indexes of 1s  
iv) Calulate jumps to Redistribute those 1s around Mid  v) Substract iii - iv
TC: O(n) SC: O(n)  
  
*/

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {

        vector<int> storeones;

        if (k == 1) {
            return 0;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                storeones.push_back(i);
        }

        int n = storeones.size();
        int i = 0, j = 0;

        vector<long long> prefix(n, 0);

        for (int i = 0; i < n; i++) {
            if (i == 0)
                prefix[i] = storeones[i];
            else {
                prefix[i] += prefix[i - 1] + storeones[i];
            }
        }

        long long ans = LLONG_MAX;

        while (j < n) {

            if (j - i + 1 < k) {
                j++;
                continue;
            } else {

                if (k % 2 != 0) {

                    int mid = (i + j) / 2;

                    long long movestocollectall1s;

                    if ((i - 1) >= 0) {
                        movestocollectall1s = (prefix[j] - prefix[mid]) - (prefix[mid-1] - prefix[i - 1]);
                    } else {
                        movestocollectall1s = (prefix[j] - prefix[mid]) - (prefix[mid-1]);
                    }

                    long long radius = mid - i;

                    long long movestodistribute = radius * (radius + 1);

                    ans = min(ans, movestocollectall1s - movestodistribute);
                    j++;
                    i++;

                } else {
                    
                    int mid = (i + j) / 2;

                    long long movestocollectall1s;

                    if ((i - 1) >= 0) {
                        movestocollectall1s = (prefix[j] - prefix[mid]) - (prefix[mid]-prefix[i-1]);
                    } else {
                        movestocollectall1s = (prefix[j] - prefix[mid]) - prefix[mid];
                    }

                    long long radius = mid - i;

                    long long movestodistribute = (radius * (radius + 1));

                    movestodistribute += j - mid;
                    
                    ans = min(ans, movestocollectall1s - movestodistribute);
                    j++;
                    i++;
                }
            }
        }

        return ans;
    }
};
