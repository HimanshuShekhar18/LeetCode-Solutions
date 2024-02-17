class Solution {
public:

/*
Priority Queue: Min Heap
TC: O(n*log(n))
SC: O(n)
*/
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int jump = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 1; i<n; i++){
            jump=heights[i]-heights[i-1];

            // ladders are used only for larger jumps
            if(jump>0) pq.push(jump);

            // when no. of jumps is greater than no. of ladders then we need to take bricks
            if(pq.size()>ladders){
                bricks-=pq.top();
                pq.pop();
            }

            if(bricks<0) return i-1;
        }

        return n-1;
    }
};


