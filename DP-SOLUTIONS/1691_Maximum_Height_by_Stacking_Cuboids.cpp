class Solution {
public:

    // SORTING + LIS
    // TC: O(n*(3*log(3))) + O(n*log(n)) + O(n^2)
    // SC: O(2*n)

    bool check(vector<int> base, vector<int> newBox){
        if(newBox[0]<= base[0] && newBox[1] <= base[1] && newBox[2]<=base[2]) return true;
        else return false;
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        // sort all dimensions for every cuboid

        for(auto &cuboid: cuboids){
            sort(cuboid.begin(),cuboid.end());
        }

        // sort all cuboids in ascending order
        // 
        sort(cuboids.begin(),cuboids.end());

       int n = cuboids.size();
        vector<int> currrow(n+1,0);
        vector<int> nextrow(n+1,0);

        for(int curr = n-1; curr>=0; curr--){
        for(int prev = curr-1; prev>=-1; prev--){
        int take = 0;
        // changes done on condition
        // this time since we are calculating height instead of "1" we have added height 
        if(prev==-1 || check(cuboids[curr],cuboids[prev])) take = cuboids[curr][2]+nextrow[curr+1];
        int not_take = 0 + nextrow[prev+1];
        currrow[prev+1]=max(take,not_take);
        }
            nextrow = currrow;
        }
        return nextrow[-1+1]; 
    }
};


