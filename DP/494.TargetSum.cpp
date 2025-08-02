// 

/*
    To take care of -- 
      - if the nums[0] is 0 then we need to consider 2, +0 and -0
      - we need to consider from the 0th index in j, i.e sum, if the elements in array can be 0
         - if we wont take then in the take condition   dp[0-0], will misses !!!!
     - the Equation wrong ----
         - (totalSum - target)/2 
            - Because, it reserves the target elements and those wont participate in the sum
    ::::: Correct ::::
        - s1 - s2 = target
        - s1 + s2 = totalSum
         - 2s1 = totalSum + target
           s1 = (totalSun + target)/2

*/



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;

        // keep target aside from the total and make the rem as 0, 6 - 3, rem should zero up
        for(int i : nums) totalSum += i;
        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum) return 0;
        int neededSum = (totalSum + target)/2;

        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(neededSum+1,0));

        if(nums[0] == 0) dp[0][0] = 2; // -0 , +0
        else{
            dp[0][0] = 1;
            if(nums[0] <= neededSum) dp[0][nums[0]] = 1;
        }

        for(int i=1;i<n;i++) dp[i][0] = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<=neededSum;j++){
                int not_take = dp[i-1][j];

                int take = 0;
                if(j-nums[i] >= 0) take = dp[i-1][j-nums[i]];

                dp[i][j] = take + not_take;
            }
        }

        return dp[n-1][neededSum];
    }
};