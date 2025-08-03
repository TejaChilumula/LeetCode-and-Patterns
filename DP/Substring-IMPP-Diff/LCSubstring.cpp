class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {

        
        int n = s1.size(); 
        int m = s2.size();
        int ans = 0;
        
        // Different to the actual subsequence problems

        /*
            - We can't take the else condition like
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) 
                 - because it violates the substring case, it becomes the subsequence !!!!

            and also we need to start from scratch, if we failed up to form a substring, or a diff element comes in between
             dp[i][j] = 0
            
                0    1   2   3   4
                    a    b   c   d
            a . 1   1    0   0 . 0
            b   2   0 .  2 . 0 . 0
            x   3 . 0 .  0 . 0 . 0
            d   4 . 0 .  0 . 0 . 1

            take the max = 2

        */
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]) 
                    {
                        dp[i][j] = 1 + dp[i-1][j-1];
                        ans = max(ans, dp[i][j]);
                    }
                else
                    dp[i][j] = 0;
            }
        }
        
        return ans;
        
    }
};