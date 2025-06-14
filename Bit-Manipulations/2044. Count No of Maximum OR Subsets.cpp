class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // first we will compute the maxXOR and then try all
        /* which has xor to this or not */

        int maxOR = 0, ans = 0, n = nums.size();

        for(auto num : nums) maxOR |= num;

        // for(int i=0;i<nums.size();i++){
        //     subsets(nums, maxOR, nums[i], i, ans);
        // }
        //return ans;

        // using the power set approach
            // we get 2pown subsets
        for(int mask=0;mask< (1<<n);mask++){
            int curOR = 0;
            for(int i=0;i<nums.size();i++){
                if(mask & (1<<i)) // checking that bit on or not
                {
                    curOR |= nums[i];
                }
            }
            if(curOR == maxOR) ans++;

        }
        return ans;
    }

    void subsets(vector<int> &nums, int &maxOR, int lcl, int i, int &ans){
        if(maxOR == lcl) ans++;
        if(i >= nums.size()) return;

        for(int k = i+1;k<nums.size();k++){
            subsets(nums, maxOR, lcl|nums[k], k, ans);
        }
    }
};