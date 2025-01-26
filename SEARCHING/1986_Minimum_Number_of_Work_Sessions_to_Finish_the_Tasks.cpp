/*
Binary Search for Pruning and Recursion plus Backtracking for Iterating through all possible subsets
TC: O( log(n) * n * 2^n )
SC: O( n )
*/

class Solution {
public:
 
    // recursion and backtracking for iterating through all possibilities
    bool isans(vector<int>& tasks, int mid, int i, int sessionTime, vector<int> &work_session){
        if(i==tasks.size()) return 1;

        for(int j = 0; j<mid; j++){

            if(work_session[j]+tasks[i]<=sessionTime){
                // take
                work_session[j]+=tasks[i];
                // next level or next task
                if(isans(tasks,mid,i+1,sessionTime, work_session)){
                    work_session[j]-=tasks[i]; // wapas jate waqt khali kardo
                    return 1;
                }
                // not-take
                work_session[j]-=tasks[i];
            }
            if(work_session[j]==0) break; // it's common sense ki jab jth wala work session(which was empty) se answer nahi aaya to (j+1)th, (j+2)th..... se to same wahi combination banega na for next recursion level and no valid answer is possible
        }
        return 0;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int start = 1;
        int end = n;
        vector<int> work_session(n, 0);
        while(start<end){
            int mid = (end+start)/2;
            if(isans(tasks,mid,0,sessionTime,work_session)){
                end = mid;
            }
            else {
                start = mid+1;
            }
        }
        return start;
    }

};
