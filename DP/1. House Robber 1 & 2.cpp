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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;

        for(int i=0;i<n;i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if( i!= n-1) temp2.push_back(nums[i]);
        }

        return max(tabular(temp1), tabular(temp2));
    }

// tabular converted to SO O(1)
int tabular(vector<int> &nums)
{

    int n = nums.size();
    //vector<int> dp(n,0);

    //dp[0] = nums[0];

    int prev1 = 0, prev2 = 0;

    prev1 = nums[0];

    for(int i=1;i<n;i++)
    {
        int take = nums[i];
        if(i-1 > 0)
        {
            take += prev2;
        }

        int not_take = prev1;

        int cur = max(take, not_take);
        prev2 = prev1;
        prev1 = cur;


    }

return prev1;


}
// Memoized approach
    int help(vector<int> nums, int l, int r, int i)
    {
        if(i <= l) return nums[i];

        int take = nums[i];
        if(i-2 >= l)
            take += help(nums, l, r, i-2);
        int not_take = help(nums, l , r, i-1);

        return max(take, not_take);
    }
};