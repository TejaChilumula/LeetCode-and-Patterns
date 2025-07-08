#include<iostream>

using namespace std;

class Solution {
public:
    int good_spots = 0;
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> 
        dp(n, vector<vector<double>>(n, vector<double>(k+1, -1)));

        return dfs(n, k, row, column, dp);

        // Thought of find all the valid spots on the grid after k moves 
        /*
         - But caused the error, because this wont work because,

         total valid moves. = 8 pow k, but its not, if the knight at the corner

         When you divide by 8^k, you're saying:

              ******  “The knight always has 8 choices at each step.” *****

                But in reality:

                The knight may have fewer than 8 valid moves — especially near edges and corners.

            ************************************************************************
        */

        // long long total_valid = dfs(n, k, row, column, dp);

        // long long total_possible_moves = pow(8LL,k);

        // return (double)total_valid/total_possible_moves;

        
    }

    double dfs(int n ,int k, int r, int c, vector<vector<vector<double>>> &dp){

        if (r < 0 || r >= n || c < 0 || c >= n) return 0;
        if(k ==0) return 1;
        if(dp[r][c][k] != -1.0) return dp[r][c][k];
        
        dp[r][c][k] = 0.0;
        vector<vector<int>> dirs {{1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1}};
        double prob = 0.0;
        for(auto dir : dirs){
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            
                    prob  += 0.125*dfs(n, k-1, new_r, new_c, dp);

        }

        return dp[r][c][k] = prob;
    }

};