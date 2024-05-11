class Solution {
public:
    /*

    Algorithm --> Greedy and Maths

    i) if cost1*2<cost2 then simply ans = no. of increaments*cost1;
    ii) else
    Two Subcases

    eg: [4,1,3,8]  --> [8,8,8,8]         and           [1,14,14,15] -->
    [21,21,21,21]

    So how to get maximum element for which we get the minimum cost
    Ans: Traverse from max_element to 2*max_element

    so for the 1st case

    [1,3,4,8]

    maximum element = 8

    difference array = [7,5,4,0]

    now diff1 = num[n-1]-num[0] = 7
    diff2 = 5+4+0 = 9

    since diff2>diff1

    Total increaments = 7+5+4+0 = diff1+diff2

    therefore ans = (increamenst/2)*cost2 + (increament%2)*cost1;

    // <--------------------------------------------------------------------------------------------->

    And For the 2nd Case
    [1,14,14,15]

    maximum element for first time = 15

    difference array = [14,1,1,0]

    now diff1 = num[n-1]-num[0] = 14
    diff2 = 1+1+0 = 2

    since diff1>diff2

    ans = (diff1-diff2)*cost1 + (diff2)*cost2
    and then increment diff1 by 1 and diff2 by n-1 for next maxi element in the
    range [maxi,maxi*2]

    TC: O(n)
    SC: O(1)

    No Sorting of nums array is needed

    */

    // DON'T USE 'mod' everywhere just use it atlast while returning the value

    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {

        const int mod = 1e9 + 7;

        long long sum = accumulate(nums.begin(), nums.end(), sum = 0);

        long long maxi = *max_element(nums.begin(), nums.end());
        long long mini = *min_element(nums.begin(), nums.end());

        long long diff1 = maxi - mini;

        long long diff2 = nums.size() * 1LL * maxi - sum - diff1;

        long long ans = 0;
        long long res = (diff1 + diff2) * cost1; // changed this total_increament*cost1 = ans3
        
        // case 1
        if (cost2 > cost1 * 2) {

            return res%mod;
            
        } else { // case 2

            for (long long i = maxi; i <= 2*maxi; i++) {             

                // ans2
                if (diff1 < diff2) {
                    ans = (diff1 + diff2) / 2 * cost2;
                    if ((diff1 + diff2) % 2 == 1) {
                        ans += cost1;
                    }
                } 
                else {  // ans1
                    ans = ((diff1 - diff2) * cost1 + (diff2)*cost2);
                }

                res = min(res, ans);
                diff1++;
                diff2 += nums.size() - 1;
            }
        }
        return res % mod;
    }
};

