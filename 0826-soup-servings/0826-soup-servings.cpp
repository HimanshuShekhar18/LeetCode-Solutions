class Solution {
public:

    // Explanation Actually how the operation is working
    /*
    Example 2:
    Input: n = 100
    Output: 0.71875
    We start with (100, 100)
Try to serve (100, 100) in these 4 ways, see what is left, the probability of each will be multiplied by 0.25:
____1. (0, 100)
____A is 0, so the probability is 1.

____2. (25, 75)
____Try to serve (25, 75) in these 4 ways, see what is left, the probability of each will be multiplied by 0.25:

________2.1. (0, 75)
________A is 0, so the probability is 1.
________2.2. (0, 50)
________A is 0, so the probability is 1.
________2.3. (0, 25)
________A is 0, so the probability is 1.
________2.4. (0, 0)
________Both A and B are 0, we take only half of the probability, so 0.5.

____So the total probability of option 2 is (1+1+1+0.5) x 0.25 = 0.875

____3. (50, 50)
____Try to serve (50, 50) in these 4 ways, see what is left, the probability of each will be multiplied by 0.25:

________3.1 (0, 50)
________A is 0, so the probability is 1.
________3.2 (0, 25)
________A is 0, so the probability is 1.
________3.3 (0, 0)
________Both A and B are 0, we take only half of the probability, so 0.5.
________3.4 (25, 0)
________B is 0, so the probability is 0.

____So the total probability of option 3 is (1+1+0.5+0) x 0.25 = 0.625

____4. (75, 25)
____Try to serve (75, 25) in these 4 ways, see what is left, the probability of each will be multiplied by 0.25:

________4.1 (0, 25)
________A is 0, so the probability is 1.
________4.2 (0, 0)
________Both A and B are 0, we take only half of the probability, so 0.5.
________4.3 (25, 0)
________B is 0, so the probability is 0.
________4.4 (50, 0)
________B is 0, so the probability is 0.

____So the total probability of option 4 is (1+0.5+0+0) x 0.25 = 0.375

To get the final result, add up the probabilities of the 4 options:
Answer = (1+0.875+0.625+0.375) x 0.25 = 2.875 x 0.25 = 0.71875
    */

    // so we can simply draw a recursive tree

    /*
                            100,100 `
                          `    `   `     `
                        `     `      `       `
                      `      25,75`     `         `
                    `      `  `  `  `       `          `
                  `       `   `   `    `      `            `
              0,100      `    `     `     `     `             `
         (return 1)    0,75    0,50  0,25   0,0    `             `
                        (1)     (1)   (1)   (0.5)    `              `
                                                    50,50 `             `
                                                   `  `  `  `               `
                                                `    `    `   `                 `
                                              `     `       `   `                   `
                                            0,50   0,25    0,0  return 0                `
                                            (1)     (1)   (0.5)                             `
                                                                                            (75,25) `
                                                                                           `  `   `    `
                                                                                          `   `    `     `
                                                                                         `    `     `      `
                                                                                        `     `      `        `
                                                                                       0,25  0,0   return 0   return 0;
                                                                                       (1)  (0.5)
      */
// notice one thing ki probability is 0, if b becomes 0 before a 
// In 100 ml of soup only then possibility of probability = 0 which decreases the overall probability(total); is 3 out of 16.
// but the effect of this decrement fades away with increase in value of 'n' and is negligible when n is very large
// for n>=5000, probability is almost 1;

// Approach used is DP: TC=O(4*4*5000), SC=O(5000*5000)

vector<vector<int>> values = {{100,0},{75,25},{50,50},{25,75}};
    
      double recursion(int a, int b,vector<vector<double>> &dp){
      
          if(a<=0 && b<=0)
          return 0.5;
          if(a<=0) 
          return 1.0;
          if(b<=0) return 0.0;
          if(dp[a][b]!=-1.0) return dp[a][b];

          double total = 0.0;

          for(auto value: values){
              int x = a-value[0];
              int y = b-value[1];
              total+=recursion(x,y,dp);
          }

          return dp[a][b] = total*0.25;
      }

    double soupServings(int n) {



        if(n>=5000){
            return 1;
        }

        vector<vector<double>> dp(n+1,vector<double> (n+1,-1.0));

       return recursion(n,n,dp);
        
    }
};