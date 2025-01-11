/*
Approach

Top-Down
Go from bottom position to the start, we have to go up and left from bottom.

Bottom-Up ( Tabulation )
Go from start to bottom, 
	its kind of all the ways so you need to sum up all the ways,
	1. how many ways you reach right and down block, so that the summation ways you can reach that block

Space Optimised
	we only need two vectors ( prev and cur )
	Actually we can only need prev and cur const but we have to keep track of all the prev occurances so that we can cal the cur row
	so

	then we store cur in prev

		cur_row[current_block] = cur_row[current_block - 1] + prev_row[same_block]

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>  dp(m, vector<int> (n,-1));
        //return help(m-1,n-1, m-1,n-1, dp);
        return tabular2(m,n);
    }

// tabular + SO O(1)
int tabular(int m, int n)
{
    vector<vector<int>> dp(m ,vector<int>(n,0));
    for(int i=0;i<m;i++)
    dp[i][0] = 1;
    for(int i=0;i<n;i++)
    dp[0][i] = 1;

    for(int i=1; i<m;i++)
    {
        for(int j=1; j<n ; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

// SO O(1)
int tabular2(int m, int n)
{
    vector<int> prev(n,0);
    vector<int> cur(n,0);

    for(int i=0;i<n;i++)
    prev[i] = 1;

    for(int i=1; i<m;i++)
    {
        for(int j=0; j<n ; j++)
        {
            if(j == 0) 
            {
                cur[0] = 1;
                continue;
            }

            cur[j] = cur[j-1] + prev[j];
        }
        prev = cur;
    }

    return prev[n-1];
}

    // Memoised

int help(int m, int n, int i, int j, vector<vector<int>> &dp)
    {
        if(i == 0 && j ==0) return 1;
        if(i < 0 || i > m || j < 0 || j > n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = help(m,n,i-1,j,dp) + help(m,n,i,j-1,dp);
    }

};