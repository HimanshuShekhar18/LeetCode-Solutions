class Solution {
public:

    bool check(vector<int> &position, int mid, int m){

        int prevstart = position[0];
        int balls = 1;

        for(int i = 1; i<position.size(); i++){

            if(position[i]-prevstart>=mid){
                balls++;
                prevstart=position[i];
            }

        }
        return balls>=m;
    }

    int maxDistance(vector<int>& position, int m) {

            sort(position.begin(),position.end());

            int n = position.size();

            int left = 1;
            int right = ceil((double)position[n-1]/(m-1));  // maximum possible gap between two adjacent balls 
            int ans = 0;
            while(left<=right){

                    int mid = right - (right-left)/2;

                    if(check(position,mid,m)){

                        ans = mid;
                        left = mid+1;

                    }
                    else{
                            right = mid-1;
                    }

            }
        return ans;
    }
};
