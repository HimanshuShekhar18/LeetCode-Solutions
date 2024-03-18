class Solution {
public:

    static bool compare(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), compare);
        
        int k = points[0][1];
        int ans = 1;

        for(int i = 1; i<points.size(); i++){

            int x = points[i][0];
            int y = points[i][1];


            if(x>k){
                ans++;
                k = y;
            }
        }

        return ans;
    }
};


