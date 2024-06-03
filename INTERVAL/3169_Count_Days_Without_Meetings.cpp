class Solution {
public:

/*
Sorting and Greedy
Exactly Same as LeetCode 56. Merge Intervals
TC: O(n * log(n))
SC: O(n)
*/
    int countDays(int days, vector<vector<int>>& meetings) {

        int freeDaysCount=0;

        int n = meetings.size();

        if(n==1){
            return meetings[0][0]-1+days-meetings[0][1];
        }

        sort(meetings.begin(),meetings.end());
        vector<vector<int>> ans;

        int start = meetings[0][0];
        int end = meetings[0][1];

        ans.push_back({start,end});

        for(int i = 1; i<n; i++){

            int x = meetings[i][0];
            int y = meetings[i][1];

            if(x<=end){
                ans.pop_back();
                if(y<=end){
                    ans.push_back({start,end});
                }
                else{
                    ans.push_back({start,y});
                    end = y;
                }
            }
            else{
                start = x;
                end = y;
                ans.push_back({start,end});
            }
        }

        int siz = ans.size();

        freeDaysCount+=ans[0][0]-1;
        end = ans[0][1];

        for(int i = 1; i<siz; i++){

            freeDaysCount+=ans[i][0]-end-1;
            end = ans[i][1];

        }

        freeDaysCount+=days-end;

        return freeDaysCount;
    }
};




// <------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

/*

Sorting and Greedy Space Optimization
TC: O(n)
SC: O(1)

*/


class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        int freeDaysCount=0;

        int n = meetings.size();

        if(n==1){
            return meetings[0][0]-1+days-meetings[0][1];
        }

        sort(meetings.begin(),meetings.end());
        

        int start = meetings[0][0];
        int end = meetings[0][1];

       

        for(int i = 1; i<n; i++){

            int x = meetings[i][0];
            int y = meetings[i][1];

            if(x>end){
                freeDaysCount+=x-end-1;
            }
            end=max(end,y);            
        }

        if(start!=1) freeDaysCount+=start-1;
        if(end!=days) freeDaysCount+=days-end;

        return freeDaysCount;
    }
};



