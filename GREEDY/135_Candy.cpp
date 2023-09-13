class Solution {
public:
    /*
    TestCase Examine: [1,2,87,87,87,2,1]
    Output = 13
    
    1) From Left to Right mincandies = {1,2,3,1,1,2,1}
    2) From Right to Left mincandies = {1,1,1,1,3,2,1}

    At the end taking max of mincandies = {1,2,3,1,3,2,1}
    Total mincandies = 1+2+3+1+3+2+1 = 13
    */
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1) return 1;
        vector<pair<int,int>> candies;
        for(int i = 0; i<n; i++){
            candies.push_back({ratings[i],1});
        }

        for(int i = 1; i<n; i++){
                if(candies[i].first==candies[i-1].first) continue;
                else if(candies[i].first>candies[i-1].first) candies[i].second = candies[i-1].second+1;
        }
        for(int i = n-2; i>=0; i--){
                if(candies[i].first==candies[i+1].first) continue;
                else if(candies[i].first>candies[i+1].first) candies[i].second = max(candies[i].second,candies[i+1].second+1);   // changes done here; bcoze you stupid chagnes tabhi karenga na jab iss jyada milega ya phir yahi rahe jo pehle tha isse kam thodi lena hain.
        }
        
        int mincandies = 0;
        for(auto candy: candies){
            mincandies+=candy.second;
        }
        return mincandies;
    }
};



// <--------------------------------------------------------------------SC: O(1) ------------------------------------------------------------------------------------>

class Solution {
public:
    /*

    APPROACH MOUNTAIN --> (UP, PEAK and DOWN)
    TC: O(n)
    SC: O(1)
    ratings = {1,2,5,7,8,4,2,5,2,2}

                        Here --> peak = 4 and down = 2

                                                8
                                               `  `
                                              7    `
                                             `      `
                                            5        `      5
                                           `          4    `  `
                                          `            `  `    `
                                         2              2       2 ` ` ` 2
                                        `
                                       1 

                        Here -->  What If down = peak 
                                       peak = 4  and down = 4  

                                                 8
                                               `  `
                                              7    `
                                             `      `
                                            5        `      5
                                           `          4    `  `
                                          `            `  `    `
                                         2              2       2 ` ` ` 2
                                        `                `
                                       1                  1
                                                           `
                                                            0
            still holds good 

            BUT,            
                        Here -->  What If down > peak 
                                       peak = 4  and down = 5  

                                                 8
                                               `  `
                                              7    `
                                             `      `
                                            5        `      5
                                           `          4    `  `
                                          `            `  `    `
                                         2              2       2 ` ` ` 2
                                        `                `
                                       1                  1
                                                           `
                                                            0
                                                             `
                                                              -1
                 
                    one more increments is needed  mincandies+1                               
    */
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int mincandies = 1;  // base to banana padega for i = 0 ke liye
        int peak = 0, up = 0, down = 0;
        for(int i = 1; i<n; i++){
                // ascending 
                if(ratings[i]>ratings[i-1]) {
                        peak=++up;
                        down = 0;
                        mincandies+=peak+1;
                }
                // stable horizontal level
                else if(ratings[i]==ratings[i-1]) {
                    up = 0;
                    down = 0;
                    peak=0;
                    mincandies++;
                }
                // decreasing 
                else {
                    down++;
                    up=0;
                    if(down>peak) mincandies+=1;
                    mincandies+=down;
                }
        }
        return mincandies;
    }
};


