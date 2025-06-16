class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Basically the longest subarray should have all the
        /*
        elements should be the same maxi element
            - Find ma
            - Find max subarry of all Maxi's
            */
        int maxi = nums[0];
        for(auto num : nums) maxi = max(maxi, num);
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int lcl_count = 0;
            if(nums[i] == maxi){
                while(i<nums.size()-1 && nums[i] == nums[i+1]){
                    lcl_count++;
                    i++;
                }
            }
            ans = max(lcl_count+1, ans);
        }
        return ans;
    }
};