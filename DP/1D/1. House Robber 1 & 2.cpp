/*
Approach

House Robber 1
    should not rob the consecutive houses ( only alternate )
    try all possible ways ( overlapping sub problem )

    memoised - take , not take and max(take, not take)

    tabular - bottom up 
    dp[0] = arr[0]

    dp[1] = max ( arr[1] + dp[i-2], dp[i-1]) // in this case we can get the max one possible

    SO O(1)

    only need the prev1 and prev2 elements to get cur

House Robber 2
    circular houses so first and last are adjacent
        - try arr[0 to n] and arr[1 to n-1] so that both of these wont be at one place
        and get max(these two)
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